#include <iterator>
#include "memory.hpp"
#include <string>
#include <fstream>

template <typename T>
std::vector<T> LoadBin(const std::string &path)
{
    std::basic_ifstream<T> file{path, std::ios::binary};
    return {std::istreambuf_iterator<T>{file}, {}};
}

void Memory::load_rom(const std::string &path)
{
    //rom = LoadBin<uint8_t>(path);
    rom.resize(0xFFFF);
    FILE *file = fopen(path.c_str(), "rb");
    int pos = 0;

    while (fread(&rom[pos], 1, 1, file))
    {
        //std::cout << std::hex << (int)Memory.rom[pos] << " ";
        pos++;
    }

}

void Memory::write(uint16_t addr, uint8_t val)
{
    switch (addr)
    {
    case 0x0000 ... 0x07FF:
    {
        ram[addr] = val;
        break;
    }

    case 0x0800 ... 0x0FFF:
    {
        ram[addr - 0x0800] = val;
        break;
    }

    case 0x1000 ... 0x17FF:
    {
        ram[addr - 0x1000] = val;
        break;
    }

    case 0x1800 ... 0x1FFF:
    {
        ram[addr - 0x1800] = val;
        break;
    }

    case 0x2000 ... 0x2007:
    {
        ppu_regs[addr - 0x2000] = val;
        break;
    }

    case 0x2008 ... 0x3FFF:
    {
        //ppu mirroring
        break;
    }

    case 0x4000 ... 0x4017:
    {
        apu_io_regs[addr - 0x4000] = val;
        break;
    }

    case 0x4018 ... 0x401F:
    {
        //not handled ;n;
        break;
    }

    case 0x4020 ... 0xFFFF:
    {
        //no writes to rom?
        /*
        Note: Most common boards and iNES mappers address ROM and Save/Work RAM in this format:

        $6000-$7FFF = Battery Backed Save or Work RAM
        $8000-$FFFF = Usual ROM, commonly with Mapper Registers (see MMC1 and UxROM for example)
    */
        break;
    }

    default:
        break;
    }
}

uint8_t Memory::read(uint16_t addr)
{
    switch (addr)
    {
    case 0x0000 ... 0x07FF:
    {
        return ram[addr];
        break;
    }

    case 0x0800 ... 0x0FFF:
    {
        return ram[addr - 0x0800];
        break;
    }

    case 0x1000 ... 0x17FF:
    {
        return ram[addr - 0x1000];
        break;
    }

    case 0x1800 ... 0x1FFF:
    {
        return ram[addr - 0x1800];
        break;
    }

    case 0x2000 ... 0x2007:
    {
        return ppu_regs[addr - 0x2000];
        break;
    }

    case 0x2008 ... 0x3FFF:
    {
        //ppu mirroring
        break;
    }

    case 0x4000 ... 0x4017:
    {
        return apu_io_regs[addr - 0x4000];
        break;
    }

    case 0x4018 ... 0x401F:
    {
        //not handled ;n;
        break;
    }

    case 0x4020 ... 0xFFFF:
    {
        return rom[addr - 0x4020];
        break;
    }

    default:
        break;
    }
}
