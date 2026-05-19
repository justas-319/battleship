/**
 * @file Coordinates.h
 * @brief Defines the Coordinates struct, which represents a point in 2D space
 * with x and y coordinates.
 */

#pragma once

/**
 * @class Coordinates
 * @brief Represents a point in 2D space with x and y coordinates.
 *
 */
struct Coordinates {
  int x;
  int y;

  /**
   * @brief Default constructor that initializes the coordinates to (0, 0).
   */
  Coordinates() : x(0), y(0) {}
  /**
   * @brief Parameterized constructor that initializes the coordinates to the
   * specified values.
   *
   * @param x
   * @param y
   */
  Coordinates(int x, int y) : x(x), y(y) {}
};
