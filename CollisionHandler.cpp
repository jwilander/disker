//
//  CollisionHandler.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-28.
//  Copyright (c) 2014 SLTR. All rights reserved.
//

#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(PhysicsScreen *scene, Player *player)
{
    this->scene = scene;
    this->player = player;
}

void CollisionHandler::handleEvent(Event *e)
{
    /* only accept events sent from the right place */
    if (e->getDispatcher() == scene)
    {
        PhysicsScreenEvent *pe = (PhysicsScreenEvent*) e;
        switch (pe->getEventCode())
        {
            case PhysicsScreenEvent::EVENT_NEW_SHAPE_COLLISION:
                HandleCollisionStart(pe);
                break;                
            default:
                break;
        }
    }
}

/* handles all the possible cases for when collisions start */
void CollisionHandler::HandleCollisionStart(PhysicsScreenEvent *pe)
{
    String entityType1 = pe->entity1->custEntityType;
    String entityType2 = pe->entity2->custEntityType;
    
    /* check all useful cases for first possible combination */
    if (entityType1 == ENTITY_PLAYER)
    {
        /* kill the player if they hit the board edge */
        if (entityType2 == ENTITY_BOUNDARY) {
            static_cast<Player*>(pe->entity1->getUserData())->Damage(MAX_PLAYER_HEALTH);
            return;
        }
    }
    
    /* check all useful cases for the other possible combination */
    if (entityType2 == ENTITY_PLAYER)
    {
        /* kill the player if they hit the board edge */
        if (entityType1 == ENTITY_BOUNDARY) {
            static_cast<Player*>(pe->entity2->getUserData())->Damage(MAX_PLAYER_HEALTH);
            return;
        }
    }
}