#include "scene_rects.h"

SceneRects::SceneRects(){

}

SceneRects::SceneRects(
    SDL_Rect position_rect1,
    SDL_Rect position_rect2,
    SDL_Rect position_rect3,
    SDL_Rect frame_rect1,
    SDL_Rect frame_rect2,
    SDL_Rect frame_rect3
){

    this->position_rect1 = position_rect1;
    this->position_rect2 = position_rect2;
    this->position_rect3 = position_rect3;
    this->frame_rect1 = frame_rect1;
    this->frame_rect2 = frame_rect2;
    this->frame_rect3 = frame_rect3;
    util = new Util();

    //uint32_t m_size;
    //util->loadCoorsFromFile("data/scene1-ground.txt", nullptr, &m_size);
    //ground_bounds_array = new int[m_size];
    //util->loadCoorsFromFile("data/scene1-ground.txt", ground_bounds_array, &m_size);

}

SDL_Rect* SceneRects::getPositionRect1(){
    return &position_rect1;
};

SDL_Rect* SceneRects::getPositionRect2(){
    return &position_rect2;
};

SDL_Rect* SceneRects::getPositionRect3(){
    return &position_rect3;
};

SDL_Rect* SceneRects::getFrameRect1(){
    return &frame_rect1;
};

SDL_Rect* SceneRects::getFrameRect2(){
    return &frame_rect2;
};

SDL_Rect* SceneRects::getFrameRect3(){
    return &frame_rect3;
};

void SceneRects::getGroundBoundsArray(int* array, uint32_t* size) {
    util->loadCoorsFromFile("data/scene1-ground.txt", array, size);
}
