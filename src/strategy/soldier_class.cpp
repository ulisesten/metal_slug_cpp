#include "strategy/soldier_class.hpp"

#include <iostream>

/**
 * @brief Realiza el ataque
 * @param who Es el objetivo del ataque
*/
void Soldier::attack(Soldier* who){
    if (this->_behavior)
        this->_behavior->performAttack(this, who);
    else
        std::cout << "No attack performed" << std::endl;
}

void Soldier::setAttackBehavior(IAttackBehavior* b){
    this->_behavior = b;
}

const std::string& Soldier::getName() const { return this->_name; };