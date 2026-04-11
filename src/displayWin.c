#include <SDL2/SDL.h>
#include <stdio.h>
#include "displayWin.h"

int Window_Init(Window* win, const char* title, int width, int height) {
    win->width = width;
    win->height = height;
    
    win->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!win->window) {
        printf("Window creation failed %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

int Window_CreateRenderer(Window* win) {
    // Use software rendering to avoid GPU driver issues with unsupported architectures
    win->renderer = SDL_CreateRenderer(
        win->window, -1, SDL_RENDERER_SOFTWARE
    );

    if (!win->renderer) {
        // Fallback to hardware acceleration if software fails
        win->renderer = SDL_CreateRenderer(
            win->window, -1, SDL_RENDERER_ACCELERATED
        );
    }

    if (!win->renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

void Window_Destroy(Window* win) {
    if (win->renderer) SDL_DestroyRenderer(win->renderer);
    if (win->window) SDL_DestroyWindow(win->window);
}
