#include "Game.h"
#include <iostream>

Game::Game(int tableWidth, int tableHeight)
    : tableWidth(tableWidth), tableHeight(tableHeight), isGameOver(false) {}

void Game::initializeGame() {
    // Initialize the puck position and velocity
    puck.setPosition(tableWidth / 2, tableHeight / 2);
    puck.setVelocity(1, -1); // Example starting velocity

    // Initialize players and their paddles
    // Example for two players
    players.push_back(Player(1));
    players.push_back(Player(2));
    // Set paddles' positions, velocities, etc., as needed
}

void Game::gameLoop() {
    std::cout << "Game loop executed." << std::endl;
    checkCollisions();
    updateScores();
    // Update positions
    puck.updatePosition();
    for (auto& player : players) {
        // Update player paddle position if needed
    }

    // Check for game over condition
    // Example: You can check here if the game should end based on your game's logic
    // and set isGameOver = true accordingly.
    // For example: if (score >= winningScore) isGameOver = true;
}


void Game::checkCollisions() {
    // Check collisions between the puck and paddles
    for (auto& player : players) {
        if (CollisionDetection::checkPaddlePuckCollision(player.getPaddle(), puck)) {
            CollisionDetection::respondToPaddlePuckCollision(puck, player.getPaddle());
            // Update scores or game state as needed
        }
    }

    // Check and respond to wall collisions
    CollisionDetection::checkAndRespondToWallCollisions(puck, tableWidth, tableHeight);
}

void Game::updateScores() {
    // Example: Increment score if the puck hits a goal area
    // This method would likely be more complex, depending on game rules
}


// Additional methods as needed, such as for handling user input or AI for moving paddles

// Getters
int Game::getTableWidth() const {
    return tableWidth;
}

int Game::getTableHeight() const {
    return tableHeight;
}

const Puck& Game::getPuck() const {
    return puck;
}

const std::vector<Player>& Game::getPlayers() const {
    return players;
}

bool Game::getIsGameOver() const {
    return isGameOver;
}

// Setters
void Game::setTableWidth(int width) {
    tableWidth = width;
}

void Game::setTableHeight(int height) {
    tableHeight = height;
}

void Game::setPuck(const Puck& newPuck) {
    puck = newPuck;
}

void Game::addPlayer(const Player& player) {
    players.push_back(player);
}

void Game::setIsGameOver(bool status) {
    isGameOver = status;
}
