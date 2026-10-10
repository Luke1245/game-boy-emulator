#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef struct {
    uint32_t window_width;
    uint32_t window_height;
    uint32_t scale_factor;
} config_t;

void set_config(config_t* config);

#endif
