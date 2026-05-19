#include <../include/Game.h>
#include <iostream>
#include <vector>

void Game::runSetup() {
    ai.setupGrid();
    printBoard(ai.getMyGrid());
    static const int SHIP_SIZES[] = {5, 4, 3, 3, 2};
    static const int SHIP_COUNT = 5;
    for (int i = 0; i < SHIP_COUNT; ++i) {
        int size = SHIP_SIZES[i];
        bool placed = false;
        while (!placed) {
            int startX, startY, endX, endY;
            int shipLenght = 0;
            int horizontal = 0;
            std::cout << "Current ship's lenght: " << size << "\n";
            std::cout << "Please enter ship's start coordinates (e.g. 0 0): ";
            std::cin >> startX >> startY;
            std::cout << "Please enter ship's end coordinates (e.g. 5 0): ";
            std::cin >> endX >> endY;
            if ((startX < 0)||(startY < 0)||(endX < 0)||(endY < 0)) {
                std::cout << "No negative coordinates allowed.\n";
                continue;
            }
            shipLenght = abs(startX - endX) > abs(startY - endY) ? abs(startX - endX) : abs(startY - endY);
            if (shipLenght > size-1) {
                std::cout << "Ship too big.\n";
                continue;
            }
            if (shipLenght < size-1) {
                std::cout << "Ship too small\n";
                continue;
            }
            std::cout << endX;
            Ship ship(Coordinates(startX, startY), Coordinates(endX, endY));
            placed = human.placeShip(ship);
            if (!placed) {
                std::cout << "Can't place ship here.\n";
            }
        }
        std::cout << "Ship placed.\n";
        std::cout << "Current playfield:\n";
        printBoard(human.getMyGrid());
    }
    std::cout << "all the ships are placed. The game will begin.\n";
}

void Game::printBoard(std::vector<std::vector<int>> board) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
           std::cout << board.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

