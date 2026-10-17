#ifndef MMU_H
#define MMU_H

#include "../include/cpu.h"

bool load_rom(gb_t* gameboy, char* rom_name);
bool swap_memory(uint8_t input_block[], uint8_t output_block[], int size,
                 int location, gb_t* gameboy);
#endif
