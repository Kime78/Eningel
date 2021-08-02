#include "decoder.hpp"
#include <iostream>
auto add = [](std::array<uint8_t, 3>)
{
    return 3;
};

auto dissasemble_undefined_instruction = [](std::array<uint8_t, 3> a) -> std::string
{
    std::cout << std::hex << "Unimplemented instruction: " + (int)a[0];
    return NULL;
};

auto decode_undefined_instruction = [](std::array<uint8_t, 3> a) -> int
{
    std::cout << std::hex << "Unimplemented instruction: " + (int)a[0];
    return 0;
};
std::function<int(std::array<uint8_t, 3>)> Decoder::decode(std::array<uint8_t, 3> bytes)
{
    switch (bytes[0])
    {
    default:
        //std::cout << std::hex << "Unimplemented instruction: " + (int)opcode;
        return decode_undefined_instruction;
    }
}

std::function<std::string(std::array<uint8_t, 3>)> disassemble(std::array<uint8_t, 3> bytes)
{
    switch (bytes[0])
    {
    default:
        return dissasemble_undefined_instruction;
    }
}
