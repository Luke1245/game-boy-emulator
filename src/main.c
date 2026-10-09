#include <stdio.h>
#include <stdlib.h>

#include "../include/cpu.h"

int main(void) {
    printf("Game Boy Emulator\n");
    gb_t gameboy;

    if (!initialise_gameboy(&gameboy)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
