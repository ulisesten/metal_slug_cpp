#include <iostream>
#include <memory>

#include "sdl/graphics.hpp"

#include "strategy/soldier_class.hpp"
#include "strategy/player_class.hpp"

using std::shared_ptr;

int main(){
    
    //shared_ptr<SDL_Surface* pSurface;
    //shared_ptr<Graphics> graphics = Graphics::getPtr();
    SDL_Window* window = nullptr;
    SDL_Surface* screen = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0) {
        SDL_Log("Error SDL_Init %s", SDL_GetError());
        exit(-1);
    }

    window = SDL_CreateWindow("Metal Slug",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_OPENGL);


    if(!window) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        exit(-2);
    }

    screen = SDL_GetWindowSurface(window);
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

    SDL_Surface* surface = IMG_Load("assets/superbad.jpg");
    //pSurface = IMG_Load("assets/superbad.jpg");

    if( surface == NULL ) {
        std::cout << "Unable to load image %s! SDL Error: %s\n" << "02_getting_an_image_on_the_screen/hello_world.bmp" << SDL_GetError() << std::endl;
    }

    SDL_BlitSurface( surface, NULL, screen, NULL );

    SDL_UpdateWindowSurface( window );
    SDL_Delay(1000);
    SDL_FreeSurface(surface);

    /*
    Player player("Marco");
    Soldier soldier("Gun Soldier");

    KnifeAttack knife;
    GunAttack gunAttack;
    
    player.setAttackBehavior(&knife);
    soldier.setAttackBehavior(&gunAttack);

    soldier.attack(&player);
    player.attack(&soldier);
    */

    return 0;
}