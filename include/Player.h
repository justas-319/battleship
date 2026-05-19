/**
 * @file Player.h
 * @brief Defines the abstract Player class, which serves as the base class for
 * Human and AI players in a game of Battleship.
 */

#pragma once

#include "Board.h"
#include "Coordinates.h"
#include "Ship.h"

/**
 * @class Player
 * @brief Abstract base class representing a player in a game of Battleship.
 *
 * Holds the player's own board (where their ships reside) and a target grid
 * (a local record of shots fired at the opponent's board). Concrete subclasses
 * must implement fireShot(), which differs between a Human (user input) and
 * an AI (automated selection).
 */
class Player {
protected:
  Board myBoard; /**< The player's own board, containing their ships. */
  int targetGrid[10][10]; /**< Local tracking grid for shots fired at the opponent.
                           0 = unknown, 2 = hit, 3 = miss (mirrors Board grid
                           encoding). */

public:
  /**
   * @brief Default constructor. Initialises the target grid to all zeros
   *        (no shots fired yet).
   */
  Player();

  /**
   * @brief Virtual destructor. Derived classes clean up their own resources.
   */
  virtual ~Player() = default;

  /**
   * @brief Attempts to place a ship on the player's own board.
   *
   * Delegates to Board::placeShip, which validates bounds and overlap.
   *
   * @param ship The ship to place (start/end coordinates must already be set).
   * @return true  if the ship was placed successfully.
   * @return false if the placement is invalid (out of bounds or overlapping).
   */
  bool placeShip(Ship ship);

  /**
   * @brief Selects the coordinates for the next attack on the opponent's board.
   *
   * Pure virtual — Human reads from user input; AI computes a target
   * automatically.
   *
   * @return Coordinates The cell to attack on the opponent's board.
   */
  virtual Coordinates fireShot() = 0;

  /**
   * @brief Records the outcome of a shot on the target grid.
   *
   * Should be called after the opponent's Board::attack() returns so that the
   * player's local view stays in sync with the opponent's board state.
   *
   * @param coords The cell that was attacked.
   * @param hit    true if the shot hit a ship, false if it missed.
   */
  void updateTargetGrid(Coordinates coords, bool hit);

  /**
   * @brief Returns a pointer to the player's own 10×10 board grid.
   *
   * Grid encoding: 0 = empty, 1 = ship, 2 = hit, 3 = miss.
   *
   * @return int** Pointer to the internal 2-D array of myBoard.
   */
  int **getMyGrid() const;

  /**
   * @brief Returns a pointer to the player's 10×10 target-tracking grid.
   *
   * Grid encoding: 0 = unknown, 2 = hit, 3 = miss.
   *
   * @return int** Pointer to the internal 2-D target grid array.
   */
  int **getTargetGrid() const;
};