//
//  CollisionHandler.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-28.
//  Copyright (c) 2014 SLTR. All rights reserved.
//

#ifndef __Disker__CollisionHandler__
#define __Disker__CollisionHandler__

#include <Polycode.h>
#include "PolycodeView.h"
#include "Player.h"
#include "Boundary.h"

class CollisionHandler : public EventHandler {
public:
    CollisionHandler(PhysicsScreen *scene, Player *player);
    
    void handleEvent(Event *e);
    
private:
    PhysicsScreen *scene;
    Player *player;
    
    void HandleCollisionStart(PhysicsScreenEvent *pe);
    
};

#endif /* defined(__Disker__CollisionHandler__) */
