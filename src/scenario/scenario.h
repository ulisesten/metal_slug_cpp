//
// Created by ulises on 15/12/22.
//

#ifndef __SCENARIO_H__
#define __SCENARIO_H__

#include "i_scenario.h"
#include <scene_rects.h>
//#include "SDL.h"
//#include "mouse.h"

class Scenario: public IScenario {

    SDL_Surface* surface = nullptr;
    SDL_Renderer* renderer = nullptr;
    int maxWidth, maxHeight;
    SDL_Event event;


    IGameElement* gameElement = nullptr;
    bool quit = false;
    int fps = 60;
    int frameDelay = 1000/fps;
    Uint32 frameStart;
    unsigned long frameTime;
    unsigned int current = 0;
    unsigned int past = 0;
    unsigned int current_position = 0;
    unsigned int past_position = 0;

    // need to abstract this rects
    SDL_Rect rect;

    SceneRects* sceneRects;

    SDL_Texture* texture = nullptr;

    int* ground_bounds_array;


public:
    Scenario(SDL_Renderer* renderer, int maxWidth, int maxHeight, IGameElement* gameElement, const char* sceneBackground, SceneRects* sceneRects);

    void paint();

    void actionPerformed();

    int getWidth() const {
        return maxWidth;
    }

    int getHeight() const {
        return maxHeight;
    }
};

#endif //__SCENARIO_H__