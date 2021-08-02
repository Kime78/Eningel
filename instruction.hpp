#pragma once

#include <cstdint>
#include <array>
#include <string>
#include <functional>

struct Instruction
{
    bool decoded;
    std::array<uint8_t, 3> bytes;
    std::function<int(std::array<uint8_t, 3>)> execute;
    std::function<std::string(std::array<uint8_t, 3>)> to_string;

    Instruction();
    Instruction(std::array<uint8_t, 3>);
    ~Instruction() = default;
};