#include "AITest.h"

void testAI() {
  AI ai;

  ai.setupGrid();

  std::vector<std::vector<int>> grid = ai.getMyGrid();

  int occupied = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (grid[i][j] == 1) {
        occupied++;
      }
    }
  }

  // Total ship cells: 5 + 4 + 3 + 3 + 2 = 17
  assert(occupied == 17);

  Coordinates shot = ai.fireShot();

  assert(shot.x >= 0 && shot.x < 10);
  assert(shot.y >= 0 && shot.y < 10);

  std::cout << "AI tests passed!" << std::endl;
}
