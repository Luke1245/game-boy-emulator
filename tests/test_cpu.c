#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/cpu.h"

int main(void) {
    gb_t gameboy;
    initialise_gameboy(&gameboy);

    // TODO: Improve tests to cover all scenarios

    // Combined registers
    assert(set_combined_register(DE, &gameboy, 0xFFFF));
    assert(get_combined_register(DE, &gameboy) == 0xFFFF);

    // Flag setting
    set_flag_register(FLAG_CARRY, &gameboy);
    assert(gameboy.registers.f == FLAG_CARRY);
    set_flag_register(FLAG_ZERO, &gameboy);
    assert(gameboy.registers.f == (FLAG_CARRY | FLAG_ZERO));

    clear_flag_register(FLAG_CARRY | FLAG_ZERO, &gameboy);
    assert(gameboy.registers.f == 0);

    return 0;
}
