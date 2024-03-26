#include "./model/Game/Game.h"
#include "./view/GameRenderer.h"
#include <iostream>
#include <thread>

int main() {
    // Initialize the game with table dimensions. Adjust these values as needed.
    int tableWidth = 16;
    int tableHeight = 16;
    Game game(tableWidth, tableHeight);

    // Initialize the game state (set up players, puck position, etc.)
    game.initializeGame();

    // Create a game renderer and pass the game to it for rendering
    GameRenderer renderer(game);

    // Main game loop
    while (!game.getIsGameOver()) {
        // Update game state: check collisions, update scores, move puck, etc.
        game.gameLoop();

        // Render the current state of the game
        renderer.render();

        // Here you could add a delay to control the frame rate, e.g., using std::this_thread::sleep_for
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        // Check for a condition to end the game (this could be inside gameLoop or here)
        // if (someCondition) {
        //     game.setIsGameOver(true);
        // }

        // For demonstration purposes, let's assume we have a mechanism to exit the loop.
        // In a real game, you would likely have conditions based on game logic (e.g., a score limit).
    }

    // Game over. You can add any game over logic here.
    std::cout << "Game Over!" << std::endl;

    return 0;
}
