/**
 * @file Game.cpp
 * @brief Implementation of Game class
 *
 */

#include "../include/Game.h"
#include <iostream>
#include <vector>

void Game::runSetup() {
  ai.setupGrid();

  std::cout << "Import board setup from file? y/n\n";
  if (std::cin.get() == 'y' || std::cin.get() == 'Y') {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    human.importBoardFromFile(filename);
    return;
  }

  // printBoard(ai.getMyGrid());
  static const int SHIP_SIZES[] = {5, 4, 3, 3, 2};
  static const int SHIP_COUNT = 5;
  for (int i = 0; i < SHIP_COUNT; ++i) {
    int size = SHIP_SIZES[i];
    bool placed = false;
    while (!placed) {
      int startX, startY, endX, endY;
      int shipLenght = 0;
      std::cout << "Current ship's lenght: " << size << "\n";
      std::cout << "Please enter ship's start coordinates (e.g. 0 0): ";
      std::cin >> startX >> startY;
      std::cout << "Please enter ship's end coordinates (e.g. 5 0): ";
      std::cin >> endX >> endY;
      if ((startX < 0) || (startY < 0) || (endX < 0) || (endY < 0)) {
        std::cout << "No negative coordinates allowed.\n";
        continue;
      }
      shipLenght = abs(startX - endX) > abs(startY - endY) ? abs(startX - endX)
                                                           : abs(startY - endY);
      if (shipLenght > size - 1) {
        std::cout << "Ship too big.\n";
        continue;
      }
      if (shipLenght < size - 1) {
        std::cout << "Ship too small\n";
        continue;
      }
      // std::cout << endX;
      Ship ship(Coordinates(startX, startY), Coordinates(endX, endY));
      placed = human.placeShip(ship);
      if (!placed) {
        std::cout << "Can't place ship here.\n";
      }
    }
    std::cout << "Ship placed.\n";
    std::cout << "Current playfield:\n";
    printBoard(human.getMyGrid());
  }
  std::cout << "all the ships are placed. The game will begin.\n";
}

void Game::runGame() {
  int gameEnded = 0;
  while (!gameEnded) {
    bool hit = 0;
    Coordinates fireAt;
    // human turn
    std::cout << "Current board state:\n";
    printBoard(human.getMyGrid());
    std::cout << "chose where to attack:\n";
    printTargetBoard(ai.getMyGrid());
    fireAt = human.fireShot();
    hit = ai.attacked(fireAt);
    human.updateTargetGrid(fireAt, hit);
    if (hit) {
      std::cout << "You have hit an enemy ship.\n";
    } else {
      std::cout << "You missed.\n";
    }
    // ai turn
    fireAt = ai.fireShot();
    hit = human.attacked(fireAt);
    ai.updateTargetGrid(fireAt, hit);
    if (hit) {
      std::cout << "AI has hit your ship.\n";
    } else {
      std::cout << "AI missed.\n";
    }
    if (!shipsAlive(human.getMyGrid())) {
      std::cout << "you lost.\n";
      return;
    }
    if (!shipsAlive(ai.getMyGrid())) {
      std::cout << "You won!\n";
      return;
    }
  }
}

void Game::printBoard(std::vector<std::vector<int>> board) {
  std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
  std::cout << "  -------------------\n";
  for (int i = 0; i < 10; ++i) {
    std::cout << i << "|";
    for (int j = 0; j < 10; ++j) {
      if (board.at(j).at(i) == 3) {
        std::cout << "\033[33m" << board.at(j).at(i) << "\033[0m" << " ";
      }
      else if (board.at(j).at(i) == 2) {
        std::cout << "\033[31m" << board.at(j).at(i) << "\033[0m" << " ";
      }
      else if (board.at(j).at(i) == 1) {
        std::cout << "\033[34m" << board.at(j).at(i) << "\033[0m" << " ";
      }
      else {
        std::cout << board.at(j).at(i) << " ";
      }
      
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
void Game::printTargetBoard(std::vector<std::vector<int>> board) {
  std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
  std::cout << "  -------------------\n";
  for (int i = 0; i < 10; ++i) {
    std::cout << i << "|";
    for (int j = 0; j < 10; ++j) {
      if (board.at(j).at(i) != 1) {
        if (board.at(j).at(i) == 3) {
          std::cout << "\033[33m" << board.at(j).at(i) << "\033[0m" << " ";
        }
        else if (board.at(j).at(i) == 2) {
          std::cout << "\033[31m" << board.at(j).at(i) << "\033[0m" << " ";
        }
        else {
          std::cout << board.at(j).at(i) << " ";
        }
      } else {
        std::cout << "0 ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool Game::shipsAlive(std::vector<std::vector<int>> board) {
  for (long unsigned int i = 0; i < board.size(); ++i) {
    for (long unsigned int j = 0; j < board.at(i).size(); ++j) {
      if (board.at(i).at(j) == 1) {
        return true;
      }
    }
  }
  return false;
}
