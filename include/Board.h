/**
 * @file Board.h
 * @brief Defines the Board class, which represents the game board in a game of
 * Battleship.
 */

#pragma once

#include "Ship.h"
#include <vector>

/****
 * @class Board
 * @brief Represents the game board in a game of Battleship.
 */
class Board {
private:
  std::vector<Ship> ships; /**< An array of ships on the board. */
  int grid[10][10];        /**< A 2D array representing the game board, where 0
                              indicates an empty cell, 1 indicates a cell occupied by a
                              ship, 2 indicates hit, and 3 indicates a miss. */
public:
  /**
   * @brief Default constructor that initializes the board with default values.
   */
  Board();
  /**
   * @brief Places a ship on the board at the specified coordinates.
   * @param ship The ship to be placed on the board.
   * @return true if the ship was successfully placed, false if the placement is
   * invalid (e.g., out of bounds or overlapping with another ship).
   */
  /**
   * @brief Destructor for the Board class. arrays and vectors will
   * automatically clean up their memory, so no explicit cleanup is necessary in
   * this destructor.
   *
   */
  ~Board() = default;
  bool placeShip(Ship ship);
  /**
   * @brief Attacks the specified coordinates on the board.
   * @param attack The coordinates of the attack.
   * @return true if the attack hits a ship, false if it misses.
   */
  bool attack(Coordinates attack);
};
