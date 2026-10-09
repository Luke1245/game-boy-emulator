#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/cpu.h"

int main(void) {
    gb_t gameboy;
    initialise_gameboy(&gameboy);

    assert(set_combined_register(AF, &gameboy, 0xFFFF));
    assert(get_combined_register(AF, &gameboy) == 0xFFFF);

    return 0;
}
