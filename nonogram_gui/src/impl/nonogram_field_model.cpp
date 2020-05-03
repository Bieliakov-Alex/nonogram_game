/*Copyright 2020 Alex Bieliakov*/

#include "nonogram_field_model.hpp"

NonogramFieldModel::NonogramFieldModel(QObject *parent)
    : QAbstractListModel(parent), nonogram_{nullptr} {}

int NonogramFieldModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || !nonogram_) {
    return 0;
  } else {
    return nonogram_->GetFieldWidth() * nonogram_->GetFieldHeight();
  }
}

QVariant NonogramFieldModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  switch (role) {
  case StateRole: {
    auto field = nonogram_->getNonogram()->GetField();
    auto cell_state =
        field[index.row() / field[0].size()][index.row() % field[0].size()];
    switch (cell_state) {
    case NonogramCellState::kEmpty: {
      return State::Empty;
    }
    case NonogramCellState::kMarked: {
      return State::Marked;
    }
    case NonogramCellState::kCrossed: {
      return State::Crossed;
    }
    default:
      break;
    }
  }
  case RowCountRole: {
    return nonogram_->GetFieldHeight();
  }
  case ColumnCountRole: {
    return nonogram_->GetFieldWidth();
  }
  default:
    return QVariant();
  }
}

QHash<int, QByteArray> NonogramFieldModel::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();

  roles[StateRole] = "state";
  roles[RowCountRole] = "row_count";
  roles[ColumnCountRole] = "column_count";

  return roles;
}

bool NonogramFieldModel::setData(const QModelIndex &index,
                                 const QVariant &value, int role) {
  if (!index.isValid()) {
    return false;
  }

  switch (role) {
  case StateRole: {
    auto state = value.value<State>();
    auto nonogram_state = NonogramCellState::kEmpty;
    switch (state) {
    case State::Empty: {
      nonogram_state = NonogramCellState::kEmpty;
      break;
    }
    case State::Marked: {
      nonogram_state = NonogramCellState::kMarked;
      break;
    }
    case State::Crossed: {
      nonogram_state = NonogramCellState::kCrossed;
      break;
    }
    default: { return false; }
    }
    auto field = nonogram_->getNonogram()->GetField();
    auto row = index.row() / nonogram_->GetFieldWidth();
    auto column = index.row() % nonogram_->GetFieldWidth();
    nonogram_->getNonogram()->SetNonogramCellState(row, column, nonogram_state);
    break;
  }
  case RowCountRole:
    return false;
  case ColumnCountRole:
    return false;
  }

  emit dataChanged(index, index, QVector<int>() << role);
  return true;
}

Qt::ItemFlags NonogramFieldModel::flags(const QModelIndex &index) const {
  if (!index.isValid()) {
    return Qt::ItemIsEnabled;
  }

  return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

NonogramWrapper *NonogramFieldModel::nonogram() const { return nonogram_; }

void NonogramFieldModel::setNonogram(NonogramWrapper *nonogram) {
  nonogram_ = nonogram;
}
