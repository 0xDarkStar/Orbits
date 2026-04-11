#include "physics.h"
#include "simBody.h"
#include <math.h>

const double GRAVITY = 1;

void Physics_calcAll(Body* bodies, unsigned body_count, double deltaTime) {
    // First, reset all accelerations
    for (int i = 0; i < body_count; i++) {
        bodies[i].ax = 0.0;
        bodies[i].ay = 0.0;
        bodies[i].az = 0.0;
    }
    
    // Calculate all gravitational forces and accumulate accelerations
    for (int i = 0; i < body_count; i++) {
        for (int j = i+1; j < body_count; j++) {
            double forceVector[3] = {bodies[j].x-bodies[i].x, bodies[j].y-bodies[i].y, bodies[j].z-bodies[i].z};
            double distance = sqrt(forceVector[0]*forceVector[0] + forceVector[1]*forceVector[1] + forceVector[2]*forceVector[2]);
            
            // Avoid division by zero when bodies are at the same position
            if (distance < 0.0001) {
                continue;
            }
            
            // Normalize the force vector to get direction
            double invDistance = 1.0 / distance;
            double directionX = forceVector[0] * invDistance;
            double directionY = forceVector[1] * invDistance;
            double directionZ = forceVector[2] * invDistance;
            
            double force = GRAVITY*(bodies[i].mass*bodies[j].mass)/(distance*distance);
            double forceX = force*directionX;
            double forceY = force*directionY;
            double forceZ = force*directionZ;

            // Apply force to both bodies (F = ma, so a = F/m)
            bodies[i].ax += forceX/bodies[i].mass;
            bodies[i].ay += forceY/bodies[i].mass;
            bodies[i].az += forceZ/bodies[i].mass;
            
            bodies[j].ax += (-forceX)/bodies[j].mass;
            bodies[j].ay += (-forceY)/bodies[j].mass;
            bodies[j].az += (-forceZ)/bodies[j].mass;
        }
    }
    
    // Update all velocities based on accumulated accelerations
    for (int i = 0; i < body_count; i++) {
        Physics_updateVelocity(&bodies[i], deltaTime);
    }
}

void Physics_updateVelocity(Body* body, double deltaTime) {
    body->vx += body->ax*deltaTime;
    body->vy += body->ay*deltaTime;
    body->vz += body->az*deltaTime;
}
