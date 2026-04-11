#ifndef DISPLAYWIN_H
#define DISPLAYWIN_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
} Window;

int Window_Init(Window* win, const char* title, int width, int height);
int Window_CreateRenderer(Window* win);
void Window_Destroy(Window* win);

#endif
