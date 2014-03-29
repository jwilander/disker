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
    topWall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, width*0.95f, 8);
    topWall->setPosition(-0.0025f * width, height/2 - 0.025f * height);
    topWall->setColorInt(215, 31, 38, 255);
    topWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(topWall, PhysicsScene2DEntity::ENTITY_RECT, true);
    
    leftWall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 8, height*0.95f);
    leftWall->setPosition(-width/2 + 0.0258f * width, -0.0025f * height);
    leftWall->setColorInt(215, 31, 38, 255);
    leftWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(leftWall, PhysicsScene2DEntity::ENTITY_RECT, true);
    
    rightWall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 8, height*0.95f);
    rightWall->setPosition(width/2 - 0.0305f * width, -0.0025f * height);
    rightWall->setColorInt(215, 31, 38, 255);
    rightWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(rightWall, PhysicsScene2DEntity::ENTITY_RECT, true);
    
    bottomWall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, width*0.95f, 8);
    bottomWall->setPosition(-0.0025f * width, -height/2 + 0.025f * height);
    bottomWall->setColorInt(215, 31, 38, 255);
    bottomWall->custEntityType = ENTITY_BOUNDARY;
    scene->addPhysicsChild(bottomWall, PhysicsScene2DEntity::ENTITY_RECT, true);
}

Boundary::~Boundary()
{
    delete topWall;
    delete leftWall;
    delete rightWall;
    delete bottomWall;
}

