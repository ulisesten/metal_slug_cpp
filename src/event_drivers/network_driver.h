#ifndef __NETWORK_DRIVER_H__
#define __NETWORK_DRIVER_H__

#include "i_event_driver.h"
#include "sio_client.h"

class NetworkDriver: public IEventDriver {
    SDL_Event network_event;
    sio::client io;
    SDL_Event _event;

public:
    NetworkDriver(std::string server_url);

    int getEventType();
    bool handleEvents(SDL_Event* event, int* direction) override;
};

#endif //__NETWORK_DRIVER_H__