#include "default_driver.h"

bool  DefaultDriver::getEvent(SDL_Event* event){
    if (SDL_PollEvent(event)){
        return true;
    }

    return false;
}