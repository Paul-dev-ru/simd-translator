#ifndef LABEL_VISITOR_H
#define LABEL_VISITOR_H

#include "AssemblyBaseVisitor.h"

class LabelVisitor : public AssemblyBaseVisitor {
public:
    antlrcpp::Any visitProgram(AssemblyParser::ProgramContext* context) override;
    antlrcpp::Any visitStatement(AssemblyParser::StatementContext* context) override;
    antlrcpp::Any visitLabelDeclaration(AssemblyParser::LabelDeclarationContext* context) override;
    const std::unordered_map<std::string, int>& getLabelTable() const;

private:
    std::unordered_map<std::string, int> labelTable;
    int offset = 0; // Смещение интсрукции в байтах
};


#endif  // LABEL_VISITOR_H