#ifndef _PLAYER_H
#define _PLAYER_H

#include "../Paddle/Paddle.h"

class Player {
  public:
    Player(int playerNumber);
    void updateScore(int points);

    int getPlayerNumber() const;
    int getScore() const;
    Paddle getPaddle() const;
    void setPlayerNumber(int playerNumber);
    void setScore(int score);
    void setPaddle(const Paddle& paddle);

  private:
    int playerNumber;
    int score;
    Paddle paddle;
};

#endif