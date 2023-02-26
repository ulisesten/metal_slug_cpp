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

        if (current > past + 170) {
            past = current;
            gameElement->update();
        }

        if (current_position > past_position + 20) {
            past_position = current_position;
            //gameElement->move();
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks64() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

}

void toggleFullscreen(SDL_Window* window) {

    Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;

    bool IsFullscreen = SDL_GetWindowFlags(window) & FullscreenFlag;
    SDL_SetWindowFullscreen(window, IsFullscreen ? 0 : FullscreenFlag);
    SDL_ShowCursor(IsFullscreen);

}