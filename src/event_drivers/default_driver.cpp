#include "default_driver.h"

bool DefaultDriver::handleEvents(SDL_Event* event, int* direction){
        SDL_Log("event type %d", event->type);
        switch(event->type){
            case SDL_QUIT: {
                //SDL_Log("Quiting from player_class");
                return true;
            }

            case SDLK_f: {
                //toggleFullscreen();
                break;
            }

            case SDL_KEYDOWN: {
                SDL_Log("Local");
                if(event->user.code != 2) {
                    if(event->key.keysym.sym == SDLK_RIGHT){
            
                        *direction = 1;

                    } else if(event->key.keysym.sym == SDLK_LEFT){

                        *direction = 0;

                    }
                }

                break;
            }
        }
        
    //}
    return false;
}

int DefaultDriver::getEventType(){
    return 1;
}