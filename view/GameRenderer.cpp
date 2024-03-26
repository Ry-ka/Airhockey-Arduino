#include "GameRenderer.h"
#include <iostream>
#include <windows.h>

GameRenderer::GameRenderer(const Game& game) : game(game) {}

void GameRenderer::render() const {
    clearScreen();
    clearGrid();
    std::cout << "Rendering game state." << std::endl;
    drawWallsAndGoals();
    drawPuck();
    drawPaddles();
    printGrid();
}

void GameRenderer::clearGrid() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = ' ';
        }
    }
}

void GameRenderer::drawPuck() const {
    auto puckPos = game.getPuck().getPosition();
    std::cout << "Puck position: X=" << puckPos.getX() << ", Y=" << puckPos.getY() << std::endl;

    int x = static_cast<int>(puckPos.getX()); // Assume position is already scaled
    int y = static_cast<int>(puckPos.getY());
    grid[y][x] = '@';
}

void GameRenderer::drawPaddles() const {
    // Assuming there's a method to get paddles' positions. Adjust as necessary.
    for (const auto& player : game.getPlayers()) {
        auto paddlePos = player.getPaddle().getPosition();
        int x = static_cast<int>(paddlePos.getX());
        int y = static_cast<int>(paddlePos.getY());
        grid[y][x] = '0'; // Represent the paddle
    }
}

void GameRenderer::drawWallsAndGoals() const {
    for (int x = 0; x < width; ++x) {
        grid[0][x] = x == width / 2 ? '=' : '-'; // Top wall with goal
        grid[height - 1][x] = x == width / 2 ? '=' : '-'; // Bottom wall with goal
    }
    for (int y = 0; y < height; ++y) {
        grid[y][0] = '|'; // Left wall
        grid[y][width - 1] = '|'; // Right wall
    }
}

void GameRenderer::printGrid() const {

    std::cout << "----- Frame -----" << std::endl; // Frame separator
    // Existing code...


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << grid[y][x];
        }
        std::cout << std::endl;
    }
}

void GameRenderer::clearScreen() const {
#ifdef _WIN32
    // Windows-specific screen clearing
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 }; // Home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
    }
#else
    // ANSI escape code for clearing the screen and moving the cursor to the top-left corner
    std::cout << "\033[2J\033[H";
#endif
}