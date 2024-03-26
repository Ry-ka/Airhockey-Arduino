#ifndef _PADDLE_H
#define _PADDLE_H

#include "../Position/Position.h"
#include "../Velocity/Velocity.h"

class Paddle {
  public:
    Paddle(); //constructor
    Paddle(const Paddle& other); //copy constructor

    Paddle& operator=(const Paddle& other); //assignment overload

    //getters and setters
    Position getPosition() const;
    Velocity getVelocity() const;
    int getWidth() const;
    int getHeight() const;

    void setVelocity(Velocity velocity);
    void setPosition(Position position);
    void setWidth(int width);
    void setHeight(int height);

  private:
    Position position;
    Velocity velocity;
    int width;
    int height;
    
};

#endif