#ifndef CPU_H
#define CPU_H

#include <stdint.h>

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
} gb_t;

bool initialise_gameboy(gb_t* gameboy);
void fetch_combined_registers(uint8_t registers[], combreg_t reg,
                              gb_t* gameboy);
uint16_t get_combined_register(combreg_t reg, gb_t* gameboy);
bool set_combined_register(combreg_t reg, gb_t* gameboy, uint16_t value);

#endif
