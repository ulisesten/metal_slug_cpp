//
// Created by ulises on 21/12/22.
//

#ifndef __I_GAME_ELEMENT_H__
#define __I_GAME_ELEMENT_H__

#include "SDL2/SDL.h"

/**
 * @author Ulisesten
 * @brief  Interface that is injected to scenario and inherited by players or enemies
*/
class IGameElement {
public:
    virtual void move() = 0;
    virtual void paint() = 0;
    virtual void update() = 0;
    virtual void setDirection() = 0;
    virtual void keyPressed() = 0;
    virtual bool handleEvents(SDL_Event event) = 0;
    virtual void setGroundBoundsArray(int* ground_bounds_array) = 0;
};

#endif //__I_GAME_ELEMENT_H__