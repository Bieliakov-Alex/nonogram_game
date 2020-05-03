/*Copyright 2020 Alex Bieliakov*/

#include "column_numbers_model.hpp"

#include <QString>

ColumnNumbersModel::ColumnNumbersModel(QObject *parent)
    : QAbstractListModel(parent), nonogram_{nullptr} {}

int ColumnNumbersModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }

  return max_column_numbers_ * column_numbers_.size();
}

QVariant ColumnNumbersModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  switch (role) {
  case MaxColumnNumbersRole:
    return max_column_numbers_;
  case FieldWidthRole:
    return static_cast<quint8>(column_numbers_.size());
  case ColumnNumberTextRole: {
    auto row = index.row() / column_numbers_.size();
    auto column = index.row() % column_numbers_.size();
    auto max_column_size = column_numbers_[column].size();
    return (max_column_numbers_ - row) > max_column_size
               ? ""
               : QString::number(
                     column_numbers_[column][max_column_numbers_ - row - 1]);
  }
  default:
    return QVariant();
  }
}

QHash<int, QByteArray> ColumnNumbersModel::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();

  roles[MaxColumnNumbersRole] = "max_column_numbers";
  roles[FieldWidthRole] = "field_width";
  roles[ColumnNumberTextRole] = "column_number_text";

  return roles;
}

NonogramWrapper *ColumnNumbersModel::nonogram() const { return nonogram_; }

void ColumnNumbersModel::setNonogram(NonogramWrapper *nonogram) {
  nonogram_ = nonogram;

  auto field_width = nonogram_->GetFieldWidth();

  max_column_numbers_ = nonogram_->GetMaxColumnNumbers();

  for (size_t i = 0; i < field_width; ++i) {
    column_numbers_.push_back(nonogram_->getNonogram()->GetColumnNumbers(i));
  }
}
