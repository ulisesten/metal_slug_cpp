#include "soldier_class.h"
#include <iostream>


Soldier::Soldier(std::string name, const char* sprite_path, SDL_Renderer* renderer, IPlayerRects* player_rects): _name(name), _behavior(0), _sprite_path(sprite_path) {
    
    this->renderer = renderer;
    object_surface = IMG_Load(sprite_path);

    if(!object_surface)
        SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "Couldn't load surface: %s", IMG_GetError());

    this->object_texture = SDL_CreateTextureFromSurface(this->renderer, this->object_surface);

    if(!this->object_texture)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Couldn't load texture: %s", SDL_GetError());


    SDL_FreeSurface(object_surface);

    sprite_rects_array = player_rects->getTorsoStandRect();
    sprite_rect = sprite_rects_array[0];
    sprite_rect_limit = 4;//sizeof(sprite_rects_array)/ sizeof(SDL_Rect);
    rect = {100,100, 50, 50};
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
    std::cout << "moving to ";

    if(this->direction == RIGHT){
        std::cout << "the right\n";
    } else if( this->direction == LEFT ){
        std::cout << "the left\n";
    }
};


void Soldier::paint() {
    if(BaseObject::is_visible){
        SDL_RenderCopy(renderer, object_texture, &sprite_rect, &rect);

    }
};


void Soldier::update() {
    //std::cout << "updating\n";
    if(torso_index >= sprite_rect_limit) torso_index = 0;

    sprite_rect = sprite_rects_array[torso_index];
    
    torso_index++;
};


void Soldier::setDirection() {
    std::cout << "Setting direction\n";
};


