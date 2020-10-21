/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_FIELD_MODEL_HPP_
#define NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_FIELD_MODEL_HPP_

/**
 * @brief The class describes model for the QML component, which repesents part
 * the nonogram field.
 */

#include <QAbstractListModel>

#include "nonogram_cell_state.hpp"
#include "nonogram_wrapper.hpp"

class NonogramFieldModel : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(NonogramWrapper *nonogram READ nonogram WRITE setNonogram)

public:
  enum Roles {
    StateRole = Qt::UserRole + 1,
    RowCountRole,
    ColumnCountRole,
  };

  enum State {
    Empty,
    Marked,
    Crossed,
  };
  Q_ENUM(State);

  explicit NonogramFieldModel(QObject *parent = 0);

  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;
  bool setData(const QModelIndex &index, const QVariant &value,
               int role) override;
  Qt::ItemFlags flags(const QModelIndex &index) const override;

  /**
   * @brief The method returns pointer to the nonogram wrapper object.
   *
   * @return Pointer to the nonogram wrapper object.
   */
  NonogramWrapper *nonogram() const;

  /**
   * @brief The method sets pointer to the nonogram wrapper object.
   *
   * nonogram  Pointer to the nonogram wrapper object.
   */
  void setNonogram(NonogramWrapper *nonogram);

private:
  /**
   * @brief Pointer to nonogram wrapper object.
   */
  NonogramWrapper *nonogram_;
};

#endif // NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_FIELD_MODEL_HPP_
