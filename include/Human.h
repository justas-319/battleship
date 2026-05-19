/**
 * @file Human.h
 * @brief Defines the Human class, which represents a human player in a game
 *        of Battleship.
 */

#pragma once

#include "Player.h"

/**
 * @class Human
 * @brief Represents a human-controlled player in a game of Battleship.
 *
 * Extends Player with a fireShot() implementation that obtains the target
 * coordinates from user input (keyboard). Ship placement is interactive:
 * the game loop is responsible for reading the desired position and rotation
 * from the user and calling placeShip() accordingly.
 */
class Human : public Player {
public:
  /**
   * @brief Default constructor. Delegates initialisation to Player().
   */
  Human();

  /**
   * @brief Default destructor.
   */
  ~Human() = default;

  /**
   * @brief Prompts the human player to enter attack coordinates.
   *
   * Reads a target cell from standard input, validates that the cell has not
   * already been fired upon (targetGrid value is 0), and returns the chosen
   * coordinates. Re-prompts on invalid input.
   *
   * @return Coordinates The cell the human player wishes to attack.
   */
  Coordinates fireShot() override;
};