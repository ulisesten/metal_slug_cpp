#ifndef __NETWORK_DRIVER_H__
#define __NETWORK_DRIVER_H__

#include "i_event_driver.h"

class NetworkDriver: public IEventDriver {
    SDL_Event network_event;
public:
    bool getEvent(SDL_Event* event);
    /*
        sio.on("event", [nullptr](cb){
            SDL_PushEvent(event);
        });
    */
};

#endif //__NETWORK_DRIVER_H__