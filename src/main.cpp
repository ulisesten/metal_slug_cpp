/// Ulisesten

#include <iostream>
#include <SDL2/SDL_surface.h>
#include <zlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_image.h>
#include "soldier_class.h"
#include "player_class.h"
#include "scenario.h"

#include "clark_rects.h"
#include "game_element_set.h"


int main(){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int maxWidth = 502, maxHeight = 260;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0) {
        SDL_Log("Error SDL_Init %s", SDL_GetError());
        exit(-1);
    }

    window = SDL_CreateWindow("Metal Slug",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,502, 260,SDL_WINDOW_OPENGL);


    if(!window) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        exit(-2);
    }

    
    //SDL_GetWindowSize(window, &maxWidth, &maxHeight);


    if(IMG_Init(IMG_INIT_JPG) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                        "Couldn't init SDL_image: %s", SDL_GetError());
        exit(-4);
    }


    /*if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return -5;
    }*/

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s",
                     SDL_GetError());
        return -3;
    }


    /*
    Soldier soldier("Gun Soldier");
    KnifeAttack knife;
    GunAttack gunAttack;
    player.setAttackBehavior(&knife);
    soldier.setAttackBehavior(&gunAttack);
    soldier.attack(&player);
    player.attack(&soldier);
    */

    SDL_Rect player1PositionRect = {100, 100, 50, 50};
    
    IPlayerRects* mPlayerRects = new ClarkRects();
    IGameElement* player = new Player("Clark", "assets/clark.png", renderer, mPlayerRects, player1PositionRect);
    SceneRects m_sceneRects;

    GameElementSet* gameElementSet = new GameElementSet();
    gameElementSet->add(player);
    
    Scenario scenario( 
        renderer, 
        maxWidth, 
        maxHeight, 
        (IGameElement*)gameElementSet, 
        "assets/mision1.png", 
        &m_sceneRects
    );

    scenario.actionPerformed();

    return 0;
}