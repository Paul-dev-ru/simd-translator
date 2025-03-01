#include "ExecutableGenerator.h"


const std::vector<uint8_t>& ExecutableGenerator::generateExecutable() {
    executable.clear();

    generateElfHeader();

    generateProgramHeader();

    executable.resize(0x54, 0x00); // Выравниваем до entry point
    executable.insert(executable.end(), code.begin(), code.end());

    std::array<uint8_t, 3> toAscii = {
        0x83, 0xC0, 0x30       // add eax, '0' (0x30 в ASCII — это '0')
    };
    executable.insert(executable.end(), toAscii.begin(), toAscii.end());

    // sub esp, 4  (выделяем 4 байта на стеке)
    std::array<uint8_t, 3> allocStack = { 0x83, 0xEC, 0x04 };
    executable.insert(executable.end(), allocStack.begin(), allocStack.end());

    // mov dword ptr [esp], eax (сохраняем eax в стек)
    std::array<uint8_t, 3> saveEaxStack = { 0x89, 0x04, 0x24 };
    executable.insert(executable.end(), saveEaxStack.begin(), saveEaxStack.end());

    // mov byte ptr [esp+3], 0x0A (записываем '\n' в конец буфера)
    std::array<uint8_t, 5> storeNewlineStack = { 0xC6, 0x44, 0x24, 0x03, 0x0A };
    executable.insert(executable.end(), storeNewlineStack.begin(), storeNewlineStack.end());

    // mov eax, 4 (sys_write)
    std::array<uint8_t, 5> sysWrite = { 0xB8, 0x04, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), sysWrite.begin(), sysWrite.end());

    // mov ebx, 1 (stdout)
    std::array<uint8_t, 5> stdoutFd = { 0xBB, 0x01, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), stdoutFd.begin(), stdoutFd.end());

    // mov ecx, esp (буфер на стеке)
    std::array<uint8_t, 2> bufferAddrStack = { 0x89, 0xE1 };
    executable.insert(executable.end(), bufferAddrStack.begin(), bufferAddrStack.end());

    // mov edx, 4 (длина вывода)
    std::array<uint8_t, 5> bufferSize = { 0xBA, 0x04, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), bufferSize.begin(), bufferSize.end());

    // int 0x80 (вызов sys_write)
    std::array<uint8_t, 2> syscallWrite = { 0xCD, 0x80 };
    executable.insert(executable.end(), syscallWrite.begin(), syscallWrite.end());

    // mov eax, 1 (sys_exit)
    std::array<uint8_t, 5> sysExit = { 0xB8, 0x01, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), sysExit.begin(), sysExit.end());

    // mov ebx, 0 (exit code)
    std::array<uint8_t, 5> exitCode = { 0xBB, 0x00, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), exitCode.begin(), exitCode.end());

    // int 0x80 (вызов system exit)
    std::array<uint8_t, 2> systemExit = { 0xCD, 0x80 };
    executable.insert(executable.end(), systemExit.begin(), systemExit.end());

    // Добавляем буфер (4 байта, инициализируем нулями)
    std::array<uint8_t, 4> buffer = { 0x00, 0x00, 0x00, 0x00 };
    executable.insert(executable.end(), buffer.begin(), buffer.end());

    return executable;
}


void ExecutableGenerator::generateElfHeader() {
    std::vector<uint8_t> elfHeader = {
        0x7F, 'E', 'L', 'F',   // ELF magic
        0x01, 0x01, 0x01, 0x00, // 32-bit, little-endian, version 1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Unused
        0x02, 0x00, 0x03, 0x00, // Type = EXEC (2), Machine = x86 (3)
        0x01, 0x00, 0x00, 0x00, // ELF version 1
        0x54, 0x80, 0x04, 0x08, // Entry point (offset 0x80 в бинарнике)
        0x34, 0x00, 0x00, 0x00, // Program header offset
        0x00, 0x00, 0x00, 0x00, // Section header offset (не используем)
        0x00, 0x00, 0x00, 0x00, // Flags
        0x34, 0x00, 0x20, 0x00, // ELF header size (0x34), Program header size (0x20)
        0x01, 0x00, 0x00, 0x00, // 1 программный заголовок
        0x00, 0x00, 0x00, 0x00, // No section headers
    };

    executable.insert(executable.end(), elfHeader.begin(), elfHeader.end());
}


void ExecutableGenerator::generateProgramHeader() {
    uint32_t segmentSize = 0x54 + code.size();
    std::vector<uint8_t> programHeader = {
        0x01, 0x00, 0x00, 0x00, // PT_LOAD (1)
        0x54, 0x00, 0x00, 0x00, // Offset в файле
        0x54, 0x80, 0x04, 0x08, // Виртуальный адрес (0x80)
        0x80, 0x00, 0x00, 0x00, // Физический адрес (не важен)
        static_cast<uint8_t>(segmentSize), 0x00, 0x00, 0x00, // Размер в файле
        static_cast<uint8_t>(segmentSize), 0x00, 0x00, 0x00, // Размер в памяти
        0x07, 0x00, 0x00, 0x00  // Флаги: RWX (чтение, запись, исполнение)
    };

    executable.insert(executable.end(), programHeader.begin(), programHeader.end());
}