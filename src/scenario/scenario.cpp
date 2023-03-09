//
// Created by ulises on 15/12/22.
//

#include "scenario.h"
#include <SDL2/SDL_image.h>

Scenario::Scenario(SDL_Renderer* renderer, int maxWidth, int maxHeight, IGameElement* gameElement, const char* sceneBackground, SceneRects* sceneRects){
    this->renderer = renderer;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;

    this->sceneRects = sceneRects;

    surface = IMG_Load(sceneBackground);
    if(!surface) SDL_LogError (SDL_LOG_CATEGORY_APPLICATION,
    "Couldn't load surface: %s", IMG_GetError());

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture) SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
    "Couldn't load texture: %s", SDL_GetError());

    rect.x = 0;
    rect.y = 0;
    rect.w = maxWidth;
    rect.h = maxHeight;

    /// Mouse declaration
    this->gameElement = gameElement;
    uint32_t m_size;
    sceneRects->getGroundBoundsArray(nullptr, &m_size);
    ground_bounds_array = new int[m_size];
    sceneRects->getGroundBoundsArray(this->ground_bounds_array, &m_size);

    /*while(*this->ground_bounds_array) {

        SDL_Log("coor: %d", *(this)->ground_bounds_array);
        this->ground_bounds_array++;

    }*/

    gameElement->setGroundBoundsArray(this->ground_bounds_array);

    SDL_FreeSurface(surface);

}

void Scenario::paint() {

    SDL_RenderCopy(renderer, texture, sceneRects->getFrameRect3(), sceneRects->getPositionRect3());
    SDL_RenderCopy(renderer, texture, sceneRects->getFrameRect2(), sceneRects->getPositionRect2());
    SDL_RenderCopy(renderer, texture, sceneRects->getFrameRect1(), sceneRects->getPositionRect1());

    gameElement->paint();

}

void Scenario::actionPerformed() {

    while (!quit) {

        frameStart = SDL_GetTicks64();

        if(SDL_PollEvent(&event))
            quit = gameElement->handleEvents(event);

        SDL_RenderClear(renderer);

        this->paint();

        current = SDL_GetTicks64();
        current_position = SDL_GetTicks64();

        if (current > past + 130) {
            past = current;
            gameElement->update();
        }

        if (current_position > past_position + 10) {
            past_position = current_position;
            gameElement->move();
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks64() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

}