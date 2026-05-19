/**
 * @file Ship.cpp
 * @brief Implements the Ship class, which represents a ship in a game of
 * Battleship.
 */

#include "../include/Ship.h"
#include <algorithm>
#include <cstdlib>

Ship::Ship(Coordinates start, Coordinates end)
    : isSunk(false), hitCount(0), start(start), end(end) {
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
    hitCount++;
    return true;
  }
  return false;
}
bool Ship::getIsSunk() {
  if (isSunk) {
    return true;
  }
  if (hitCount == abs(start.x - end.x) + abs(start.y - end.y) + 1) {
    isSunk = true;
  }
  return isSunk;
}
