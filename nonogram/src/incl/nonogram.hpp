/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_HPP_
#define NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_HPP_

#include <memory>
#include <vector>

#include "i_nonogram.hpp"
#include "i_nonogram_log.hpp"

/**
 * @brief Implementation of the INonogram interface
 */
class Nonogram : public INonogram {
public:
  /**
   * @brief Creates nonogram object from vectors with numbers according to which
   * the nonogram should be solved.
   *
   * @param row_numbers vector of row numbers vectors.
   *
   * @param column_numbers vector of column numbers vectors.
   *
   * @param log The logger object.
   */
  Nonogram(const std::vector<std::vector<uint8_t>> &row_numbers,
           const std::vector<std::vector<uint8_t>> &column_numbers,
           const std::shared_ptr<INonogramLog> log);

  const std::vector<std::vector<NonogramCellState>> &GetField() const override;

  const uint8_t GetColumns() const override;

  const uint8_t GetRows() const override;

  const NonogramCellState
  GetNonogramCellState(const uint8_t row, const uint8_t column) const override;

  void SetNonogramCellState(const uint8_t row, const uint8_t column,
                            NonogramCellState state) override;

  const std::vector<uint8_t> &GetRowNumbers(const uint8_t row) const override;

  const std::vector<uint8_t> &
  GetColumnNumbers(const uint8_t column) const override;

private:
  /**
   * @brief The number of the nonogram rows.
   */
  const uint8_t rows_;

  /**
   * @brief The number of the nonogram columnss.
   */
  const uint8_t columns_;

  /**
   * @brief The member contains the nonogram state.
   */
  std::vector<std::vector<NonogramCellState>> field_;

  /**
   * @brief The member contains row numbers vectors according to which the
   * nonogram should be solved.
   */
  const std::vector<std::vector<uint8_t>> row_numbers_;

  /**
   * @brief The member contains column numbers vectors according to which the
   * nonogram should be solved.
   */
  const std::vector<std::vector<uint8_t>> column_numbers_;

  /**
   * @brief The logger object
   */
  const std::shared_ptr<INonogramLog> log_;
};

#endif // NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_HPP_
