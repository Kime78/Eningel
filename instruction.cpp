#include "instruction.hpp"

Instruction::Instruction()
{
    decoded = 0;
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    execute = NULL;
    to_string = NULL;
}