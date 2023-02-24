#ifndef __I_PLAYER_RECTS_H__
#define __I_PLAYER_RECTS_H__

class IPlayerRects {
public:
    virtual SDL_Rect* getTorsoStandRect() = 0;
    virtual SDL_Rect* getLegsStandRect() = 0;
    virtual SDL_Rect* getTorsoRunningRect() = 0;
    virtual SDL_Rect* getLegsRunningRect() = 0;

    /// @brief This takes a position rect and return a new one with the correct measures, in function of the torso sprite correct position
    /// @param src The original rect position
    /// @return The adjusted rect position
    virtual SDL_Rect getTorsoPositionRect(SDL_Rect src) = 0;

    virtual int getTorsoMaxStandingIndex() = 0;
    virtual int getLegsMaxStandingIndex() = 0;
    virtual int getTorsoMaxRunningIndex() = 0;
    virtual int getLegsMaxRunningIndex() = 0;
};

#endif