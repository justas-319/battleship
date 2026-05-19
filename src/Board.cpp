/**
 * @file Board.cpp
 * @brief Implements the Board class, which represents the game board in a game
 * of Battleship.
 */

#include "../include/Board.h"

Board::Board() {
  grid.resize(10, std::vector<int>(10, 0)); // Initialize a
}

bool Board::placeShip(Ship ship) {
  if (ship.start.x < 0 || ship.start.x > 9 || ship.start.y < 0 ||
      ship.start.y > 9 || ship.end.x < 0 || ship.end.x > 9 || ship.end.y < 0 ||
      ship.end.y > 9) {
    return false; // Out of bounds
  }

  for (int i = ship.start.x; i <= ship.end.x; i++) {
    for (int j = ship.start.y; j <= ship.end.y; j++) {
      if (grid[i][j] != 0) {
        return false; // Overlapping with another ship
      }
    }
  }
  if (ship.start.x != ship.end.x && ship.start.y != ship.end.y) {
    return false; // diagonal line
  }
  for (int i = ship.start.x; i <= ship.end.x; i++) {
    for (int j = ship.start.y; j <= ship.end.y; j++) {
      grid[i][j] = 1; // Mark the cells occupied by the ship
    }
  }
  ships.push_back(ship);
  return true;
}

bool Board::attack(Coordinates attack) {

  for (Ship &ship : ships) {
    if (ship.checkHit(attack)) {
      grid[attack.x][attack.y] = 2; // Mark as hit
      if (ship.getIsSunk()) {
        // mark 3 for all cells around the sunk ship
        for (int i = ship.start.x - 1; i <= ship.end.x + 1; i++) {
          for (int j = ship.start.y - 1; j <= ship.end.y + 1; j++) {
            if (i >= 0 && i < 10 && j >= 0 && j < 10 && grid[i][j] == 0) {
              grid[i][j] = 3; // Mark as miss around the sunk ship
            }
          }
        }
      }
      return true;
    }
  }
  grid[attack.x][attack.y] = 3; // Mark as miss
  return false;
}
