#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/cpu.h"

int main(void) {
    gb_t gameboy;
    // Use Blargg's CPU instruction test ROM
    bool success = initialise_gameboy(&gameboy, "cpu_instrs.gb");
    assert(success);
    (void)success;

    // TODO: Tests for loading ROM
    // Boot ROM load
    const uint8_t test_boot_rom_bytes[] = {0x31, 0xfe, 0xff, 0xaf,
                                           0x21, 0xff, 0x9f};
    for (size_t i = 0; i < sizeof test_boot_rom_bytes; i++) {
        // Check that the first six bytes of memory are the same as the first
        // six bytes of the boot ROM
        assert(test_boot_rom_bytes[i] == gameboy.memory[i]);
    }

    const uint8_t test_test_rom_bytes[] = {0x00, 0xc3, 0x37, 0x06,
                                           0xce, 0xed, 0x66};
    for (size_t i = 0; i < sizeof test_test_rom_bytes; i++) {
        // Check that six bytes (not first, as first bytes of test ROM are not
        // helpful) of the memory are same as the Blargg test ROM
        assert(test_test_rom_bytes[i] == gameboy.memory[i + 0x200]);
    }

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
