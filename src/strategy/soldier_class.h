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
        int movement_range = 3;

        SDL_Rect sprite_torso_rect;
        SDL_Rect sprite_leg_rect;

        SDL_Rect torso_position_rect;
        SDL_Rect leg_position_rect;

        /// @brief Rect array for compose objects like player or soldiers. This is for torso animation
        SDL_Rect* sprite_torso_rects_array = nullptr;

        /// @brief Rect array for compose objects like player or soldiers. This is for leg animation
        SDL_Rect* sprite_leg_rects_array = nullptr;

        EVENT_CONTROL event_control = {false};

        IPlayerRects* playerRects = nullptr;

        int* ground_bounds_array;

    public:
        Soldier(std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect);
        void attack(Soldier* who);
        void setAttackBehavior(IAttackBehavior* b);
        const std::string& getName() const;

        void move() override;
        void paint() override;
        void update() override;
        void setDirection() override;

        /**
         * @brief Sets the array that contains the floor coors of the scenario
         * @param heightArray array of integers; it will be summed to the rect.y to control the y position
        */

};