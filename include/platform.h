#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL3/SDL.h>

#include "config.h"

typedef struct sdl {
    SDL_Window* window;
    SDL_Renderer* renderer;
} sdl_t;

bool initialise_sdl(sdl_t* sdl, config_t config);
void exit_cleanup(sdl_t* sdl);
void clear_screen(const sdl_t* sdl);
void update_screen(const sdl_t* sdl);

#endif
