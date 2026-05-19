/**
 * @file Ship.h
 * @brief Defines the Ship class, which represents a ship in a game of
 * Battleship.
 */

#pragma once

#include "Coordinates.h"

/****
 * @class Ship
 * @brief Represents a ship in a game of Battleship.
 */
class Ship {
private:
  bool isSunk;  /**< A flag indicating whether the ship has been sunk. */
  int hitCount; /**< The number of hits the ship has taken. */
public:
  Coordinates start; /**< The starting coordinates of the ship. */
  Coordinates end;   /**< The ending coordinates of the ship. */

  /**
   * @brief Default constructor that initializes the ship with default values.
   */
  Ship() : isSunk(false), hitCount(0), start(), end() {};
  /**
   * @brief Destructor for the Ship class. Since we are not dynamically
   * allocating any memory in this class, we can use the default destructor
   * provided by the compiler.
   */
  ~Ship() = default;
  /**
   * @brief Parameterized constructor that initializes the ship with the
   * specified starting and ending coordinates.
   *
   * @param start
   * @param end
   */
  Ship(Coordinates start, Coordinates end);
  /**
   * @brief Checks if the given attack coordinates hit the ship.
   *
   * @param attack The coordinates of the attack.
   * @return true if the attack hits the ship, false otherwise.
   */

  bool checkHit(Coordinates attack);
  /**
   * @brief Returns whether the ship has been sunk.
   *
   * @return true if the ship has been sunk, false otherwise.
   */
  bool getIsSunk();
};
