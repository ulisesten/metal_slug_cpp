#ifndef __I_EVENT_DRIVER_H__
#define __I_EVENT_DRIVER_H__

#include <SDL2/SDL.h>

class IEventDriver {

public:
    virtual Uint32 getEvent() = 0;
};

#endif //__I_EVENT_DRIVER_H__