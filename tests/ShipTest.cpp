#include "ShipTest.h"

void testShip() {
  Ship ship(Coordinates(1, 1), Coordinates(1, 3));
  assert(!ship.getIsSunk());
  assert(ship.checkHit(Coordinates(1, 2)));
  assert(!ship.getIsSunk());
  assert(ship.checkHit(Coordinates(1, 1)));
  assert(!ship.getIsSunk());
  assert(ship.checkHit(Coordinates(1, 3)));
  assert(ship.getIsSunk());
  assert(!ship.checkHit(Coordinates(2, 2)));
  assert(!ship.checkHit(Coordinates(100, 100)));
  std::cout << "Ship tests passed!" << std::endl;
}
