#include "../include/mmu.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/cpu.h"

bool load_rom(gb_t* gameboy, char* rom_name) {
    FILE* file_pointer = fopen(rom_name, "rb");

    if (file_pointer == NULL) {
        printf("File not found\n");
        return false;
    }

    fseek(file_pointer, 0L, SEEK_END);
    long size = ftell(file_pointer);
    fseek(file_pointer, 0L, SEEK_SET);

    if (!fread(gameboy->memory, size, 1, file_pointer)) {
        printf("Unable to read ROM into memory\n");
        fclose(file_pointer);
        return false;
    }

    fclose(file_pointer);

    printf("ROM loaded\n");

    return true;
}

bool swap_memory(uint8_t input_block[], uint8_t output_block[], int size,
                 int location, gb_t* gameboy) {
    memcpy(output_block, gameboy->memory + location, (size * sizeof(uint8_t)));
    memcpy(gameboy->memory + location, input_block, size);

    return true;
}
