#ifndef DEBUGFPS_H
#define DEBUGFPS_H

#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct {
    int frameCount;
    double timeAccumulator;
    int currFPS;
} FPSCounter;

void FPSCounter_Init(FPSCounter* fps);
void FPSCounter_Update(FPSCounter* fps, double deltaTime);
void FPSCounter_Draw(FPSCounter* fps, SDL_Renderer* renderer);

#endif
