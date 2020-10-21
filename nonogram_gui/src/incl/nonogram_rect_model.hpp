/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_RECT_MODEL_HPP_
#define NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_RECT_MODEL_HPP_

/**
 * @brief The class describes model for the QML component, which repesents
 * rectangles for the nonogram field parts.
 */

#include <QAbstractListModel>
#include <QtGlobal>

#include <cstdint>
#include <memory>
#include <vector>

#include "nonogram_wrapper.hpp"

class NonogramRectModel : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(NonogramWrapper *nonogram READ nonogram WRITE setNonogram)

public:
  enum Roles {
    MaxRowNumbersRole = Qt::UserRole + 1,
    FieldWidthRole,
    MaxColumnNumbersRole,
    FieldHeightRole,
  };

  explicit NonogramRectModel(QObject *parent = 0);

  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

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

  /**
   * @brief Max count of row numbers in one row.
   */
  quint8 max_row_numbers_;

  /**
   * @brief Count of the main nonogram field columns.
   */
  quint8 field_width_;

  /**
   * @brief Max count of column numbers in one column.
   */
  quint8 max_column_numbers_;

  /**
   * @brief Count of the main nonogram field rows.
   */
  quint8 field_height_;
};

#endif // NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_RECT_MODEL_HPP_
