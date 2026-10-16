#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint32_t window_width;
    uint32_t window_height;
    uint32_t scale_factor;
} config_t;

bool set_config(config_t* config, char** rom_name, int argc, char* argv[]);

#endif
