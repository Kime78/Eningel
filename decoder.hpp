#pragma once
#include <cstdint>
#include <array>
#include <functional>
#include <string>
#include "memory.hpp"

class Decoder
{
    friend class Memory;

public:
    std::function<int(std::array<uint8_t, 3>)> decode(std::array<uint8_t, 3> bytes);
    std::function<std::string(std::array<uint8_t, 3>)> disassemble(std::array<uint8_t, 3> bytes);
};