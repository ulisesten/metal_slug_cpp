#ifndef __BASE_OBJECT_H__
#define __BASE_OBJECT_H__

#include <SDL2/SDL.h>

class BaseObject {
protected:
    bool is_visible = true;
    static const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;

    int torso_index = 0;
    int legs_index = 0;

    int frame_index = -1;
    bool increment_sprite_index = true;

    /// SDL stuff
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* object_surface = nullptr;
    SDL_Texture* object_texture = nullptr;
    SDL_Event event;
    SDL_Rect* sprite_rects_array = nullptr;
    SDL_Rect sprite_rect;
    SDL_Rect rect;
    int sprite_rect_limit;
};

#endif // __BASE_OBJECT_H__