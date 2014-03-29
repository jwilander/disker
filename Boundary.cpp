//
//  Boundary.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-27.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#include "Boundary.h"

Boundary::Boundary(PhysicsScreen *scene, float width, float height)
{
    /* set up boundary entities */
    topWall = new ScreenShape(ScreenShape::SHAPE_RECT, width*0.95f, 8);
    topWall->setPosition(-0.0025f * width, height/2 - 0.025f * height);
    topWall->setColorInt(215, 31, 38, 255);
    topWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(topWall, PhysicsScreenEntity::ENTITY_RECT, true, 0.1, 1, 0, false, false, -1);
    
    leftWall = new ScreenShape(ScreenShape::SHAPE_RECT, 8, height*0.95f);
    leftWall->setPosition(-width/2 + 0.0258f * width, -0.0025f * height);
    leftWall->setColorInt(215, 31, 38, 255);
    leftWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(leftWall, PhysicsScreenEntity::ENTITY_RECT, true);
    
    rightWall = new ScreenShape(ScreenShape::SHAPE_RECT, 8, height*0.95f);
    rightWall->setPosition(width/2 - 0.0305f * width, -0.0025f * height);
    rightWall->setColorInt(215, 31, 38, 255);
    rightWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(rightWall, PhysicsScreenEntity::ENTITY_RECT, true);
    
    bottomWall = new ScreenShape(ScreenShape::SHAPE_RECT, width*0.95f, 8);
    bottomWall->setPosition(-0.0025f * width, -height/2 + 0.025f * height);
    bottomWall->setColorInt(215, 31, 38, 255);
    bottomWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(bottomWall, PhysicsScreenEntity::ENTITY_RECT, true);
}

Boundary::~Boundary()
{
    delete topWall;
    delete leftWall;
    delete rightWall;
    delete bottomWall;
}

