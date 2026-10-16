#include "../include/config.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool set_config(config_t* config, char** rom_name, int argc, char* argv[]) {
    if (argc < 2 || argv[1][0] == '-') {
        fprintf(stderr, "Usage %s <rom_name> [-s scale_factor]\n", argv[0]);
        return false;
    }

    *config = (config_t){
        .window_width = 160,   // Original Gameboy Resolution
        .window_height = 144,  // Original Gameboy Resolution
        .scale_factor = 5,
    };

    *rom_name = argv[1];

    int opt;
    while ((opt = getopt(argc - 1, argv + 1, "s:")) != -1) {
        switch (opt) {
            case 's':
                // Convert string argument to uint32_t for scale_factor
                config->scale_factor = (uint32_t)strtol(optarg, NULL, 10);
                break;
        }
    }

    return true;
}
