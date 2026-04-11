#ifndef SIMDATA_H
#define SIMDATA_H

#include "simBody.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    Body* bodies;
    unsigned body_count;
    signed viewX, viewY, viewZ;   // View Position
    float zoom;
    bool is_paused;
} Simulation;

void Simulation_Init(Simulation* simData);
void Simulation_SortBodies(Simulation* simData);
void Simulation_addBody(Simulation* simData);

#endif
