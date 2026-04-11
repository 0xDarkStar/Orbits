#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "simBody.h"

void drawFilledCircle(SDL_Renderer* renderer, signed centerX, signed centerY, unsigned radius) {
    int r = (int)radius;  // Convert to signed for loop calculations
    for (int y = -r; y <= r; y++) {
        int width = (int)sqrt((double)(r*r - y*y));
        SDL_RenderDrawLine(renderer,
            centerX-width, centerY+y,
            centerX+width, centerY+y);
    }
}

void renderBodies(SDL_Renderer* renderer, Body* bodies, unsigned bodyCount, unsigned viewZ) {
    for (unsigned int i = 0; i < bodyCount; i++) {
        double distance = viewZ - bodies[i].z;
        double scale = 1000.0 / (1000.0 + distance*3);
        unsigned screenRad = (unsigned)(bodies[i].radius * scale);
        SDL_SetRenderDrawColor(renderer,
            bodies[i].r,
            bodies[i].g,
            bodies[i].b,
            255);
        drawFilledCircle(renderer,
            (signed)bodies[i].x,
            (signed)bodies[i].y,
            screenRad);
    }
}

void Body_Init(Body* body, double x, double y, double z, double vx, double vy, double vz, unsigned radius, double mass, unsigned r, unsigned g, unsigned b) {
    body->x = x;
    body->y = y;
    body->z = z;
    body->vx = vx;
    body->vy = vy;
    body->vz = vz;
    body->radius = radius;
    body->mass = mass;
    body->r = r;
    body->g = g;
    body->b = b;
    body->ax = 0.0;
    body->ay = 0.0;
    body->az = 0.0;
    body->chosen = false;
}

void Body_Update(Body* body, double deltaTime) {
    body->x += body->vx * deltaTime;
    body->y += body->vy * deltaTime;
    body->z += body->vz * deltaTime;
}
