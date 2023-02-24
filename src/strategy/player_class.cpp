#include "player_class.h"

#include <iostream>

Player::Player(const std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects, SDL_Rect position_rect): Soldier(name, sprite_path, renderer, player_rects, position_rect) {
    //Soldier::_sprite_path = sprite_path;
    

}

void Player::networking() {
    
}

void Player::keyPressed(SDL_Event event) {


    /*if(event.key.keysym.sym == SDLK_RIGHT){

        Soldier::direction = RIGHT;

    } else if(event.key.keysym.sym == SDLK_LEFT){

        Soldier::direction = LEFT;

    } else if(event.key.keysym.sym == SDLK_UP){

        Soldier::direction = UP;

    } else if(event.key.keysym.sym == SDLK_DOWN){

        Soldier::direction = DOWN;

    }*/
};