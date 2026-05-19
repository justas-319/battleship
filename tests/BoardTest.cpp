#include "BoardTest.h"

void testBoard() {
  Board board;
  Ship ship1(Coordinates(1, 1), Coordinates(1, 3));
  Ship ship2(Coordinates(3, 3), Coordinates(5, 3));
  assert(board.placeShip(ship1));
  assert(board.placeShip(ship2));
  assert(!board.placeShip(
      Ship(Coordinates(0, 1), Coordinates(2, 1)))); // Overlapping
  assert(!board.placeShip(
      Ship(Coordinates(-1, -1), Coordinates(-1, -1)))); // Out of bounds
  assert(
      !board.placeShip(Ship(Coordinates(0, 0), Coordinates(1, 1)))); // Diagonal

  assert(board.attack(Coordinates(1, 2)));  // Hit ship1
  assert(!board.attack(Coordinates(2, 2))); // Miss
  assert(board.attack(Coordinates(1, 1)));  // Hit ship1
  assert(board.attack(Coordinates(1, 3)));  // Hit and sink ship1
  assert(board.attack(Coordinates(3, 3)));  // Hit ship2
  assert(board.attack(Coordinates(4, 3)));  // Hit ship2
  assert(board.attack(Coordinates(5, 3)));  // Hit and sink ship2
  std::cout << "Board tests passed!" << std::endl;
}
