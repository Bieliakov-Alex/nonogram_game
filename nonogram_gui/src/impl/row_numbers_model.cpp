/*Copyright 2020 Alex Bieliakov*/

#include "row_numbers_model.hpp"

#include <QString>

RowNumbersModel::RowNumbersModel(QObject *parent)
    : QAbstractListModel(parent), nonogram_{nullptr} {}

int RowNumbersModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }

  return max_row_numbers_ * static_cast<quint8>(row_numbers_.size());
}

QVariant RowNumbersModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  switch (role) {
  case MaxRowNumbersRole:
    return max_row_numbers_;
  case FieldHeightRole:
    return static_cast<quint8>(row_numbers_.size());
  case RowNumberTextRole: {
    auto row = index.row() / max_row_numbers_;
    auto column = index.row() % max_row_numbers_;
    auto max_row_size = row_numbers_[row].size();

    return (max_row_numbers_ - column) > max_row_size
               ? ""
               : QString::number(
                     row_numbers_[row][max_row_numbers_ - column - 1]);
  }
  default:
    return QVariant();
  }

  return QVariant();
}

QHash<int, QByteArray> RowNumbersModel::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();

  roles[MaxRowNumbersRole] = "max_row_numbers";
  roles[FieldHeightRole] = "field_height";
  roles[RowNumberTextRole] = "row_number_text";

  return roles;
}

NonogramWrapper *RowNumbersModel::nonogram() const { return nonogram_; }

void RowNumbersModel::setNonogram(NonogramWrapper *nonogram) {
  nonogram_ = nonogram;

  auto field_height = nonogram_->GetFieldHeight();
  max_row_numbers_ = nonogram_->GetMaxRowNumbers();

  for (size_t i = 0; i < field_height; ++i) {
    row_numbers_.push_back(nonogram_->getNonogram()->GetRowNumbers(i));
  }
}
