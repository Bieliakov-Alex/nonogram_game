/*Copyright 2020 Alex Bieliakov*/

#include "nonogram_wrapper.hpp"

NonogramWrapper::NonogramWrapper(const std::shared_ptr<INonogram> &nonogram,
                                 QObject *parent)
    : QObject{parent}, nonogram_{nonogram},
      field_width_{nonogram_->GetColumns()},
      field_height_{nonogram_->GetRows()},
      max_row_numbers_([&nonogram]() -> quint8 {
        auto field_height = nonogram->GetRows();
        auto max_row_numbers = nonogram->GetRowNumbers(0).size();

        for (size_t i = 0; i < field_height; ++i) {
          auto row_numbers_size = nonogram->GetRowNumbers(i).size();
          if (max_row_numbers < row_numbers_size) {
            max_row_numbers = row_numbers_size;
          }
        }
        return max_row_numbers;
      }()),
      max_column_numbers_{[&nonogram]() -> quint8 {
        auto field_width = nonogram->GetColumns();
        auto max_column_numbers = nonogram->GetColumnNumbers(0).size();

        for (size_t i = 0; i < field_width; ++i) {
          auto column_numbers_size = nonogram->GetColumnNumbers(i).size();
          if (max_column_numbers < column_numbers_size) {
            max_column_numbers = column_numbers_size;
          }
        }
        return max_column_numbers;
      }()} {}

const std::shared_ptr<INonogram> NonogramWrapper::getNonogram() const {
  return nonogram_;
}

const quint8 NonogramWrapper::GetFieldWidth() const { return field_width_; }

const quint8 NonogramWrapper::GetFieldHeight() const { return field_height_; }

const quint8 NonogramWrapper::GetMaxRowNumbers() const {
  return max_row_numbers_;
}

const quint8 NonogramWrapper::GetMaxColumnNumbers() const {
  return max_column_numbers_;
}
