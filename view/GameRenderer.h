#ifndef _GAMERENDERER_H
#define _GAMERENDERER_H

#include "../model/Game/Game.h"

class GameRenderer {
public:
    GameRenderer(const Game& game);

    void render() const;

private:
    const Game& game;
    static const int width = 16; // Grid width
    static const int height = 16; // Grid height

    mutable char grid[height][width]; // The rendering grid, marked mutable
    void clearScreen() const;
    void clearGrid() const;
    void drawPuck() const;
    void drawPaddles() const; // Now const, assuming it doesn't modify anything other than grid
    void drawWallsAndGoals() const; // Also marked as const
    void printGrid() const;
};

#endif // _GAMERENDERER_H
