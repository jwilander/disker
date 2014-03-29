//
//  InputHandler.cpp
//  Disker
//
//  Created by Joram Wilander on 2014-03-26.
//  Copyright (c) 2014 Slaughter Games. All rights reserved.
//

#include "InputHandler.h"

InputHandler::InputHandler(CoreInput *coreInput, Player *player)
{
    this->coreInput = coreInput;
    this->player = player;
}

void InputHandler::handleEvent(Event *e)
{
    if (e->getDispatcher() == coreInput)
    {
        InputEvent *ie = (InputEvent*) e;
        switch (ie->getEventCode()) {
            case InputEvent::EVENT_KEYDOWN:
                HandleKeyDown(ie->getKey());
                break;
            case InputEvent::EVENT_KEYUP:
                HandleKeyUp(ie->getKey());
                break;
        }
        
    }
}

void InputHandler::HandleKeyDown(PolyKEY key)
{
    switch (key) {
        case Polycode::KEY_w:
            player->MoveForward();
            break;
        case Polycode::KEY_s:
            player->MoveBackward();
            break;
        case Polycode::KEY_a:
            player->TurnAntiClockwise();
            break;
        case Polycode::KEY_d:
            player->TurnClockwise();
            break;
        default:
            break;
    }
}

void InputHandler::HandleKeyUp(PolyKEY key)
{
    switch (key) {
        case Polycode::KEY_w:
            player->StopMove();
            break;
        case Polycode::KEY_s:
            player->StopMove();
            break;
        case Polycode::KEY_a:
            player->StopTurn();
            break;
        case Polycode::KEY_d:
            player->StopTurn();
            break;
        default:
            break;
    }
}