CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

BUILD_DIR = build

CORE_SRCS = src/Board.cpp src/Ship.cpp 

MAIN_SRC = src/main.cpp
GAME_TARGET = $(BUILD_DIR)/battleship

TEST_SRCS = tests/test.cpp tests/BoardTest.cpp tests/ShipTest.cpp
TEST_TARGET = $(BUILD_DIR)/run_tests

all: $(GAME_TARGET)

$(GAME_TARGET): $(CORE_SRCS) $(MAIN_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Game compiled successfully! Run with: ./$(GAME_TARGET)"

test: $(CORE_SRCS) $(TEST_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_TARGET)
	@echo "Tests compiled successfully! Running tests...\n"
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)/*
	@echo "Build folder cleaned."
