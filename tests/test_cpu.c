#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/cpu.h"

int main(void) {
    gb_t gameboy;
    initialise_gameboy(&gameboy);

    // Tests for combined register functions
    // Set
    assert(set_combined_register(DE, &gameboy, 0xDFA2));
    // Get
    assert(get_combined_register(DE, &gameboy) == 0xDFA2);
    // Setting one register does not change another
    set_combined_register(HL, &gameboy, 0x7C38);
    assert(get_combined_register(DE, &gameboy) == 0xDFA2);

    // Tests for flag register functions
    // Set flag
    set_flag_register(FLAG_CARRY, &gameboy);
    assert(gameboy.registers.f == FLAG_CARRY);
    // Clear flag
    clear_flag_register(FLAG_CARRY, &gameboy);
    assert(gameboy.registers.f == 0);
    // Setting multiple flags
    set_flag_register(FLAG_CARRY | FLAG_HALF | FLAG_ZERO, &gameboy);
    assert(gameboy.registers.f == (FLAG_CARRY | FLAG_ZERO | FLAG_HALF));
    // Clearing multiple flags
    clear_flag_register(FLAG_CARRY | FLAG_HALF | FLAG_ZERO, &gameboy);
    assert(gameboy.registers.f == 0);
    // Setting flag does not change other flag
    set_flag_register(FLAG_CARRY, &gameboy);
    set_flag_register(FLAG_SUB, &gameboy);
    assert(gameboy.registers.f == (FLAG_CARRY | FLAG_SUB));
    // Clearing flag does not change other flag
    clear_flag_register(FLAG_SUB, &gameboy);
    assert(gameboy.registers.f == FLAG_CARRY);

    return 0;
}
