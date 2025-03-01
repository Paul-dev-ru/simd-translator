#ifndef EXECUTABLE_GENERATOR_H
#define EXECUTABLE_GENERATOR_H

#include <vector>
#include <array>
#include <cstdint>

class ExecutableGenerator {
public:
    ExecutableGenerator(const std::vector<uint8_t>& code_)
        : code{ code_ } {}

    const std::vector<uint8_t>& generateExecutable();

private:
    void generateElfHeader();
    void generateProgramHeader();

    std::vector<uint8_t> code;
    std::vector<uint8_t> executable;
};

#endif  // EXECUTABLE_GENERATOR_H