/**
 * 
*/

#include "i_attack_behavior.h"

void KnifeAttack::performAttack(Soldier* attacker, Soldier* who) {
    std::cout << attacker->getName() << " knifing to " << who->getName() << std::endl;
}

void GunAttack::performAttack(Soldier* attacker, Soldier* who) {
    std::cout << attacker->getName() << " shoots to " << who->getName() << std::endl;
}