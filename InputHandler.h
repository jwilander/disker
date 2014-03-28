//
//  InputHandler.h
//  Disker
//
//  Created by Joram Wilander on 2014-03-26.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#include <Polycode.h>
#include "PolycodeView.h"
#include "Player.h"

#ifndef __Disker__InputHandler__
#define __Disker__InputHandler__

class InputHandler : public EventHandler
{
public:
    InputHandler(CoreInput *coreInput, Player *player);
    
    void handleEvent(Event *e);

private:
    CoreInput *coreInput;
    Player *player;
    
    void handleKeyDown(PolyKEY key);
    void handleKeyUp(PolyKEY key);
};

#endif /* defined(__Disker__InputHandler__) */
