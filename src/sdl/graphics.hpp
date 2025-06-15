#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <iostream>
#include <SDL2/SDL_surface.h>
#include <zlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_image.h>
#include <memory>

class Graphics:public std::enable_shared_from_this<Graphics> {
    //shared_ptr<SDL_Surface*> pSurface;
    SDL_Window*    window  =  NULL;//Ventana
    SDL_Surface*   screen  =  NULL;//Pantalla

    public:
        Graphics();

        Graphics(int width, int height);

        virtual SDL_Window* getWindow();

        virtual SDL_Surface* getScreen();

        static std::shared_ptr<Graphics> getPtr();

        ~Graphics();
};


#endif