//
// Created by ulises on 21/12/22.
//

#ifndef __GAME_ELEMENT_SET_H__
#define __GAME_ELEMENT_SET_H__

#include "i_game_element.h"
#include <vector>

using std::vector;

class GameElementSet: public IGameElement {
    std::vector<IGameElement*> elementsList;

public:
    void add(IGameElement* e);

    void move();
    void paint();
    void update();
    void setDirection();
    void keyPressed(SDL_Event event);
};

#endif //__GAME_ELEMENT_SET_H__
