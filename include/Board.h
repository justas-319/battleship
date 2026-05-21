/**
 * @file Board.h
 * @brief Defines the Board class, which represents the game board in a game of
 * Battleship.
 */

#pragma once

#include "Ship.h"
#include <string>
#include <vector>

/****
 * @class Board
 * @brief Represents the game board in a game of Battleship.
 */
class Board {
private:
  std::vector<Ship> ships; /**< An array of ships on the board. */
  std::vector<std::vector<int>>
      grid; /**< A 2D array representing the game board, where 0
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

  /**
   * @brief Returns a pointer to the 2D array representing the game board
   *
   * @return A pointer to the 2D array representing the game board
   */
  std::vector<std::vector<int>> getGrid() const { return grid; }

  /**
   * @brief Imports the game board configuration from a file (file format -
   * coordinates of the ships).
   *
   * @param filename The name of the file containing the game board
   * configuration.
   */
  void importFromFile(const std::string &filename);
};
