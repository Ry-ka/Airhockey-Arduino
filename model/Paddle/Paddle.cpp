#include "Paddle.h"

Paddle::Paddle() : position(), velocity(), width(0), height(0)  {}
Paddle::Paddle(const Paddle& other) : position(other.position), velocity(other.velocity), width(other.width), height(other.height) {}

Paddle& Paddle::operator=(const Paddle& other) {
  if (this != &other) { // Prevent self-assignment
    width = other.width;
    height = other.height;
    position = other.position;
    velocity = other.velocity;
  }
  return *this;
}

//getters and setters
Position Paddle::getPosition() const {
  return position;
}

Velocity Paddle::getVelocity() const {
  return velocity;
}

int Paddle::getWidth() const {
  return width;
}

int Paddle::getHeight() const {
  return height;
}

void Paddle::setVelocity(Velocity velocity) {
  this->velocity = velocity;
}

void Paddle::setPosition(Position position){
  this->position = position;
}
void Paddle::setWidth(int width){
  this->width = width;
}

void Paddle::setHeight(int height){
  this->height = height;
}