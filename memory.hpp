#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <filesystem>

class Memory
{
    uint8_t accumulator;
    uint8_t x, y;
    uint8_t stack;
    uint8_t status;

    std::array<uint8_t, 0x0800> ram;
    std::array<uint8_t, 0x0008> ppu_regs;
    std::array<uint8_t, 0x0018> apu_io_regs;
    std::vector<uint8_t> rom;

public:
    uint16_t pc;
    void load_rom(const std::string &path);
    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t val);
};