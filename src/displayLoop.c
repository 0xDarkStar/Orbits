#include <SDL2/SDL.h>
#include <stdbool.h>
#include "displayWin.h"
#include "displayLoop.h"
#include "physics.h"
#include "simData.h"
#include "simBody.h"
#include "debugFPS.h"

int Loop_Start(Simulation simData) {
    SDL_Init(SDL_INIT_VIDEO);
    Window mainWin;
    Window_Init(&mainWin, "Orbits", 800, 600);
    Window_CreateRenderer(&mainWin);

    FPSCounter fps;
    FPSCounter_Init(&fps);

    // Get first time for deltaTime
    Uint64 prevTime = SDL_GetPerformanceCounter();

    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        // Calculate deltaTime
        Uint64 currTime = SDL_GetPerformanceCounter();
        double deltaTime = (double)(currTime-prevTime) / SDL_GetPerformanceFrequency();
        prevTime = currTime;
        FPSCounter_Update(&fps, deltaTime);
    
        // Handle Inputs
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }
    
        if (!simData.is_paused) {
            // Update everything
            Physics_calcAll(simData.bodies, simData.body_count, deltaTime);
            for (int i = 0; i < simData.body_count; i++) {
                Body_Update(&simData.bodies[i], deltaTime);
            }
            Simulation_SortBodies(&simData);
        }

        // Render
        SDL_SetRenderDrawColor(mainWin.renderer, 0, 0, 0, 255);
        SDL_RenderClear(mainWin.renderer);
        renderBodies(mainWin.renderer, simData.bodies, simData.body_count, simData.viewZ);
        FPSCounter_Draw(&fps, mainWin.renderer);
        SDL_RenderPresent(mainWin.renderer);
        SDL_Delay(16);
    }

    Window_Destroy(&mainWin);
    SDL_Quit();
    return 0;
}
