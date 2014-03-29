//
//  PlayerMovement.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-25.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#include "PlayerMovement.h"
#include <algorithm>

const float MOVEMENT_ACCEL = 15.0f; // meters per second^2
const float FRICTION_ACCEL = 5.0f; // meters per second^2
const float MAX_SPEED = 20.0f; // meters per second
const float TURNING_SPEED = 5.5f; // radians per second

PlayerMovement::PlayerMovement(Player *player, PhysicsScreen *scene)
{
    this->player = player;
    this->scene = scene;
    
    rollSpeed = 0.0f;
    accelerationX = 0.0f;
    accelerationY = 0.0f;
    velocityX = 0.0f;
    velocityY = 0.0f;
}

bool PlayerMovement::Update(float elapsed)
{
    /* calculate and apply player rotation */
    player->direction += rollSpeed * elapsed;
    player->sprite->setRoll(player->direction*180/PI);
    
    /* calculate facing direction vector */
    float faceDirectionX = cos(player->direction);
    float faceDirectionY = sin(player->direction);
    
    /* calculate new velocity using the direction player is facing and time elapsed */
    velocityX += faceDirectionX * accelerationX * elapsed;
    velocityY += faceDirectionY * accelerationY * elapsed;
    
    /* calculate speed */
    float speed = std::sqrt(velocityX * velocityX + velocityY * velocityY);
    
    /* calculate movement direction vector */
    float moveDirectionX = std::abs(velocityX / speed);
    float moveDirectionY = std::abs(velocityY / speed);
    
    /* apply friction to velocity */
    if (velocityX > 0.0f)
        velocityX -= std::min(FRICTION_ACCEL * moveDirectionX * elapsed, velocityX);
    else if (velocityX < 0.0f)
        velocityX += std::max(FRICTION_ACCEL * moveDirectionX * elapsed, velocityX);
    
    if (velocityY > 0.0f)
        velocityY -= std::min(FRICTION_ACCEL * moveDirectionY * elapsed, velocityY);
    else if (velocityY < 0.0f)
        velocityY += std::max(FRICTION_ACCEL * moveDirectionY * elapsed, velocityY);
    
    /* recalculate speed from new velocity */
    speed = std::sqrt(velocityX * velocityX + velocityY * velocityY);
    
    /* limit velocity */
    if (speed > MAX_SPEED)
    {
        velocityX = velocityX * MAX_SPEED / speed;
        velocityY = velocityY * MAX_SPEED / speed;
    }
    
    /* update position based on current position and new velocity */
    Vector2 currentPosition = player->sprite->getPosition2D();
    player->sprite->setPosition(currentPosition.x + velocityX, currentPosition.y + velocityY);
    
    return true;
}

void PlayerMovement::StartMove(MovementType moveType)
{
    if (moveType == FORWARD)
    {
        accelerationX = MOVEMENT_ACCEL;
        accelerationY = MOVEMENT_ACCEL;
    }
    else
    {
        accelerationX = -MOVEMENT_ACCEL;
        accelerationY = -MOVEMENT_ACCEL;
    }
}

void PlayerMovement::StopMove()
{
    accelerationX = 0.0f;
    accelerationY = 0.0f;
}

void PlayerMovement::ZeroVelocity()
{
    velocityX = 0.0f;
    velocityY = 0.0f;
}

void PlayerMovement::StartTurn(TurnType turnType)
{
    if (turnType == CLOCKWISE)
    {
        rollSpeed = TURNING_SPEED;
    }
    else
    {
        rollSpeed = -TURNING_SPEED;
    }
}

void PlayerMovement::StopTurn()
{
    rollSpeed = 0.0f;
}