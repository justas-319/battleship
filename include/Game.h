/**
 * @file Game.h
 * @brief Defines The game class, which allows users to interact with the game
 *
 */

#pragma once
#include "../include/AI.h"
#include "../include/Coordinates.h"
#include "../include/Human.h"
#include "../include/Player.h"
#include <vector>
/****
 * @class Game
 * @brief Implements basic game functions
 *
 */
class Game {
private:
  /**
   * @brief prints out the given board parameter
   *
   * @param board Players board
   */
  void printBoard(std::vector<std::vector<int>> board);
  /**
   * @brief checks if there are alive ships on a given board
   *
   * @param board Players board
   * @return true there are alive ships
   * @return false no alive ships are left
   */

  /**
   * @brief prints out the given board parameter, but hides the ships
   *
   * @param board
   */
  void printTargetBoard(std::vector<std::vector<int>> board);
  /**
   * @brief checks if there are alive ships on a given board
   *
   * @param board
   * @return true there are alive ships, else false
   */
  bool shipsAlive(std::vector<std::vector<int>> board);
  AI ai;       ///< The AI player
  Human human; ///< The human player

public:
  // Game();
  // ~Game();
  /**
   * @brief runs thru ai and human board setup
   *
   */
  void runSetup();
  /**
   * @brief runs the game loop
   *
   */
  void runGame();
};
