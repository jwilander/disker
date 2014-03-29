//
//  Player.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-25.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#include "Player.h"

Player::Player(PhysicsScreen *scene)
{
    health = MAX_PLAYER_HEALTH;
    direction = START_PLAYER_DIRECTION;
    state = ALIVE;
    // TODO - figure out relative path
    sprite = new ScreenSprite("/usr/local/joram/disker/Resources/playerSprite.png", PLAYER_WIDTH, PLAYER_HEIGHT);
    sprite->custEntityType = ENTITY_PLAYER;
    sprite->setUserData(this);
    scene->addCollisionChild(sprite, PhysicsScreenEntity::ENTITY_CIRCLE);
    
    playerMovement = new PlayerMovement(this, scene);
    playerDeath = new PlayerDeath(this, scene);
}

bool Player::Update(float elapsed)
{
    switch (state) {
        case ALIVE:
            playerMovement->Update(elapsed);
            playerDeath->Update(elapsed);
            break;
        case DYING:
            playerDeath->Update(elapsed);
            break;
        case DEAD:
            playerDeath->Respawn();
            break;
    }
    return true;
}

void Player::Damage(int amount)
{
    /* don't allow increasing health */
    if (health < 0)
        return;
    
    health -= amount;
}

/* begin PlayerMovement functions */

void Player::MoveForward()
{
    playerMovement->StartMove(PlayerMovement::FORWARD);
}

void Player::MoveBackward()
{
    playerMovement->StartMove(PlayerMovement::BACKWARD);
}

void Player::StopMove()
{
    playerMovement->StopMove();
}

void Player::ZeroVelocity()
{
    playerMovement->ZeroVelocity();
}

void Player::TurnClockwise()
{
    playerMovement->StartTurn(PlayerMovement::CLOCKWISE);
}

void Player::TurnAntiClockwise()
{
    playerMovement->StartTurn(PlayerMovement::ANTICLOCKWISE);
}

void Player::StopTurn()
{
    playerMovement->StopTurn();
}

/* end PlayerMovement functions */

/* begin PlayerAttack functions */

void Player::Shoot()
{
    
}

/* end PlayerAttack functions */

/* begin PlayerDeath functions */

//void Player::Respawn()
//{
//    playerDeath->Respawn();
//}

/* end PlayerDeath functions */

Player::~Player()
{
    delete sprite;
    delete playerMovement;
    delete playerDeath;
}