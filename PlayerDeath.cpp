//
//  PlayerDeath.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-28.
//  Copyright (c) 2014 SLTR. All rights reserved.
//

#include "PlayerDeath.h"

const float DYING_TIME = 5.0f;

PlayerDeath::PlayerDeath(Player *player, PhysicsScreen *scene)
{
    this->player = player;
    this->scene = scene;
    
    deathTimer = 0.0f;
}

bool PlayerDeath::Update(float elapsed)
{
    /* if the player is alive and health equals zero or less, update state to DYING*/
    if (player->state == Player::ALIVE) {
        if (player->health <= 0)
        {
            player->state = Player::DYING;
            scene->removeChild(player->sprite);
            deathTimer = 0.0f;
            return true;
        }
    /* if player as been dying long enough, update state to DEAD */
    } else if (player->state == Player::DYING) {
        deathTimer += elapsed;
        if (deathTimer >= DYING_TIME)
        {
            player->state = Player::DEAD;
            return true;
        }
    }
    
    return true;
}

/* reset the player to inital spawn state */
void PlayerDeath::Respawn()
{
    player->sprite->setPosition(0, 0);
    player->ZeroVelocity();
    player->health = MAX_PLAYER_HEALTH;
    player->state = Player::ALIVE;
    scene->addCollisionChild(player->sprite, PhysicsScene2DEntity::ENTITY_CIRCLE);
}