/**
 * @file Player.cpp
 * @brief Implements the Player class, the abstract base for Human and AI
 *        players in a game of Battleship.
 */

#include "../include/Player.h"

Player::Player() {
  // Initialize the target grid to 0 (unknown)
  targetGrid = std::vector<std::vector<int>>(10, std::vector<int>(10, 0));
}

bool Player::placeShip(Ship ship) { return myBoard.placeShip(ship); }

void Player::updateTargetGrid(Coordinates coords, bool hit) {
  targetGrid[coords.x][coords.y] = hit ? 2 : 3;
}

std::vector<std::vector<int>> Player::getMyGrid() const {
  return myBoard.getGrid();
}

std::vector<std::vector<int>> Player::getTargetGrid() const {
  return targetGrid;
}


  /**
   * @brief wrapper for board::attack
   * @param attack The coordinates of the attack.
   * @return true if the attack hits a ship, false if it misses.
   */
bool Player::attacked(Coordinates attack) {
  return myBoard.attack(attack);
}