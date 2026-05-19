/**
 * @file Player.cpp
 * @brief Implements the Player class, the abstract base for Human and AI
 *        players in a game of Battleship.
 */

#include "../include/Player.h"

Player::Player() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      targetGrid[i][j] = 0; // 0 = no shot fired at this cell yet
    }
  }
}

bool Player::placeShip(Ship ship) { return myBoard.placeShip(ship); }

void Player::updateTargetGrid(Coordinates coords, bool hit) {
  targetGrid[coords.x][coords.y] = hit ? 2 : 3;
}

int **Player::getMyGrid() const { return myBoard.getGrid(); }

int **Player::getTargetGrid() const { return (int **)targetGrid; }