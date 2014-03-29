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
#include "PlayerDeath.h"

class PlayerMovement;
class PlayerDeath;

const String ENTITY_PLAYER = "player";
const int MAX_PLAYER_HEALTH = 1000;
const float START_PLAYER_DIRECTION = 0.0f;
const float PLAYER_WIDTH = 71.25;
const float PLAYER_HEIGHT = 67.5;

class Player {
    friend class PlayerMovement;
    friend class PlayerDeath;
    
public:
    Player(PhysicsScreen *scene);
    ~Player();
    
    bool Update(float elapsed);
    
    /* PlayerMovement functions */
    void MoveForward();
    void MoveBackward();
    void StopMove();
    void ZeroVelocity();
    void TurnClockwise();
    void TurnAntiClockwise();
    void StopTurn();
    
    /* PlayerAttack functions */
    void Shoot();
    
    /* PlayerDeath functions */
    void Respawn();

private:
    /* friend logic classes, for encapsulating all player logic */
    PlayerMovement *playerMovement;
    PlayerDeath *playerDeath;
    
    /* player variables */
    int health;
    float direction;
    SceneSprite *sprite;
};

#endif /* defined(__Disker__Player__) */
