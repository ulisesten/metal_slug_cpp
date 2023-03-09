#ifndef __DEFAULT_DRIVER_H__
#define __DEFAULT_DRIVER_H__

#include "i_event_driver.h"

class DefaultDriver: public IEventDriver {

public:

    bool handleEvents(SDL_Event* event, EVENT_CONTROL* event_control) override;
    
};

#endif //__DEFAULT_DRIVER_H__