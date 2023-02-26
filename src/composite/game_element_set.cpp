//
// Created by ulises on 21/12/22.
//


#include "game_element_set.h"


void GameElementSet::add(IGameElement* e) {
    elementsList.push_back(e);
}

void GameElementSet::move() {

    for (auto & el: elementsList){
        el->move();
    }

}

void GameElementSet::paint() {

    for (auto & el: elementsList){
        el->paint();
    }

}

void GameElementSet::update() {

    for (IGameElement* el: elementsList){
        el->update();
    }

}

bool GameElementSet::handleEvents(SDL_Event event) {

    for (IGameElement* el: elementsList){

        if(el->handleEvents(event)) return true;
        
    }

    return false;
}

void GameElementSet::keyPressed() {
    for (auto & el: elementsList){
        el->keyPressed();
    }
}

void GameElementSet::setDirection() {
    for (auto & el: elementsList){
        el->setDirection();
    }
}