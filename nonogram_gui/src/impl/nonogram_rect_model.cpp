/*Copyright 2020 Alex Bieliakov*/

#include "nonogram_rect_model.hpp"

#include <algorithm>

NonogramRectModel::NonogramRectModel(QObject *parent)
    : QAbstractListModel(parent), nonogram_{nullptr}, max_row_numbers_{0},
      field_width_{0}, max_column_numbers_{0}, field_height_{0} {}

int NonogramRectModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }

  return 1;
}

QVariant NonogramRectModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  switch (role) {
  case MaxRowNumbersRole: {
    return max_row_numbers_;
  }
  case FieldWidthRole:
    return field_width_;
  case MaxColumnNumbersRole:
    return max_column_numbers_;
  case FieldHeightRole:
    return field_height_;
  default:
    return QVariant();
  }

  return QVariant();
}

QHash<int, QByteArray> NonogramRectModel::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
  roles[MaxRowNumbersRole] = "max_row_numbers";
  roles[FieldWidthRole] = "field_width";
  roles[MaxColumnNumbersRole] = "max_column_numbers";
  roles[FieldHeightRole] = "field_height";

  return roles;
}

NonogramWrapper *NonogramRectModel::nonogram() const { return nonogram_; }

void NonogramRectModel::setNonogram(NonogramWrapper *nonogram) {
  nonogram_ = nonogram;

  field_height_ = nonogram_->GetFieldHeight();
  field_width_ = nonogram_->GetFieldWidth();

  max_row_numbers_ = nonogram_->GetMaxRowNumbers();
  max_column_numbers_ = nonogram_->GetMaxColumnNumbers();
}
