/**
 * @file AI.h
 * @brief Defines the AI class, which represents a computer-controlled player
 *        in a game of Battleship.
 */

#pragma once

#include "Player.h"

/**
 * @class AI
 * @brief Represents a computer-controlled player in a game of Battleship.
 *
 * Extends Player with:
 *  - setupGrid()  : automatically places all ships on the AI's own board
 *                   using random-but-valid positions.
 *  - fireShot()   : automatically selects an un-fired target cell.
 *                   The base implementation uses a random strategy; the game
 *                   logic layer may call more sophisticated selection.
 */
class AI : public Player {
public:
  /**
   * @brief Default constructor. Delegates initialisation to Player().
   */
  AI();

  /**
   * @brief Default destructor.
   */
  ~AI() = default;

  /**
   * @brief Automatically places all required ships on the AI's own board.
   *
   * Generates random start coordinates and orientation for each ship,
   * retrying until Board::placeShip() accepts the placement.
   * Called once during the Setup phase (see activity diagram).
   */
  void setupGrid();

  /**
   * @brief Automatically selects a target cell on the opponent's board.
   *
   * Picks a cell whose targetGrid value is 0 (not yet attacked).
   * The selection strategy (random vs. hunt/target) is determined by the
   * logic implemented in the body of this method.
   *
   * @return Coordinates The cell the AI chooses to attack.
   */
  Coordinates fireShot() override;
};
