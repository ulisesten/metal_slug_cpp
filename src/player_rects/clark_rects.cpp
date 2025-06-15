#include "clark_rects.h"

ClarkRects::ClarkRects(){
    /// Standing Player rects
    torsoStandRect[0].x=10; torsoStandRect[0].y=5;
    torsoStandRect[0].w=35; torsoStandRect[0].h=35;
    torsoStandRect[1].x=43; torsoStandRect[1].y=5;
    torsoStandRect[1].w=35; torsoStandRect[1].h=35;
    torsoStandRect[2].x=76; torsoStandRect[2].y=5;
    torsoStandRect[2].w=35; torsoStandRect[2].h=35;
    torsoStandRect[3].x=109; torsoStandRect[3].y=5;
    torsoStandRect[3].w=35; torsoStandRect[3].h=35;

    legsStandRect[0].x=145; legsStandRect[0].y=20;
    legsStandRect[0].w=35; legsStandRect[0].h=34;

    /// Running Player Rects
    legsRunningRect[0].x=13;  legsRunningRect[0].y=434;
    legsRunningRect[0].w=34;  legsRunningRect[0].h=34;
    legsRunningRect[1].x=57;  legsRunningRect[1].y=434;
    legsRunningRect[1].w=34;  legsRunningRect[1].h=34;         
    legsRunningRect[2].x=101; legsRunningRect[2].y=434;
    legsRunningRect[2].w=34;  legsRunningRect[2].h=34;
    legsRunningRect[3].x=133; legsRunningRect[3].y=434;
    legsRunningRect[3].w=34;  legsRunningRect[3].h=34;
    legsRunningRect[4].x=167; legsRunningRect[4].y=434;
    legsRunningRect[4].w=34;  legsRunningRect[4].h=34;
    legsRunningRect[5].x=201; legsRunningRect[5].y=434;
    legsRunningRect[5].w=34;  legsRunningRect[5].h=34;


    torsoShootingRect[0].x=19;   torsoShootingRect[0].y=50;
    torsoShootingRect[0].w=55;   torsoShootingRect[0].h=30;
    torsoShootingRect[1].x=85;   torsoShootingRect[1].y=50;
    torsoShootingRect[1].w=55;   torsoShootingRect[1].h=30;
    torsoShootingRect[2].x=153;  torsoShootingRect[2].y=50;
    torsoShootingRect[2].w=57;   torsoShootingRect[2].h=30;
    torsoShootingRect[3].x=206;  torsoShootingRect[3].y=50;
    torsoShootingRect[3].w=37;   torsoShootingRect[3].h=30;
    torsoShootingRect[4].x=206;  torsoShootingRect[4].y=50;
    torsoShootingRect[4].w=50;   torsoShootingRect[4].h=30;
    torsoShootingRect[5].x=303;  torsoShootingRect[5].y=50;
    torsoShootingRect[5].w=45;   torsoShootingRect[5].h=30;
    torsoShootingRect[6].x=352;  torsoShootingRect[6].y=50;
    torsoShootingRect[6].w=45;   torsoShootingRect[6].h=30;
    torsoShootingRect[7].x=401;  torsoShootingRect[7].y=48;
    torsoShootingRect[7].w=40;   torsoShootingRect[7].h=30;
    torsoShootingRect[8].x=449;  torsoShootingRect[8].y=49;
    torsoShootingRect[8].w=35;   torsoShootingRect[8].h=30;
    torsoShootingRect[9].x=498;  torsoShootingRect[9].y=50;
    torsoShootingRect[9].w=35;   torsoShootingRect[9].h=30;

    torso_position_rect = {3, sprite_compensation, 0, 0};

}

SDL_Rect* ClarkRects::getTorsoStandRect(){
    return torsoStandRect;
};

SDL_Rect* ClarkRects::getLegsStandRect(){
    return legsStandRect;
};

SDL_Rect* ClarkRects::getTorsoRunningRect(){
    /// By now torsoRunningRect is the same as torsoStandRect and is commentarized in the header
    return torsoStandRect;
};

SDL_Rect* ClarkRects::getLegsRunningRect(){
    return legsRunningRect;
};

SDL_Rect* ClarkRects::getTorsoShootingRect(){
    return torsoShootingRect;
}

SDL_Rect ClarkRects::getTorsoPositionRect(SDL_Rect src){
    src.x += torso_position_rect.x;
    src.y -= torso_position_rect.y;
    return src;
};

int ClarkRects::getTorsoMaxStandingIndex(){
    return 4;
}

int ClarkRects::getLegsMaxStandingIndex(){
    return 1;
}

int ClarkRects::getTorsoMaxRunningIndex(){
    return 4;
}

int ClarkRects::getLegsMaxRunningIndex(){
    return 6;
}

int ClarkRects::getTorsoMaxShootingIndex(){
    return 4;
}