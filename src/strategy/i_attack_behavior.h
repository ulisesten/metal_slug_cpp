#pragma once

#include "soldier_class.h"
#include <SDL2/SDL.h>
#include <iostream>

class Soldier;


/**Interface*/
class IAttackBehavior {

protected:
    /// check this static vars for duplication
    static const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
    SDL_Rect leg_position_rect;
    SDL_Rect torso_position_rect;
    SDL_Rect sprite_torso_rect;
    SDL_Rect sprite_leg_rect;
    
public:
    virtual void paint(SDL_Renderer* renderer, SDL_Texture* texture, int direction) = 0;
    virtual void performAttack(Soldier* attacker, Soldier* who) = 0;

};