#include "../include/mmu.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/cpu.h"

bool load_rom(gb_t* gameboy, char* rom_name) {
    FILE* file_pointer = fopen(rom_name, "rb");

    if (file_pointer == NULL) {
        printf("File %s not found\n", rom_name);
        return false;
    }

    fseek(file_pointer, 0L, SEEK_END);
    int rom_size = ftell(file_pointer);
    int gb_memory_size = sizeof(gameboy->memory) + 1;

    if (rom_size == 0 || rom_size > gb_memory_size) {
        printf("File %s is an invalid size (%i)\n", rom_name, rom_size);
        fclose(file_pointer);
        return false;
    }

    fseek(file_pointer, 0L, SEEK_SET);

    if (!fread(gameboy->memory, rom_size, 1, file_pointer)) {
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
    memcpy(output_block, gameboy->memory + location, size);
    memcpy(gameboy->memory + location, input_block, size);

    return true;
}
