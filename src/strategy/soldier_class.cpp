#include "soldier_class.h"
#include <iostream>


Soldier::Soldier(std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* playerRects, SDL_Rect position_rect): _name(name), _behavior(0), _sprite_path(sprite_path) {
    
    this->renderer = renderer;
    this->playerRects = playerRects;
    object_surface = IMG_Load(sprite_path);

    if(!object_surface)
        SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "Couldn't load surface: %s", IMG_GetError());

    this->object_texture = SDL_CreateTextureFromSurface(this->renderer, this->object_surface);

    if(!this->object_texture)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Couldn't load texture: %s", SDL_GetError());


    SDL_FreeSurface(object_surface);

    leg_position_rect= position_rect;

    sprite_torso_rects_array = playerRects->getTorsoStandRect();
    sprite_leg_rects_array = playerRects->getLegsStandRect();

    sprite_torso_rect = sprite_torso_rects_array[0];
    sprite_leg_rect = sprite_leg_rects_array[0];

    sprite_torso_rect_limit = playerRects->getTorsoMaxStandingIndex();//(int)(sizeof(sprite_rects_array)/ sizeof(SDL_Rect));
    sprite_legs_rect_limit = playerRects->getLegsMaxStandingIndex();

    torso_position_rect = playerRects->getTorsoPositionRect(leg_position_rect);

}


/**
 * @brief Realiza el ataque
 * @param who Es el objetivo del ataque
*/
void Soldier::attack(Soldier* who){
    if (this->_behavior)
        this->_behavior->performAttack(this, who);
    else
        std::cout << "No attack performed" << std::endl;
}

void Soldier::setAttackBehavior(IAttackBehavior* b){
    this->_behavior = b;
}


const std::string& Soldier::getName() const { return this->_name; };





void Soldier::move() {
    if(BaseObject::is_visible){
        if( event_control.key_right) {
            torso_position_rect.x+= movement_range;
            leg_position_rect.x+= movement_range;
            ground_bounds_array+= movement_range;
        }

        else if( event_control.key_left ) {
            torso_position_rect.x-= movement_range;
            leg_position_rect.x-= movement_range;
            ground_bounds_array-= movement_range;
        }
    }
};


void Soldier::paint() {
    if(BaseObject::is_visible){

        leg_position_rect.y = *ground_bounds_array + 30;
        torso_position_rect.y = *ground_bounds_array;

        if( event_control.direction == RIGHT ) {
            SDL_RenderCopy(renderer, object_texture, &sprite_leg_rect,   &leg_position_rect);
            SDL_RenderCopy(renderer, object_texture, &sprite_torso_rect, &torso_position_rect);
        }

        else if( event_control.direction == LEFT ) {
            torso_position_rect.x-= 5;
            SDL_RenderCopyEx(renderer, object_texture, &sprite_leg_rect,   &leg_position_rect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
            SDL_RenderCopyEx(renderer, object_texture, &sprite_torso_rect, &torso_position_rect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
            torso_position_rect.x+= 5;
        }
    }
};


void Soldier::update() {

    /** Legs animation */
    if( event_control.key_right || event_control.key_left ) {

        if(legs_index >= playerRects->getLegsMaxRunningIndex()) legs_index = 0;

        sprite_leg_rect = playerRects->getLegsRunningRect()[legs_index];
        legs_index++;

    }

    else {

        sprite_leg_rect = playerRects->getLegsStandRect()[0];
        legs_index = 0;

    }


    /** Torso animation */
    if(torso_index >= sprite_torso_rect_limit) torso_index = 0;

    sprite_torso_rect = sprite_torso_rects_array[torso_index];
    
    torso_index++;
    
};


void Soldier::setDirection() {
    std::cout << "Setting direction\n";
}