// Position.h
#ifndef _POSITION_H
#define _POSITION_H
#include <iostream>
#include <string>

class Position {
public:
    Position(int x = 0, int y = 0); // Constructor
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    
    friend std::ostream& operator<<(std::ostream& os, const Position& position) {
        os << "(" << position.x << "," << position.y << ")";
        return os;
    }
private:
    int x;
    int y;
};

#endif
