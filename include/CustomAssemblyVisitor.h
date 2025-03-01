#ifndef CUSTOM_ASSEMBLY_VISITOR_H
#define CUSTOM_ASSEMBLY_VISITOR_H

#include "AssemblyBaseVisitor.h"

class CustomAssemblyVisitor : public AssemblyBaseVisitor {
public:
    const std::vector<uint8_t>& getMachineCode() const {
        return machineCode;
    }

    enum class Operation {
        Add,
        Sub,
    };

    enum class Register {
        Eax,
        Ecx,
        Edx,
        Ebx,
    };

    antlrcpp::Any visitAddStatement(AssemblyParser::AddStatementContext* context) override;
    antlrcpp::Any visitSubStatement(AssemblyParser::SubStatementContext* context) override;
    antlrcpp::Any visitCmpStatement(AssemblyParser::CmpStatementContext* context) override;
    antlrcpp::Any visitJzStatement(AssemblyParser::JzStatementContext* context) override;

private:
    uint8_t getModrmByte(Operation operation, Register register_);
    uint8_t getOperationCodeByte(Operation operation);
    Register stringToRegister(const std::string& str);
    
    std::vector<uint8_t> machineCode;
};

#endif  // CUSTOM_ASSEMBLY_VISITOR_H