#include "Velocity.h"

Velocity::Velocity(int dx, int dy): dx(dx), dy(dy) {}

int Velocity::getDx() {
  return dx;
}

int Velocity::getDy() {
  return dy;
}

void Velocity::setDx(int dx) {
  this->dx = dx;
}

void Velocity::setDy(int dy) {
  this->dy = dy;
}

std::ostream& operator<<(std::ostream& os, const Velocity& v) {
  os << "(" << v.dx << "," << v.dy << ")";
  return os;
}