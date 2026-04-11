#include <stdio.h>
#include <stdlib.h>
#include "include/displayLoop.h"
#include "include/simData.h"
#include "include/simBody.h"

void runNicto() {
    Simulation simData;
    Simulation_Init(&simData);
    Body_Init(&simData.bodies[0], 400, 300, 0, 0, 0, 0, 30, 100000, 50, 50, 200);     // Cherenkov
    Body_Init(&simData.bodies[1], 500, 240, 0, -15, -25, 2, 10, 5000, 200, 100, 100); // Morga
    Body_Init(&simData.bodies[2], 510, 240, 0, -4, -7, 4, 3, 500, 150, 50, 50);       // Morga A (lazy)
    simData.body_count = 3;
    printf("Starting Nicto simulation\n");
    Loop_Start(simData);
    free(simData.bodies);
}

void runXYplane() {
    // Simulation 1: XY plane only (vz = 0 for all bodies)
    Simulation simData1;
    Simulation_Init(&simData1);
    Body_Init(&simData1.bodies[0], 400, 300, 0, 10, 5, 0, 30, 100000, 50, 50, 200);
    Body_Init(&simData1.bodies[1], 500, 240, 0, -5, -20, 0, 10, 5000, 200, 100, 100);
    simData1.body_count = 2;
    printf("Starting XY plane simulation (press X to close)\n");
    Loop_Start(simData1);
    free(simData1.bodies);
}

void runXZplane() {
    // Simulation 2: XZ plane only (vy = 0 for all bodies)
    Simulation simData2;
    Simulation_Init(&simData2);
    Body_Init(&simData2.bodies[0], 400, 300, 0, 0, 0, 0, 30, 100000, 50, 50, 200);
    Body_Init(&simData2.bodies[1], 500, 300, 0, -15, 0, -25, 10, 5000, 200, 100, 100);
    Body_Init(&simData2.bodies[2], 450, 300, 0, 5, 0, 10, 15, 2000, 150, 150, 50);
    simData2.body_count = 3;
    printf("Starting XZ plane simulation (press X to close)\n");
    Loop_Start(simData2);
    free(simData2.bodies);
}

void runYZplane() {
    // Simulation 3: YZ plane only (vx = 0 for all bodies)
    Simulation simData3;
    Simulation_Init(&simData3);
    Body_Init(&simData3.bodies[0], 400, 300, 0, 0, 0, 0, 30, 100000, 50, 50, 200);
    Body_Init(&simData3.bodies[1], 400, 240, 0, 0, 20, -40, 10, 5000, 200, 100, 100);
    simData3.body_count = 2;
    printf("Starting YZ plane simulation (press X to close)\n");
    Loop_Start(simData3);
    free(simData3.bodies);
}

void runAllPlanes() {
    // Simulation 4: All three axes (vx, vy, vz all non-zero)
    Simulation simData4;
    Simulation_Init(&simData4);
    Body_Init(&simData4.bodies[0], 400, 300, 0, 10, 5, 3, 30, 100000, 50, 50, 200);
    Body_Init(&simData4.bodies[1], 500, 240, 0, -15, -25, 2, 10, 5000, 200, 100, 100);
    Body_Init(&simData4.bodies[2], 450, 270, 0, -4, -7, 4, 15, 2000, 150, 50, 50);
    simData4.body_count = 3;
    printf("Starting XYZ (3D) simulation (press X to close)\n");
    Loop_Start(simData4);
    free(simData4.bodies);
}

int main(int argc, char *argv[]) {
    runNicto();
    // runXYplane();
    // runXZplane();
    runYZplane();
    // runAllPlanes();
    printf("\n");
    return 0;
}
