#ifndef __CLARK_RECTS_H__
#define __CLARK_RECTS_H__

#include <SDL2/SDL.h>
#include "i_player_rects.h"

class ClarkRects: public IPlayerRects {

    /// @brief animates the sprite when player its just standing
    SDL_Rect torsoStandRect[4];
    SDL_Rect legsStandRect[1];
    //SDL_Rect torsoRunningRect[4];
    SDL_Rect legsRunningRect[6];

public:
    ClarkRects();
    SDL_Rect* getTorsoStandRect();
    SDL_Rect* getLegsStandRect();
    SDL_Rect* getTorsoRunningRect();
    SDL_Rect* getLegsRunningRect();

    int getTorsoMaxStandingIndex();
    int getLegsMaxStandingIndex();
    int getTorsoMaxRunningIndex();
    int getLegsMaxRunningIndex();

};

#endif //__CLARK_RECTS_H__