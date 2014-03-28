//
//  PlayerMovement.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-25.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#ifndef __Disker__PlayerMovement__
#define __Disker__PlayerMovement__

#include "Player.h"

class Player;

class PlayerMovement {
    friend class Player;
    
public:
    PlayerMovement(Player *player, PhysicsScreen *scene);
    enum MovementType {FORWARD, BACKWARD};
    enum TurnType {CLOCKWISE, ANTICLOCKWISE};
    
private:
    Player *player;
    PhysicsScreen *scene;
    
    float rollSpeed;
    float accelerationX;
    float accelerationY;
    float velocityX;
    float velocityY;
    
    bool Update(float elapsed);
    
    void StartMove(MovementType moveType);
    void StopMove();
    void StartTurn(TurnType turnType);
    void StopTurn();
    
};

#endif /* defined(__Disker__PlayerMovement__) */
