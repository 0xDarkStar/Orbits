#ifndef SIMBODY_H
#define SIMBODY_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct {
    double mass;
    double x, y, z;        // Position
    double vx, vy, vz;      // Velocity
    double ax, ay, az;      // Acceleration
    unsigned radius;
    unsigned r, g, b;   // Color
    bool chosen;        // Am I selected?
} Body;

void renderBodies(SDL_Renderer* renderer, Body* bodies, unsigned bodyCount, unsigned viewZ);
void Body_Init(Body* body, double x, double y, double z, double vx, double vy, double vz, unsigned radius, double mass, unsigned r, unsigned g, unsigned b);
void Body_Update(Body* body, double deltaTime);

#endif
