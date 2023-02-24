#include "player_class.h"

#include <iostream>

Player::Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect): Soldier(name, sprite_path, renderer, player_rects, position_rect) {
    //Soldier::_sprite_path = sprite_path;
    

}

void Player::networking() {
    
}

bool Player::handleEvents() {
    if (SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: {
                //SDL_Log("Quiting from player_class");
                return true;
            }

            case SDLK_f: {
                //ToggleFullscreen();
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


    if(event.key.keysym.sym == SDLK_RIGHT){
        SDL_Log("going right");
        Soldier::direction = RIGHT;

    } else if(event.key.keysym.sym == SDLK_LEFT){
        SDL_Log("going left");
        Soldier::direction = LEFT;

    } else if(event.key.keysym.sym == SDLK_UP){

        Soldier::direction = UP;

    } else if(event.key.keysym.sym == SDLK_DOWN){

        Soldier::direction = DOWN;

    }
};