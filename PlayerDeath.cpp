//
//  PlayerDeath.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-28.
//  Copyright (c) 2014 SLTR. All rights reserved.
//

#include "PlayerDeath.h"

PlayerDeath::PlayerDeath(Player *player, PhysicsScreen *scene)
{
    this->player = player;
    this->scene = scene;
}

/* reset the player to inital spawn state */
void PlayerDeath::Respawn()
{
    player->sprite->setPosition(0, 0);
    scene->setVelocity(player->sprite, 0, 0);
}