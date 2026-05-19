/**
 * @file Ship.cpp
 * @brief Implements the Ship class, which represents a ship in a game of
 * Battleship.
 */

#include "../include/Ship.h"
#include <algorithm>

Ship::Ship(Coordinates start, Coordinates end)
    : isSunk(false), start(start), end(end) {
  if (start.x > end.x) {
    std::swap(this->start.x, this->end.x);
  };
  if (start.y > end.y) {
    std::swap(this->start.y, this->end.y);
  };
}
bool Ship::checkHit(Coordinates attack) {
  if ((attack.x >= start.x && attack.x <= end.x) &&
      (attack.y >= start.y && attack.y <= end.y)) {
    return true;
  }
  return false;
}
bool Ship::getIsSunk() {
  if (isSunk) {
    return true;
  }
  for (int i = start.x; i <= end.x; i++) {
    for (int j = start.y; j <= end.y; j++) {
      if (!checkHit({i, j})) {
        return false; // If any part of the ship is not hit, it's not sunk
      }
    }
  }
  isSunk = true; // All parts of the ship are hit, mark it as sunk
  return true;
}
