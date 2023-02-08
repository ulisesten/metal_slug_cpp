#include "sdl/graphics.hpp"
#include <SDL2/SDL_surface.h>

Graphics::Graphics(){
    Graphics(502, 238);
}


/**
 * @brief Inicializa la parte gráfica
 * @param width es para el ancho de pantalla
 * @param height es ...
 * @return int x
*/
Graphics::Graphics(int width, int height){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0) {
        SDL_Log("Error SDL_Init %s", SDL_GetError());
        exit(-1);
    }

    window = SDL_CreateWindow("Metal Slug",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);


    if(!window) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        exit(-2);
    }


    //SDL_GetWindowSize(window, &maxWidth, &maxHeight);

    /*renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);


    if(!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s",
                     SDL_GetError());
        return -3;
    }*/



    if(IMG_Init(IMG_INIT_JPG) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                         "Couldn't init SDL_image: %s", SDL_GetError());
        exit(-4);
    }


    /*if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return -5;
    }*/
}


SDL_Window* Graphics::getWindow() {
    return this->window;
}

SDL_Surface* Graphics::getScreen() {
    return SDL_GetWindowSurface(this->window);
}

std::shared_ptr<Graphics> Graphics::getPtr(){
    return std::shared_ptr<Graphics>(new Graphics());
}

Graphics::~Graphics(){
    SDL_FreeSurface(this->screen);
    SDL_DestroyWindow(this->window);//Cerrando ventana
    IMG_Quit();
    SDL_Quit();//Cerrando SDL
    std::cout << "SDL Bye!!!\n";
}