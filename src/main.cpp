#include <iostream>
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


int main() {
    std::string input =
    "start:\n"
    "   add eax, 4\n"
    "   sub eax, 2\n"
    "   cmp eax, 1\n"
    "   jz end\n"
    "middle:\n"
    "   add eax, 1\n"
    "   sub eax, 3\n"
    "   cmp eax, 12\n"
    "   jz middle\n"
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
    visitor.visit(tree);


    const auto& code = visitor.getMachineCode();
    ExecutableGenerator gen{ code };
    auto executable = gen.generateExecutable();

    saveBinary("executable", executable);

    return 0;
}