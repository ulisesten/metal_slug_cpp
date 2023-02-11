#pragma once

#include "soldier_class.h"
#include <iostream>

class Soldier;



/**Interface*/
class IAttackBehavior {
public:
    virtual void performAttack(Soldier* attacker, Soldier* who) = 0;

};



class KnifeAttack: public IAttackBehavior {
public:
    virtual void performAttack(Soldier* attacker, Soldier* who);
};



class GunAttack: public IAttackBehavior {
public:
    virtual void performAttack(Soldier* attacker, Soldier* who);
};


