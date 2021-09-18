/**
 * 
*/

#include "personages/attack_behavior_interface.hpp"

void KnifeAttack::performAttack(Soldier* attacker, Soldier* who) {
    std::cout << attacker->getName() << " knifing to " << who->getName() << std::endl;
}

void GunAttack::performAttack(Soldier* attacker, Soldier* who) {
    std::cout << attacker->getName() << " shoots to " << who->getName() << std::endl;
}