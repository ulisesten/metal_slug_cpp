#include "player_class.h"

#include <iostream>

Player::Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect, IEventDriver* eventDriver): Soldier(name, sprite_path, renderer, player_rects, position_rect) {
    this->eventDriver = eventDriver;
    

}

void Player::networking() {
    
}

bool Player::handleEvents() {
    if (eventDriver->getEvent(&player_event)){
        switch(player_event.type){
            case SDL_QUIT: {
                //SDL_Log("Quiting from player_class");
                return true;
            }

            case SDLK_f: {
                //toggleFullscreen();
                break;
            }

            case SDL_KEYDOWN: {
                this->keyPressed();
                break;
            }
        }
    }

    return false;
}

void Player::keyPressed() {

    if(player_event.key.keysym.sym == SDLK_RIGHT){
        
        Soldier::direction = RIGHT;

    } else if(player_event.key.keysym.sym == SDLK_LEFT){

        Soldier::direction = LEFT;

    } else if(player_event.key.keysym.sym == SDLK_UP){

        Soldier::direction = UP;

    } else if(player_event.key.keysym.sym == SDLK_DOWN){

        Soldier::direction = DOWN;

    }

};