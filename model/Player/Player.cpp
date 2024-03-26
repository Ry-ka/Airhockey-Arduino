#include "Player.h"

Player::Player(int playerNumber) : playerNumber(playerNumber), score(0), paddle(Paddle()) {}

void Player::updateScore(int points) {
  score += points;
}

int Player::getPlayerNumber() const {
  return playerNumber;
}

int Player::getScore() const {
  return score;
}

Paddle Player::getPaddle() const {
  return paddle;
}

void Player::setPlayerNumber(int playerNumber) {
  this->playerNumber = playerNumber;
}

void Player::setScore(int score) {
  this->score = score;
}

void Player::setPaddle(const Paddle& paddle) {
  this->paddle = paddle;
}
