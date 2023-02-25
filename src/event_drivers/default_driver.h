#ifndef __DEFAULT_DRIVER_H__
#define __DEFAULT_DRIVER_H__

#include "i_event_driver.h"

class DefaultDriver: public IEventDriver {
    SDL_Event default_event;
public:
    bool getEvent(SDL_Event* event) override;
};

#endif //__DEFAULT_DRIVER_H__