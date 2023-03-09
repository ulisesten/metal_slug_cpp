#ifndef __I_EVENT_DRIVER_H__
#define __I_EVENT_DRIVER_H__

#include <SDL2/SDL.h>

typedef struct {
    bool key_right, key_left, key_up, key_down;
    int direction;
} EVENT_CONTROL;

class IEventDriver {

public:
    virtual bool handleEvents(SDL_Event* event, EVENT_CONTROL* event_control) = 0;
};

#endif //__I_EVENT_DRIVER_H__