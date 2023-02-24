#pragma once

#include "soldier_class.h"
#include "i_player_rects.h"

class Player: public Soldier {

public:
    // name, sprite_path
    Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect);
    void networking();
    void keyPressed(SDL_Event event) override;

};