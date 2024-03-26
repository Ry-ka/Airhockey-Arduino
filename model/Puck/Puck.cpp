#include "Puck.h"

Puck::Puck() : position(), velocity() {}

void Puck::updatePosition() {
  position.setX(position.getX() + velocity.getDx());
  position.setY(position.getY() + velocity.getDy());
}

void Puck::setPosition(int x, int y) {
  position.setX(x);
  position.setY(y);
}

Position Puck::getPosition() const {
  return position;
}

void Puck::setVelocity(int dx, int dy) {
  velocity.setDx(dx);
  velocity.setDy(dy);
}

Velocity Puck::getVelocity() const {
  return velocity;
}