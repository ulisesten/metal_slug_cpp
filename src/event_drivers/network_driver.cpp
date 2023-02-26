/// Ulisesten at 24 Feb 2023

#include "network_driver.h"


NetworkDriver::NetworkDriver(std::string server_url) {

    io.connect(server_url);
    io.socket()->on("event", [&](sio::event& ev){
        _event.type = SDL_KEYDOWN;
        //_event.type = SDL_USEREVENT;
        _event.user.code = 2;
        //_event.user.data1 = NULL;
        //_event.user.data2 = NULL;
        
        if( ev.get_message().get()->get_string() == "izquierda" ){
            _event.key.keysym.sym = SDLK_LEFT;
            
        }

        else if ( ev.get_message().get()->get_string() == "derecha" ) {
            _event.key.keysym.sym = SDLK_RIGHT;
        }
        //
        SDL_PushEvent(&_event);
        
    });

}

bool NetworkDriver::handleEvents(SDL_Event* event, int* direction){
    
        SDL_Log("network event type %d", event->type);
        switch(event->type){
            case SDL_QUIT: {
                return true;
            }

            case SDLK_f: {
                //toggleFullscreen();
                break;
            }

            case SDL_KEYDOWN: {
                SDL_Log("Network");
                if(event->user.code == 2) {
                    if(event->key.keysym.sym == SDLK_RIGHT){
            
                        *direction = 1;

                    } else if(event->key.keysym.sym == SDLK_LEFT){

                        *direction = 0;

                    }
                }
                break;
            }
        }
        
    return false;
}

int NetworkDriver::getEventType(){
    return 2;
}

