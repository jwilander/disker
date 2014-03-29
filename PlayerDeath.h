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
    
    void Respawn();
    
};

#endif /* defined(__Disker__PlayerDeath__) */
