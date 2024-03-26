#ifndef _GAME_H
#define _GAME_H

#include "../Paddle/Paddle.h"
#include "../Puck/Puck.h"
#include "../Player/Player.h"
#include "../Collision/CollisionDetection.h"
#include <vector>

class Game {
public:
    Game(int tableWidth, int tableHeight);

    void initializeGame();
    void gameLoop();
    void checkCollisions();
    void updateScores();

    // Getters
    int getTableWidth() const;
    int getTableHeight() const;
    const Puck& getPuck() const;
    const std::vector<Player>& getPlayers() const;
    bool getIsGameOver() const;

    // Setters
    void setTableWidth(int width);
    void setTableHeight(int height);
    void setPuck(const Puck& newPuck);
    void addPlayer(const Player& player);
    void setIsGameOver(bool status);

private:
    int tableWidth;
    int tableHeight;
    Puck puck;
    std::vector<Player> players;
    bool isGameOver;
};

#endif // _GAME_H
