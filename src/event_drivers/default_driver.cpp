#include "default_driver.h"

bool DefaultDriver::handleEvents(SDL_Event* event, EVENT_CONTROL* event_control){

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
                
                if(event->user.code != 2) {
                    if(event->key.keysym.sym == SDLK_RIGHT){
            
                        event_control->direction = 1;
                        event_control->key_right = true;

                    } else if(event->key.keysym.sym == SDLK_LEFT){

                        event_control->direction = 0;
                        event_control->key_left = true;

                    }
                }

                break;
            }

            case SDL_KEYUP: {

                if(event->user.code != 2) {
                    if(event->key.keysym.sym == SDLK_RIGHT){
            
                        event_control->key_right = false;

                    } else if(event->key.keysym.sym == SDLK_LEFT){

                        event_control->key_left = false;

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