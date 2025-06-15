#include "util.h"


void Util::loadCoorsFromFile(const char* filepath, int* coors, uint32_t* size) {
    std::ifstream file;
    int line_counter = -1;
    //uint32_t size;
    //int* result_array;

    file.open(filepath, std::ios::in);

    if( !file.is_open() ) {

        SDL_Log("Error loading file %s", filepath);

    } else {

        std::string line;

        while( getline(file, line, '\n') ) {

            line_counter++;

            if(line_counter == 0) {

                *size = atoi(line.c_str()) + 1;
                continue;
                
            }

            if(!coors) break;

            *coors = atoi(line.c_str());

            coors++;

        }

    }

}



void Util::toggleFullscreen(SDL_Window* window) {

    if(!window) SDL_Log("No valid window provided");
    
    Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;

    bool IsFullscreen = SDL_GetWindowFlags(window) & FullscreenFlag;
    SDL_SetWindowFullscreen(window, IsFullscreen ? 0 : FullscreenFlag);
    SDL_ShowCursor(IsFullscreen);

}