#ifndef _VELOCITY_H
#define _VELOCITY_H

#include <iostream>
#include <string>

class Velocity {
  public:
    Velocity(int dx = 0, int dy = 0);
    int getDx();
    int getDy();
    void setDx(int dx = 0);
    void setDy(int dy = 0);
    
    friend std::ostream& operator<<(std::ostream& os, const Velocity& v);

  private:
    int dx;
    int dy;

};

#endif