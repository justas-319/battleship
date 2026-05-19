#include "HumanTest.h"
#include <sstream>

void testHuman() {
  Human human;

  std::istringstream input("3 4\n");
  std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

  Coordinates shot = human.fireShot();

  assert(shot.x == 3);
  assert(shot.y == 4);

  std::cin.rdbuf(oldCin);

  std::cout << "Human tests passed!" << std::endl;
}