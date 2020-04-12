/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_CELL_STATE_HPP_
#define NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_CELL_STATE_HPP_

/**
 * @brief The purpose of the enum is to indicate state of each cell of the
 * nonogram.
 */

enum class NonogramCellState {
  kEmpty = 0, /**< The value indicates that there is no sign in the cell*/
  kMarked,    /**< The value indicates that there is mark in the cell*/
  kCrossed,   /**< The value indicates that there is no mark in the cell*/
};

#endif // NONOGRAM_GAME_NONOGRAM_INCLUDE_NONOGRAM_CELL_STATE_HPP_
