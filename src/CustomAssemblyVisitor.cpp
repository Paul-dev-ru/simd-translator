#include "CustomAssemblyVisitor.h"


uint8_t CustomAssemblyVisitor::getModrmByte(Operation operation, Register register_) {
    static const std::map<Register, uint8_t> addModrm = {
        { Register::Eax, 0xC0 },
        { Register::Ecx, 0xC1 },
        { Register::Edx, 0xC2 },
        { Register::Ebx, 0xC3 }
    }; 

    static const std::map<Register, uint8_t> subModrm = {
        { Register::Eax, 0xE8 },
        { Register::Ecx, 0xE9 },
        { Register::Edx, 0xEA },
        { Register::Ebx, 0xEB }
    };

    static const std::map<Register, uint8_t> cmpModrm = {
        { Register::Eax, 0xF8 },
        { Register::Ecx, 0xF9 },
        { Register::Edx, 0xFA },
        { Register::Ebx, 0xFB }
    };

    switch (operation) {
        case Operation::Add:
            return addModrm.at(register_);
        case Operation::Sub:
            return subModrm.at(register_);
        case Operation::Cmp:
            return cmpModrm.at(register_);
        default:
            throw std::invalid_argument("Unknown opcode");
    }
}


uint8_t CustomAssemblyVisitor::getOperationCodeByte(Operation operation) {
    const std::map<Operation, uint8_t> operationCode = {
        { Operation::Add, 0x83 },
        { Operation::Sub, 0x83 },
        { Operation::Cmp, 0x83 }
    };

    return operationCode.at(operation);
}


using Register = CustomAssemblyVisitor::Register;

Register CustomAssemblyVisitor::stringToRegister(const std::string& str) {
    static const std::map<std::string, Register> mapping = {
        { "eax", Register::Eax },
        { "ecx", Register::Ecx },
        { "edx", Register::Edx },
        { "ebx", Register::Ebx },
    };

    return mapping.at(str);
}


antlrcpp::Any CustomAssemblyVisitor::visitAddStatement(AssemblyParser::AddStatementContext* context) {
    uint8_t opcodeByte = getOperationCodeByte(Operation::Add);
    
    std::string registerStr = context->register_()->getText();
    Register register_ = stringToRegister(registerStr);

    uint8_t modrmByte = getModrmByte(Operation::Add, register_);

    std::string operandStr = context->operand()->getText();
    uint8_t operandByte = static_cast<uint8_t>(std::stoi(operandStr));

    std::array<uint8_t, 3> command = { opcodeByte, modrmByte, operandByte };
    machineCode.emplace_back(command.begin(), command.end());

    curOffsetToAsmInstruction.emplace_back(currentOffset, context->getText());
    currentOffset += 3;

    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitSubStatement(AssemblyParser::SubStatementContext* context) {
    uint8_t opcodeByte = getOperationCodeByte(Operation::Sub);
    
    std::string registerStr = context->register_()->getText();
    Register register_ = stringToRegister(registerStr);

    uint8_t modrmByte = getModrmByte(Operation::Sub, register_);

    std::string operandStr = context->operand()->getText();
    uint8_t operandByte = static_cast<uint8_t>(std::stoi(operandStr));

    std::array<uint8_t, 3> command = { opcodeByte, modrmByte, operandByte };
    machineCode.emplace_back(command.begin(), command.end());

    curOffsetToAsmInstruction.emplace_back(currentOffset, context->getText());
    currentOffset += 3;

    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitCmpStatement(AssemblyParser::CmpStatementContext* context) {
    uint8_t opcodeByte = getOperationCodeByte(Operation::Cmp);
    
    std::string registerStr = context->register_()->getText();
    Register register_ = stringToRegister(registerStr);

    uint8_t modrmByte = getModrmByte(Operation::Cmp, register_);

    std::string operandStr = context->operand()->getText();
    uint8_t operandByte = static_cast<uint8_t>(std::stoi(operandStr));

    std::array<uint8_t, 3> command = { opcodeByte, modrmByte, operandByte };
    machineCode.emplace_back(command.begin(), command.end());

    curOffsetToAsmInstruction.emplace_back(currentOffset, context->getText());
    currentOffset += 3;

    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitJzStatement(AssemblyParser::JzStatementContext* context) {
    std::string label = context->label()->getText();

    if (labelTable.find(label) == labelTable.end()) {
        throw std::runtime_error("Undefined label: " + label);
    }

    int labelOffset = labelTable[label];
    int relativeOffset = labelOffset - (currentOffset + 2);

    // Код команды JZ: 0x74 + 1-байтовый offset
    uint8_t opcodeByte = 0x74;
    uint8_t offsetByte = static_cast<uint8_t>(relativeOffset & 0xFF);

    std::array<uint8_t, 2> command = { opcodeByte, offsetByte };
    machineCode.emplace_back(command.begin(), command.end());

    curOffsetToAsmInstruction.emplace_back(currentOffset, context->getText());
    currentOffset += 2;

    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitJmpStatement(AssemblyParser::JmpStatementContext* context) {
    std::string label = context->label()->getText();

    int labelOffset = labelTable[label];
    int relativeOffset = labelOffset - (currentOffset + 5);

    // Код команды JMP: E9 + 4-байтовый offset
    uint8_t opcodeByte = 0xE9;
    std::array<uint8_t, 5> command = {
        opcodeByte,
        static_cast<uint8_t>(relativeOffset & 0xFF),
        static_cast<uint8_t>((relativeOffset >> 8) & 0xFF),
        static_cast<uint8_t>((relativeOffset >> 16) & 0xFF),
        static_cast<uint8_t>((relativeOffset >> 24) & 0xFF)
    };

    machineCode.emplace_back(command.begin(), command.end());

    curOffsetToAsmInstruction.emplace_back(currentOffset, context->getText());
    currentOffset += 5;

    return antlrcpp::Any{};
}