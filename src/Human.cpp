/**
 * @file Human.cpp
 * @brief Implements the Human class.
 */

#include "../include/Human.h"
#include <iostream>
#include <limits>

Human::Human() : Player() {}

Coordinates Human::fireShot() {
  int x, y;
  while (true) {
    std::cout << "Enter target coordinates (row col, 0-9): ";
    if (!(std::cin >> x >> y)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter two integers.\n";
      continue;
    }
    if (x < 0 || x > 9 || y < 0 || y > 9) {
      std::cout << "Coordinates out of bounds. Both values must be between 0 and 9.\n";
      continue;
    }
    if (targetGrid[x][y] != 0) {
      std::cout << "You already fired at (" << x << ", " << y << "). Choose a different cell.\n";
      continue;
    }
    return Coordinates(x, y);
  }
}