#include "../include/cpu.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

bool initialise_gameboy(gb_t* gameboy) {
    memset(gameboy, 0, sizeof *gameboy);
    return true;
}

void combine_registers(uint8_t* registers[], combreg_t reg, gb_t* gameboy) {
    // Gameboy treats two 8-bit registers as one 16-bit register for some
    // operations
    switch (reg) {
        case AF:
            registers[0] = &gameboy->registers.a;
            registers[1] = &gameboy->registers.f;
            break;
        case BC:
            registers[0] = &gameboy->registers.b;
            registers[1] = &gameboy->registers.c;
            break;
        case DE:
            registers[0] = &gameboy->registers.d;
            registers[1] = &gameboy->registers.e;
            break;
        case HL:
            registers[0] = &gameboy->registers.h;
            registers[1] = &gameboy->registers.l;
            break;
    }
}

uint16_t get_combined_register(combreg_t reg, gb_t* gameboy) {
    uint8_t* registers[] = {NULL, NULL};
    combine_registers(registers, reg, gameboy);

    // Combine two registers by shifting first registers 8-bits to high bit of
    // 16-bit int then ORing (combines) with the second registers 8-bits to put
    // them in the 16-bit low bits
    return (*registers[0] << 8) | *registers[1];
}

bool set_combined_register(combreg_t reg, gb_t* gameboy, uint16_t value) {
    uint8_t* registers[] = {NULL, NULL};
    combine_registers(registers, reg, gameboy);

    // Mask off lower 8 bits then shift right to convert to 8-bit int
    *registers[0] = (value & 0xFF00) >> 8;
    // Leading 0s not needed but matches form of above line. Mask off high 8
    // bits
    *registers[1] = (value & 0x00FF);

    return true;
}

void set_flag_register(uint8_t mask, gb_t* gameboy) {
    // Use OR to set the correct flag bits without overwriting other flags
    gameboy->registers.f |= mask;
    // Lower nibble is always zero
    gameboy->registers.f &= 0xF0;
}

void clear_flag_register(uint8_t mask, gb_t* gameboy) {
    // Negate mask to clear supplied flags
    gameboy->registers.f &= ~mask;
}
