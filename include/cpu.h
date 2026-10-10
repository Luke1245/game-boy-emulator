#ifndef CPU_H
#define CPU_H

#include <stdbool.h>
#include <stdint.h>

// Flag register f, top nibble handles flags, bottom nibble always 0
// use these masks to set the correct bit in the register via bitwise OR
#define FLAG_ZERO (1 << 7)
#define FLAG_SUB (1 << 6)
#define FLAG_HALF (1 << 5)
#define FLAG_CARRY (1 << 4)

typedef enum { AF, BC, DE, HL } combreg_t;

typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t h;
    uint8_t l;
} registers_t;

typedef struct {
    registers_t registers;
    uint16_t pc;
    uint8_t memory[0xFFFF];
} gb_t;

bool initialise_gameboy(gb_t* gameboy);
void combine_registers(uint8_t* registers[], combreg_t reg, gb_t* gameboy);
uint16_t get_combined_register(combreg_t reg, gb_t* gameboy);
bool set_combined_register(combreg_t reg, gb_t* gameboy, uint16_t value);
void set_flag_register(uint8_t mask, gb_t* gameboy);
void clear_flag_register(uint8_t mask, gb_t* gameboy);

#endif
