#ifndef PHYSICS_H
#define PHYSICS_H

#include "simBody.h"
#include <math.h>

void Physics_calcAll(Body* bodies, unsigned body_count, double deltaTime);
void Physics_updateVelocity(Body* body, double deltaTime);

#endif
