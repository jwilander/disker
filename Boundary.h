//
//  Boundary.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-27.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#ifndef __Disker__Boundary__
#define __Disker__Boundary__

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"

const String ENTITY_BOUNDARY = "boundary";

class Boundary {
public:
    Boundary(PhysicsScreen *scene, float width, float height);
    ~Boundary();
    
private:
    ScenePrimitive *topWall;
    ScenePrimitive *leftWall;
    ScenePrimitive *rightWall;
    ScenePrimitive *bottomWall;
    
};

#endif /* defined(__Disker__Boundary__) */
