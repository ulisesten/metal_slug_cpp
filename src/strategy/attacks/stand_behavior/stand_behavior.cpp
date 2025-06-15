#include "stand_behavior.h"



void StandBehavior::paint(SDL_Renderer* renderer, SDL_Texture* texture, int direction) {
    if( direction == RIGHT) {
        
        SDL_RenderCopy(renderer, texture, &sprite_leg_rect,   &leg_position_rect);
        SDL_RenderCopy(renderer, texture, &sprite_torso_rect, &torso_position_rect);

    } else if( direction == LEFT ) {

        torso_position_rect.x-= 5;

        SDL_RenderCopyEx(renderer, texture, &sprite_leg_rect,   &leg_position_rect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopyEx(renderer, texture, &sprite_torso_rect, &torso_position_rect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
        
        torso_position_rect.x+= 5;

    }
}



void StandBehavior::performAttack(Soldier* attacker, Soldier* who) {

    std::cout << attacker->getName() << " shoots to " << who->getName() << std::endl;

}