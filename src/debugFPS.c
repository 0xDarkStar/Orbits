#include <stdio.h>
#include <SDL2/SDL.h>
#include "debugFPS.h"

void FPSCounter_Init(FPSCounter* fps) {
    fps->frameCount = 0;
    fps->timeAccumulator = 0.0;
    fps->currFPS = 0;
}

void FPSCounter_Update(FPSCounter* fps, double deltaTime) {
    fps->frameCount++;
    fps->timeAccumulator += deltaTime;

    if (fps->timeAccumulator >= 1.0) {
        fps->currFPS = fps->frameCount;
        fps->frameCount = 0;
        fps->timeAccumulator -= 1.0;
    }
}

void FPSCounter_Draw(FPSCounter* fps, SDL_Renderer* renderer) {
    printf("\rFPS: %d", fps->currFPS);

    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_Rect fpsBar = {10,10, fps->currFPS, 10};
    SDL_RenderFillRect(renderer, &fpsBar);
}
