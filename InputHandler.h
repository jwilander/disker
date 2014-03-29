//
//  InputHandler.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-26.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#ifndef __Disker__InputHandler__
#define __Disker__InputHandler__

#include <Polycode.h>
#include "PolycodeView.h"
#include "Player.h"

class InputHandler : public EventHandler
{
public:
    InputHandler(CoreInput *coreInput, Player *player);
    
    void handleEvent(Event *e);

private:
    CoreInput *coreInput;
    Player *player;
    
    void HandleKeyDown(PolyKEY key);
    void HandleKeyUp(PolyKEY key);
};

#endif /* defined(__Disker__InputHandler__) */
