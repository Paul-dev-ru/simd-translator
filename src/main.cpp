#include <iostream>
#include "antlr4-runtime.h"
#include "AssemblyLexer.h"
#include "AssemblyParser.h"
#include "CustomAssemblyVisitor.h"
#include "ExecutableGenerator.h"


void saveBinary(const std::string& filename, const std::vector<uint8_t>& data) {
    std::ofstream file{ filename, std::ios::binary };
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    file.close();
}


int main() {
    std::stringstream ss;
    ss << "add eax, 81\n";
    ss << "sub eax, 11\n";
    std::string input = ss.str();

    antlr4::ANTLRInputStream inputStream{ input };
    AssemblyLexer lexer{ &inputStream };

    antlr4::CommonTokenStream tokens{ &lexer };
    AssemblyParser parser{ &tokens };

    AssemblyParser::ProgramContext *tree = parser.program();

    CustomAssemblyVisitor visitor;
    visitor.visit(tree);

    const auto& code = visitor.getMachineCode();
    ExecutableGenerator gen{ code };
    auto executable = gen.generateExecutable();

    saveBinary("executable", executable);

    return 0;
}