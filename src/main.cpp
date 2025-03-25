#include <iostream>
#include <iomanip>
#include "antlr4-runtime.h"
#include "AssemblyLexer.h"
#include "AssemblyParser.h"
#include "CustomAssemblyVisitor.h"
#include "ExecutableGenerator.h"
#include "LabelVisitor.h"


void saveBinary(const std::string& filename, const std::vector<uint8_t>& data) {
    std::ofstream file{ filename, std::ios::binary };
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    file.close();
}


void printMachineCode(const std::vector<std::vector<uint8_t>>& machineCode,
    const std::vector<std::pair<int, std::string>>& offsetToAsm) {
     uint32_t offset = 0;

    std::cout << "Generated Machine Code:\n";

    for (std::size_t i = 0; i < machineCode.size(); ++i) {
        // Вывод адреса в hex
        std::cout << std::right << std::dec << std::setw(8) << std::setfill('0') << offset << "  ";

        // Вывод байтов инструкции
        auto instruction = machineCode[i];
        std::ostringstream byteStream;
        for (uint8_t byte : instruction) {
            byteStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
        }

        // Вывод байтов с фиксированной шириной
        std::string byteStr = byteStream.str();
        byteStr.pop_back(); // Удаляем последний пробел
        std::cout << std::left << std::setw(20) << std::setfill(' ')<< byteStream.str();

        auto asmInstruction = offsetToAsm[i].second;
        std::cout << asmInstruction << "\n";

        offset += instruction.size();
    }
}


int main() {
    std::string input =
    "start:\n"
    "   add eax, 4\n"
    "   sub eax, 2\n"
    "   jmp end\n"
    "middle:\n"
    "   add eax, 1\n"
    "   add eax, 1\n"
    "   cmp eax, 20\n"
    "   jz start\n"
    "end:\n";

    antlr4::ANTLRInputStream inputStream{ input };
    AssemblyLexer lexer{ &inputStream };

    antlr4::CommonTokenStream tokens{ &lexer };
    AssemblyParser parser{ &tokens };

    AssemblyParser::ProgramContext *tree = parser.program();

    LabelVisitor labelVisitor;
    labelVisitor.visitProgram(tree);

    std::cout << "\nLabel Table Info: ----------------------------------------\n";
    for (const auto& [label, offset] : labelVisitor.getLabelTable()) {
        std::cout << "Label \"" << label << "\" at byte offset: " << offset << "\n";
    }
    std::cout << "----------------------------------------------------------\n\n";

    CustomAssemblyVisitor visitor;
    visitor.setLabelTable(labelVisitor.getLabelTable());
    visitor.visit(tree);

    printMachineCode(visitor.getMachineCode(), visitor.getOffsetToAsm());

    // const auto& code = visitor.getMachineCode();
    // ExecutableGenerator gen{ code };
    // auto executable = gen.generateExecutable();

    // saveBinary("executable", executable);

    return 0;
}