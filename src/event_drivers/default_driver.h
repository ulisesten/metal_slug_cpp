#ifndef __DEFAULT_DRIVER_H__
#define __DEFAULT_DRIVER_H__

#include "i_event_driver.h"

class DefaultDriver: public IEventDriver {
public:
    Uint32 getEvent() override;
};

#endif //__DEFAULT_DRIVER_H__