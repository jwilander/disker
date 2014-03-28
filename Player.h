//
//  Player.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-25.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//


#ifndef __Disker__Player__
#define __Disker__Player__

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"
#include "PlayerMovement.h"

class PlayerMovement;

const String ENTITY_PLAYER = "player";

class Player {
    friend class PlayerMovement;
    
public:
    Player(PhysicsScreen *scene);
    ~Player();
    
    bool Update(float elapsed);
    
    /* PlayerMovement functions */
    void MoveForward();
    void MoveBackward();
    void StopMove();
    void TurnClockwise();
    void TurnAntiClockwise();
    void StopTurn();
    
    /* PlayerAttack functions */
    void Shoot();

private:
    /* friend logic classes, for encapsulating all player logic */
    PlayerMovement *playerMovement;
    
    /* player variables */
    int health;
    float direction;
    SceneSprite *sprite;
};

#endif /* defined(__Disker__Player__) */
