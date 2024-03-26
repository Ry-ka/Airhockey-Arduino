#ifndef _PUCK_H
#define _PUCK_H

#include "../Position/Position.h"
#include "../Velocity/Velocity.h"

class Puck {
  public:
    Puck();

    //updates the position based on its velocty
    //updates 1 time unit at a time 
    void updatePosition();

    //getters and setters
    void setPosition(int x, int y);
    Position getPosition() const;
    void setVelocity(int dx, int dy);
    Velocity getVelocity() const;

  private:
    Position position;
    Velocity velocity;
};


#endif