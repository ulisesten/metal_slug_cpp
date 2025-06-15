#pragma once

#include "soldier_class.h"
#include "i_player_rects.h"
#include "i_event_driver.h"

class Player: public Soldier {
    IEventDriver* eventDriver;
    SDL_Event player_event;
public:
    // name, sprite_path
    Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect, IEventDriver* eventDriver);
    void networking();
    void keyPressed() override;
    bool handleEvents(SDL_Event event) override;
    void setGroundBoundsArray(int* ground_bounds_array) override;

};