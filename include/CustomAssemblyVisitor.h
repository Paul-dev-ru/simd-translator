#ifndef CUSTOM_ASSEMBLY_VISITOR_H
#define CUSTOM_ASSEMBLY_VISITOR_H

#include "AssemblyBaseVisitor.h"

class CustomAssemblyVisitor : public AssemblyBaseVisitor {
public:
    void setLabelTable(const std::unordered_map<std::string, int>& table) {
        labelTable = table;
    }

    const std::vector<std::vector<uint8_t>>& getMachineCode() const {
        return machineCode;
    }

    const std::vector<std::pair<int, std::string>>& getOffsetToAsm() const {
        return curOffsetToAsmInstruction;
    }

    enum class Operation {
        Add,
        Sub,
        Cmp
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
    antlrcpp::Any visitJmpStatement(AssemblyParser::JmpStatementContext* context) override;

private:
    uint8_t getModrmByte(Operation operation, Register register_);
    uint8_t getOperationCodeByte(Operation operation);
    Register stringToRegister(const std::string& str);
    
    std::vector<std::vector<uint8_t>> machineCode;
    std::vector<std::pair<int, std::string>> curOffsetToAsmInstruction; 

    std::unordered_map<std::string, int> labelTable;
    int currentOffset = 0;
};

#endif  // CUSTOM_ASSEMBLY_VISITOR_H