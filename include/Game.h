/**
 * @file Game.h
 * @brief Defines The game class, which allows users to interact with the game 
 * 
 */

#pragma once
#include <../include/Human.h>
#include <../include/AI.h>
#include <../include/Coordinates.h>
#include <vector>
/****
 * @class Game
 * @brief Implements basic game functions
 * 
 */
class Game
{
private:
    void printBoard(std::vector<std::vector<int>> board);
    // void aiSetup();
    // void humanSetup();
    AI ai;
    Human human;

public:
    // Game();
    // ~Game();

    void runSetup();
    // void startGame();

};
