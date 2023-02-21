#pragma once

#include <iostream>
#include "i_attack_behavior.h"
#include "base_object.h"
#include "i_game_element.h"
#include "i_player_rects.h"
#include <SDL2/SDL_image.h>


class IAttackBehavior;

class Soldier: public BaseObject, public IGameElement {

    protected:
        std::string _name;
        IAttackBehavior* _behavior;
        const char* _sprite_path;
        int direction;
        

    public:
        Soldier(std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects);
        void attack(Soldier* who);
        void setAttackBehavior(IAttackBehavior* b);
        const std::string& getName() const;

        void move() override;
        void paint() override;
        void update() override;
        void setDirection() override;

};