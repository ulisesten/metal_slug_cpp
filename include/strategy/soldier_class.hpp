#pragma once

#include "attack_behavior_interface.hpp"
#include <iostream>

class IAttackBehavior;

class Soldier {
    protected:
        std::string _name;
        IAttackBehavior* _behavior;

    public:
        Soldier(std::string name): _name(name), _behavior(0){}

        void attack(Soldier* who);

        void setAttackBehavior(IAttackBehavior* b);

        const std::string& getName() const;
        
};