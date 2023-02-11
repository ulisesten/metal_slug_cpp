//
// Created by ulises on 15/12/22.
//

#ifndef __SCENARIO_H__
#define __SCENARIO_H__

#include "i_scenario.h"
//#include "SDL.h"
//#include "mouse.h"

class Scenario: public IScenario {
    SDL_Surface* surface = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Rect rect{};
    int maxWidth, maxHeight;
    SDL_Event event;
    //Mouse* mouse = nullptr;
    IGameElement* gameElement = nullptr;
    int quit = 0;
    int fps = 60;
    int frameDelay = 1000/fps;
    Uint32 frameStart;
    unsigned long frameTime;
    unsigned int current = 0;
    unsigned int past = 0;
    unsigned int current_position = 0;
    unsigned int past_position = 0;


public:
    Scenario(SDL_Renderer* renderer, int maxWidth, int maxHeight, IGameElement* gameElement);

    void paint();

    void actionPerformed();
    void handleEvents();
    void keyPressed(SDL_Event);
    void keyReleased(SDL_Event);

    int getWidth() const {
        return maxWidth;
    }

    int getHeight() const {
        return maxHeight;
    }
};

#endif //__SCENARIO_H__