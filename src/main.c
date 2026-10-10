#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/config.h"
#include "../include/cpu.h"
#include "../include/platform.h"

int main(void) {
    gb_t gameboy = {0};
    config_t config = {0};
    sdl_t sdl = {0};

    set_config(&config);

    if (!initialise_sdl(&sdl, config)) {
        return EXIT_FAILURE;
    }

    if (!initialise_gameboy(&gameboy)) {
        return EXIT_FAILURE;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_Delay(16);
        clear_screen(&sdl);
        update_screen(&sdl);
    }

    exit_cleanup(&sdl);

    return EXIT_SUCCESS;
}
