#pragma once

#include <iostream>
#include "i_attack_behavior.h"
#include "i_game_element.h"

class IAttackBehavior;

class Soldier: public IGameElement {
    protected:
        std::string _name;
        IAttackBehavior* _behavior;

    public:
        Soldier(std::string name): _name(name), _behavior(0){}

        void attack(Soldier* who);

        void setAttackBehavior(IAttackBehavior* b);

        const std::string& getName() const;


        void move() override;
        void paint() override;
        void update() override;
        void setDirection() override;
        void keyPressed(SDL_Event event) override;
        
};