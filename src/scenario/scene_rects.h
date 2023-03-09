#ifndef __SCENE_RECTS_H__
#define __SCENE_RECTS_H__

#include <SDL2/SDL.h>
#include "util.h"

class SceneRects {
    SDL_Rect position_rect1 = {0,  15, 502, 260};
    SDL_Rect position_rect2 = {0,  15, 502, 260};
    SDL_Rect position_rect3 = {0, -50, 502, 260};

    SDL_Rect frame_rect1 = { 10, 0,   502, 260 };
    SDL_Rect frame_rect2 = { 10, 560, 270, 300 };
    SDL_Rect frame_rect3 = { 10, 408, 250, 130 };

    Util* util;
    int* ground_bounds_array;

public:

    SceneRects();

    SceneRects(
        SDL_Rect position_rect1,
        SDL_Rect position_rect2,
        SDL_Rect position_rect3,
        SDL_Rect frame_rect1,
        SDL_Rect frame_rect2,
        SDL_Rect frame_rect3
    );

    SDL_Rect* getPositionRect1();
    SDL_Rect* getPositionRect2();
    SDL_Rect* getPositionRect3();
    SDL_Rect* getFrameRect1();
    SDL_Rect* getFrameRect2();
    SDL_Rect* getFrameRect3();

    void getGroundBoundsArray(int* array, uint32_t* size);

};

#endif //__SCENE_RECTS_H__