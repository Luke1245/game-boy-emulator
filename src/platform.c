#include "../include/platform.h"

#include <SDL3/SDL.h>

#include "../include/config.h"

bool initialise_sdl(sdl_t* sdl, config_t config) {
    if (!SDL_SetAppMetadata("Gameboy Emulator", NULL, NULL)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Failure setting SDL metadata %s\n", SDL_GetError());
        return false;
    }

    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Failure initialising SDL subsytems %s\n", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer("Gameboy Emulator",
                                     config.window_width * config.scale_factor,
                                     config.window_height * config.scale_factor,
                                     0, &(sdl->window), &(sdl->renderer))) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Failure creating SDL window and renderer %s\n",
                     SDL_GetError());
        return false;
    }

    return true;
}

void clear_screen(const sdl_t* sdl) {
    SDL_SetRenderDrawColor(sdl->renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(sdl->renderer);
}

void update_screen(const sdl_t* sdl) { SDL_RenderPresent(sdl->renderer); }

void exit_cleanup(sdl_t* sdl) {
    // Renderer must be destroyed before window
    SDL_DestroyRenderer(sdl->renderer);
    SDL_DestroyWindow(sdl->window);
    SDL_Quit();
}
