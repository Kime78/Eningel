#include "decoder.hpp"
#include "instruction.hpp"
#include <iostream>
#include <memory>


int main()
{
    Decoder uwu;
    std::array<Instruction, 0xFFFF> LUT;
    Memory mem;
    mem.load_rom("./roms/HelloWorld.nes");
    mem.pc = mem.read(0xfffd) << 8 | mem.read(0xfffc);
    while (1)
    {
        std::array<uint8_t, 3> instr;
        instr[0] = mem.read(mem.pc);
        instr[1] = mem.read(mem.pc + 1);
        instr[2] = mem.read(mem.pc + 2);
        if(LUT[mem.pc].decoded)
        {
            LUT[mem.pc].execute(instr);
        }
        else
        {
            LUT[mem.pc].execute = uwu.decode(instr);
            //LUT[0].to_string = uwu.disassemble(instr);
            LUT[mem.pc].execute(instr);
        }
    }
    return 0;
}