#include "simData.h"
#include "simBody.h"
#include <stdbool.h>
#include <stdlib.h>

const int CAPACITY = 100;

void Simulation_Init(Simulation* simData) {
    simData->bodies = malloc(CAPACITY * sizeof(Body));
    simData->body_count = 0;
    simData->viewX = 0;
    simData->viewY = 0;
    simData->viewZ = 0;
    simData->zoom = 0;
    simData->is_paused = false;
}

int compareByZ(const void* bodyA, const void* bodyB) {
    if ( (*(Body*)bodyA).z < (*(Body*)bodyB).z) return -1;
    if ( (*(Body*)bodyA).z == (*(Body*)bodyB).z) return 0;
    if ( (*(Body*)bodyA).z > (*(Body*)bodyB).z) return 1;
}

void Simulation_SortBodies(Simulation* simData) {
    qsort(simData->bodies, simData->body_count, sizeof(Body), compareByZ);
}

