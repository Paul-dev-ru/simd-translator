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

    switch (operation) {
        case Operation::Add:
            return addModrm.at(register_);
        case Operation::Sub:
            return subModrm.at(register_);
        default:
            throw std::invalid_argument("Unknown opcode");
    }
}


uint8_t CustomAssemblyVisitor::getOperationCodeByte(Operation operation) {
    const std::map<Operation, uint8_t> operationCode = {
        { Operation::Add, 0x83 },
        { Operation::Sub, 0x83 }
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
    machineCode.insert(machineCode.end(), command.begin(), command.end());

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
    machineCode.insert(machineCode.end(), command.begin(), command.end());

    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitCmpStatement(AssemblyParser::CmpStatementContext* context) {
    std::string register_ = context->register_()->getText();
    std::string operand = context->operand()->getText();
    std::cout << "Parsed CMP Operation: "
              << "Register: " << register_
              << ", Operand: " << operand
              << "\n";
    return antlrcpp::Any{};
}


antlrcpp::Any CustomAssemblyVisitor::visitJzStatement(AssemblyParser::JzStatementContext* context) {
    std::string label = context->label()->getText();
    std::cout << "Parsed JZ Operation: "
              << "Label: " << label
              << "\n";
    return antlrcpp::Any{};
}