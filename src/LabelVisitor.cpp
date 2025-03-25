#include "LabelVisitor.h"


antlrcpp::Any LabelVisitor::visitProgram(AssemblyParser::ProgramContext* context) {
    for (auto statement : context->statement()) {
        visit(statement);
    }

    return antlrcpp::Any{};
}


antlrcpp::Any LabelVisitor::visitStatement(AssemblyParser::StatementContext* context) {
    if (context->labelDeclaration()) {
        visitLabelDeclaration(context->labelDeclaration());
    } else if (context->addStatement() || context->subStatement() || context->cmpStatement()) {
        offset += 3;  // Увеличиваем смещение на 3 байта для арифметических операций
    } else if (context->jzStatement()) {
        offset += 2;  // Увеличиваем смещение на 2 байта для команд перехода
    } else if (context->jmpStatement()) {
        offset += 5;
    }
    return antlrcpp::Any{};
}


antlrcpp::Any LabelVisitor::visitLabelDeclaration(AssemblyParser::LabelDeclarationContext* context) {
    std::string labelName = context->label()->getText();
    labelTable[labelName] = offset;
    return antlrcpp::Any{};
}


const std::unordered_map<std::string, int>& LabelVisitor::getLabelTable() const {
    return labelTable;
}