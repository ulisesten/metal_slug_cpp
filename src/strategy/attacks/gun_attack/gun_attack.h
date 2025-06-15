#ifndef __GUN_ATTACK_H__
#define __GUN_ATTACK_H__

#include "i_attack_behavior.h"

class GunAttack: public IAttackBehavior {

public:
    void paint(SDL_Renderer* renderer, SDL_Texture* texture, int direction);
    void performAttack(Soldier* attacker, Soldier* who);
};

#endif // __GUN_ATTACK_H__