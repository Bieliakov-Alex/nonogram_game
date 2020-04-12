/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_INCLUDE_I_NONOGRAM_HPP_
#define NONOGRAM_GAME_NONOGRAM_INCLUDE_I_NONOGRAM_HPP_

#include <cstdint>
#include <vector>

#include "nonogram_cell_state.hpp"

/**
 * @brief The class describes interface for nonogram game object.
 */

class INonogram {
public:
  virtual ~INonogram() = default;

  /**
   * @brief The method returns state of the nonogram field.
   *
   * @return State of the nonogram field.
   */
  virtual const std::vector<std::vector<NonogramCellState>> &
  GetField() const = 0;

  /**
   * @brief The method returns count of columns of the nonogram.
   *
   * @return Number of columns of the nonogram.
   */
  virtual const uint8_t GetColumns() const = 0;

  /**
   * @brief The method returns count of columns of the nonogram.
   *
   * @return Number of rows of the nonogram.
   */
  virtual const uint8_t GetRows() const = 0;

  /**
   * @brief The method returns state of the nonogram cell.
   *
   * @param row Number of the row of the nonogram. Count starts from 0.
   *
   * @param column Number of the column of the nonogram. Count starts from 0.
   *
   * @return State of the nonogram cell.
   */
  virtual const NonogramCellState GetNonogramCellState(const uint8_t row,
                                           const uint8_t column) const = 0;

  /**
   * @brief The method sets state to the nonogram cell.
   *
   * @param row Number of the row of the nonogram. Count starts from 0.
   *
   * @param column Number of the column of the nonogram. Count starts from 0.
   */
  virtual void SetNonogramCellState(const uint8_t row, const uint8_t column,
                                    const NonogramCellState state) = 0;

  /**
   * @brief The method returns vector of numbers according to which the nonogram
   * row should be filled.
   *
   * @param row Number of the row of the nonogram. Count starts from 0.
   *
   * @return Vector of the numbers of the row of the nonogram.
   */
  virtual const std::vector<uint8_t> &
  GetRowNumbers(const uint8_t row) const = 0;

  /**
   * @brief The method returns vector of numbers according to which the nonogram
   * column should be filled.
   *
   * @param column Number of the column of the nonogram. Count starts from 0.
   *
   * @return Vector of the numbers of the column of the nonogram.
   */
  virtual const std::vector<uint8_t> &
  GetColumnNumbers(const uint8_t column) const = 0;
};

#endif // NONOGRAM_GAME_NONOGRAM_INCLUDE_I_NONOGRAM_HPP_
