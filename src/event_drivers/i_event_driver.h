#ifndef __I_EVENT_DRIVER_H__
#define __I_EVENT_DRIVER_H__

#include <SDL2/SDL.h>

class IEventDriver {

public:
    virtual int getEventType() = 0;
    virtual bool handleEvents(SDL_Event* event, int* direction) = 0;
};

#endif //__I_EVENT_DRIVER_H__