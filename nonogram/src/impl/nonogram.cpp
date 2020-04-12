/*Copyright 2020 Alex Bieliakov*/

#include <stdexcept>

#include <boost/log/trivial.hpp>

#include "nonogram.hpp"
#include "nonogram_log.hpp"

Nonogram::Nonogram(const std::vector<std::vector<uint8_t>> &row_numbers,
                   const std::vector<std::vector<uint8_t>> &column_numbers,
                   const std::shared_ptr<INonogramLog> log)
    : rows_{static_cast<uint8_t>(row_numbers.size())},
      columns_{static_cast<uint8_t>(column_numbers.size())},
      field_{rows_, {columns_, NonogramCellState::kEmpty}},
      row_numbers_{row_numbers}, column_numbers_{column_numbers}, log_{log} {
  log_->LogInfo("Constructing nonogram object.");
}

const std::vector<std::vector<NonogramCellState>> &Nonogram::GetField() const {
  log_->LogInfo("Returning field.");
  return field_;
}

const uint8_t Nonogram::GetColumns() const {
  log_->LogInfo("Returning columns.");
  return columns_;
}

const uint8_t Nonogram::GetRows() const {
  log_->LogInfo("Returning rows.");
  return rows_;
}

const NonogramCellState
Nonogram::GetNonogramCellState(const uint8_t row, const uint8_t column) const {
  log_->LogInfo("Returning state of cell.");
  if (row < 0 || row >= rows_ || column < 0 || column >= columns_) {
    throw std::runtime_error("The value of row or(and) column is not correct.");
  } else {
    return field_[row][column];
  }
}

void Nonogram::SetNonogramCellState(const uint8_t row, const uint8_t column,
                                    NonogramCellState state) {
  log_->LogInfo("Setting new state to the cell.");
  if (row < 0 || row >= rows_ || column < 0 || column >= columns_) {
    throw std::runtime_error("The value of row or(and) column is not correct.");
  } else {
    field_[row][column] = state;
  }
  return;
}

const std::vector<uint8_t> &Nonogram::GetRowNumbers(const uint8_t row) const {
  log_->LogInfo("Getting numbers for the row.");
  if (row < 0 || row >= rows_) {
    throw std::runtime_error("The value of row is not correct.");
  } else {
    return row_numbers_[row];
  }
}

const std::vector<uint8_t> &
Nonogram::GetColumnNumbers(const uint8_t column) const {
  log_->LogInfo("Getting numbers for the column.");
  if (column < 0 || column >= columns_) {
    throw std::runtime_error("The value of row or(and) column is not correct.");
  } else {
    return column_numbers_[column];
  }
}
