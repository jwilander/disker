//
//  PlayerDeath.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-28.
//  Copyright (c) 2014 SLTR. All rights reserved.
//

#ifndef __Disker__PlayerDeath__
#define __Disker__PlayerDeath__

#include "Player.h"

class Player;

class PlayerDeath
{
    friend class Player;
    
public:
    PlayerDeath(Player *player, PhysicsScreen *scene);
    
private:
    Player *player;
    PhysicsScreen *scene;
    float deathTimer;
    std::vector<ScreenImage*> playerShards;
    bool Update(float elapsed);
    
    void Kill();
    void Respawn();
    void AddPlayerShards();
    void RemovePlayerShards();
    void ApplyBlast(ScreenEntity * entity, Vector2 blastPoint, float blastPower);
    
};

#endif /* defined(__Disker__PlayerDeath__) */
