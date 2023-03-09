/** Created by Ulisesten at mar 8, 2023*/

#ifndef __UTIL_H__
#define __UTIL_H__

#include <fstream>
#include <sstream>
#include <vector>
#include <SDL2/SDL.h>

class Util {


public:
    void loadCoorsFromFile(const char* filepath, int* coors, uint32_t* size);

};

#endif //__UTIL_H__