#include "../include/config.h"

void set_config(config_t* config) {
    *config = (config_t){
        .window_width = 160,   // Original Gameboy Resolution
        .window_height = 144,  // Original Gameboy Resolution
        .scale_factor = 5,
    };
}
