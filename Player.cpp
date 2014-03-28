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
    health = 1000;
    direction = 0.0f;
    
    // TODO - figure out relative path
    sprite = new SceneSprite("/usr/local/joram/disker/Resources/playerSprite.png", 192, 182);
    sprite->setScale(0.3f, 0.3f);
    sprite->custEntityType = ENTITY_PLAYER;
    scene->addCollisionChild(sprite, PhysicsScene2DEntity::ENTITY_CIRCLE, false);
    
    playerMovement = new PlayerMovement(this, scene);
}

bool Player::Update(float elapsed)
{
    playerMovement->Update(elapsed);
    return true;
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

Player::~Player()
{
    delete sprite;
    delete playerMovement;
}