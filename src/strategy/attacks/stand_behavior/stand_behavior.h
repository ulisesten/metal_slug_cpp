#ifndef __STAND_BEHAVIOR_H__
#define __STAND_BEHAVIOR_H__

#include "i_attack_behavior.h"

class StandBehavior: IAttackBehavior {
public:
    void paint(SDL_Renderer* renderer, SDL_Texture* texture, int direction);
    void performAttack(Soldier* attacker, Soldier* who);
};

#endif //__STAND_BEHAVIOR_H__