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

    for (auto & el: elementsList){
        el->update();
    }

}

void GameElementSet::keyPressed(SDL_Event event) {
    for (auto & el: elementsList){
        el->keyPressed(event);
    }
}

void GameElementSet::setDirection() {
    for (auto & el: elementsList){
        el->setDirection();
    }
}