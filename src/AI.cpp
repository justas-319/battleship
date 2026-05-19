/**
 * @file AI.cpp
 * @brief Implements the AI class.
 */

#include "../include/AI.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Standard Battleship fleet: Carrier(5), Battleship(4), Cruiser(3),
// Submarine(3), Destroyer(2)
static const int SHIP_SIZES[] = {5, 4, 3, 3, 2};
static const int SHIP_COUNT = 5;

AI::AI() : Player() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void AI::setupGrid() {
  for (int i = 0; i < SHIP_COUNT; i++) {
    int size = SHIP_SIZES[i];
    bool placed = false;
    while (!placed) {
      // Pick a random orientation: 0 = horizontal (along y), 1 = vertical
      // (along x)
      bool horizontal = (std::rand() % 2) == 0;
      int startX, startY;
      if (horizontal) {
        startX = std::rand() % 10;
        startY = std::rand() % (10 - size + 1);
      } else {
        startX = std::rand() % (10 - size + 1);
        startY = std::rand() % 10;
      }
      int endX = horizontal ? startX : startX + size - 1;
      int endY = horizontal ? startY + size - 1 : startY;
      Ship ship(Coordinates(startX, startY), Coordinates(endX, endY));
      placed = placeShip(ship);
    }
  }
}

Coordinates AI::fireShot() {
  int x, y;
  do {
    x = std::rand() % 10;
    y = std::rand() % 10;
  } while (targetGrid[x][y] != 0);
  return Coordinates(x, y);
}
