#include "player_class.h"

#include <iostream>

Player::Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect, IEventDriver* eventDriver): Soldier(name, sprite_path, renderer, player_rects, position_rect) {
    this->eventDriver = eventDriver;
    

}

void Player::networking() {
    
}

bool Player::handleEvents(SDL_Event event) {
    //eventDriver->getEvent(&player_event);

    //if (SDL_PollEvent(&event)){
        return eventDriver->handleEvents(&event, &direction);
    //}

    //return false;
}

void Player::keyPressed() {

    if(player_event.key.keysym.sym == SDLK_RIGHT){
        
        this->direction = RIGHT;

    } else if(player_event.key.keysym.sym == SDLK_LEFT){

        this->direction = LEFT;

    } else if(player_event.key.keysym.sym == SDLK_UP){

        this->direction = UP;

    } else if(player_event.key.keysym.sym == SDLK_DOWN){

        this->direction = DOWN;

    }

};