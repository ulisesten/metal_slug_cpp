#pragma once

#include <iostream>
#include "i_attack_behavior.h"
#include "base_object.h"
#include "i_game_element.h"
#include "i_player_rects.h"
#include <SDL2/SDL_image.h>
#include "i_event_driver.h"


class IAttackBehavior;

class Soldier: public BaseObject, public IGameElement {

    protected:
        std::string _name;
        IAttackBehavior* _behavior = nullptr;
        const char* _sprite_path = nullptr;
        //int direction;

        SDL_Rect sprite_torso_rect;
        SDL_Rect sprite_leg_rect;

        SDL_Rect torso_position_rect;
        SDL_Rect leg_position_rect;

        /// @brief Rect array for compose objects like player or soldiers. This is for torso animation
        SDL_Rect* sprite_torso_rects_array = nullptr;

        /// @brief Rect array for compose objects like player or soldiers. This is for leg animation
        SDL_Rect* sprite_leg_rects_array = nullptr;

        EVENT_CONTROL event_control = {true};

    public:
        Soldier(std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect);
        void attack(Soldier* who);
        void setAttackBehavior(IAttackBehavior* b);
        const std::string& getName() const;

        void move() override;
        void paint() override;
        void update() override;
        void setDirection() override;

};