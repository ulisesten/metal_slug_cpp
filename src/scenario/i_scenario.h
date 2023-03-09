#ifndef __ISCENARIO_H__
#define __ISCENARIO_H__

#include <SDL2/SDL.h>
#include "i_game_element.h"

class IScenario {
public:
    virtual void paint() = 0;
    virtual void actionPerformed() = 0;
    //virtual void keyPressed() = 0;
    //virtual void keyReleased() = 0;
};

#endif //__ISCENARIO_H__