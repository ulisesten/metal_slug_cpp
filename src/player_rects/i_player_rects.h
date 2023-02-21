#ifndef __I_PLAYER_RECTS_H__
#define __I_PLAYER_RECTS_H__

class IPlayerRects {
public:
    virtual SDL_Rect* getTorsoStandRect() = 0;
    virtual SDL_Rect* getLegsStandRect() = 0;
    virtual SDL_Rect* getTorsoRunningRect() = 0;
    virtual SDL_Rect* getLegsRunningRect() = 0;

    virtual int getTorsoMaxStandingIndex() = 0;
    virtual int getLegsMaxStandingIndex() = 0;
    virtual int getTorsoMaxRunningIndex() = 0;
    virtual int getLegsMaxRunningIndex() = 0;
};

#endif