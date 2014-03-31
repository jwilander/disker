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
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard1.png"));
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard2.png"));
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard3.png"));
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard4.png"));
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard5.png"));
    playerShards.push_back(new ScreenImage("/usr/local/joram/disker/Resources/playerShard5.png"));
    
}

bool PlayerDeath::Update(float elapsed)
{
    /* if the player is alive and health equals zero or less, update state to DYING*/
    if (player->state == Player::ALIVE) {
        if (player->health <= 0)
        {
            player->state = Player::DYING;
            AddPlayerShards();
            scene->removeChild(player->sprite);
            deathTimer = 0.0f;
            return true;
        }
    /* if player as been dying long enough, update state to DEAD */
    } else if (player->state == Player::DYING) {
        deathTimer += elapsed;
        if (deathTimer >= DYING_TIME)
        {
            RemovePlayerShards();
            player->state = Player::DEAD;
            return true;
        }
    }
    
    return true;
}

void PlayerDeath::AddPlayerShards()
{
    Vector2 playerPos = player->sprite->getPosition2D();
    Vector2 playerDir(cos(player->direction), sin(player->direction));
    playerDir.Normalize();
    Vector2 shardPosition(playerPos.x, playerPos.y);
    
    for (int i = 0; i < playerShards.size(); ++i)
    {
        playerShards[i]->setPosition(shardPosition.x + playerDir.x * i*2, shardPosition.y + playerDir.y * i*2);
        playerShards[i]->setRoll(player->direction*180/PI);
        scene->addPhysicsChild(playerShards[i], PhysicsScreenEntity::ENTITY_MESH, false, 0.1, 0.1, 0.2);
        ApplyBlast(playerShards[i], playerPos, 9000.0f);
    }
}

void PlayerDeath::RemovePlayerShards()
{
    for (int i = 0; i < playerShards.size(); ++i) {
        scene->removePhysicsChild(playerShards[i]);
    }
}

void PlayerDeath::ApplyBlast(ScreenEntity *entity, Vector2 blastPoint, float blastPower)
{
    Vector2 direction = entity->getPosition2D() - blastPoint;
    float distance = direction.length();
    direction.Normalize();
    
    if (distance == 0.0f)
        return;
    
    float invDistance = 1 / distance;
    float impulseMag = blastPower * invDistance * invDistance;
    scene->applyImpulse(entity, direction.x * impulseMag, direction.y * impulseMag);
}

/* reset the player to inital spawn state */
void PlayerDeath::Respawn()
{
    player->sprite->setPosition(0, 0);
    player->ZeroVelocity();
    player->health = MAX_PLAYER_HEALTH;
    player->state = Player::ALIVE;
    scene->addCollisionChild(player->sprite, PhysicsScreenEntity::ENTITY_CIRCLE);
}