/// Ulisesten at 24 Feb 2023

#include "network_driver.h"


NetworkDriver::NetworkDriver(){
    io.connect("http://127.0.0.1:8080");
    io.socket()->on("event", [&](sio::event& ev){
        //SDL_Log( ev.get_message().get()->get_string().c_str() );
        
        _event.type = SDL_KEYDOWN;
        
        if( ev.get_message().get()->get_string() == "izquierda" ){
            _event.key.keysym.sym = SDLK_LEFT;
            
        }

        else if ( ev.get_message().get()->get_string() == "derecha" ) {
            _event.key.keysym.sym = SDLK_RIGHT;
        }

        SDL_PushEvent(&_event);
    });
}

bool NetworkDriver::getEvent(SDL_Event* event){

    if (SDL_PollEvent(event)){
        return true;
    }

    return false;
}

