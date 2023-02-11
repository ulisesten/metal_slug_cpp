//
// Created by ulises on 15/12/22.
//

#include "scenario.h"
#include <SDL2/SDL_image.h>

Scenario::Scenario(SDL_Renderer* renderer, int maxWidth, int maxHeight, IGameElement* gameElement){
    this->renderer = renderer;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;

    surface = IMG_Load("cheese_bk.jpg");
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
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void Scenario::actionPerformed() {

    while (!quit) {

        frameStart = SDL_GetTicks();

        this->handleEvents();

        if (event.type == SDL_QUIT) {
            quit = 1;
        }

        //Code here
        SDL_RenderClear(renderer);

        this->paint();
        gameElement->paint();
        gameElement->setDirection();

        current = SDL_GetTicks();
        current_position = SDL_GetTicks();

        if (current > past + 80) {
            past = current;
            gameElement->update();
        }

        if (current_position > past_position + 20) {
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

void Scenario::handleEvents(){
    if (SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_FINGERDOWN: {
                keyPressed(event);
                break;
            }
        }
    }
}

void Scenario::keyPressed(SDL_Event _event){
    gameElement->keyPressed(_event);
}

void Scenario::keyReleased(SDL_Event){

}