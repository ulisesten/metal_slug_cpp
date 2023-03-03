#include "player_class.h"

#include <iostream>

Player::Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect, IEventDriver* eventDriver): Soldier(name, sprite_path, renderer, player_rects, position_rect) {
    this->eventDriver = eventDriver;
    

}

void Player::networking() {
    
}

bool Player::handleEvents(SDL_Event event) {

    return eventDriver->handleEvents(&event, &event_control);

}

void Player::keyPressed() {

    if(player_event.key.keysym.sym == SDLK_RIGHT){
        
        this->event_control.direction = RIGHT;

    } else if(player_event.key.keysym.sym == SDLK_LEFT){

        this->event_control.direction = LEFT;

    } else if(player_event.key.keysym.sym == SDLK_UP){

        this->event_control.direction = UP;

    } else if(player_event.key.keysym.sym == SDLK_DOWN){

        this->event_control.direction = DOWN;

    }

};