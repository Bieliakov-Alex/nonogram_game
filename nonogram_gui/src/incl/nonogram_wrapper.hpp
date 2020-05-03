/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_WRAPPER_HPP_
#define NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_WRAPPER_HPP_

/**
 * @brief The class describes qt wrapper for the i_nonogram object.
 */

#include <QObject>

#include <memory>

#include "nonogram_factory.hpp"

class NonogramWrapper : public QObject {
  Q_OBJECT

public:
  explicit NonogramWrapper(const std::shared_ptr<INonogram> &nonogram,
                           QObject *parent = nullptr);

  /**
   * @brief The method returns pointer to the i_nonogram object.
   *
   * @return Pointer to the i_nonogram object.
   */
  const std::shared_ptr<INonogram> getNonogram() const;

  /**
   * @brief The method returns count of the columns of the nonogram.
   *
   * @return Count of the columns of the nonogram.
   */
  const quint8 GetFieldWidth() const;

  /**
   * @brief The method returns count of the rows of the nonogram.
   *
   * @return Count of the rows of the nonogram.
   */
  const quint8 GetFieldHeight() const;

  /**
   * @brief The method returns max count of row numbers in one row of the
   * nonogram.
   *
   * @return Max count of row numbers in one row.
   */
  const quint8 GetMaxRowNumbers() const;

  /**
   * @brief The method returns max count of column numbers in one column of the
   * nonogram.
   *
   * @return Max count of column numbers in one column.
   */
  const quint8 GetMaxColumnNumbers() const;

private:
  /**
   * @brief Pointer to the i_nonogram object.
   */
  const std::shared_ptr<INonogram> nonogram_;

  /**
   * @brief Count of the main nonogram field columns.
   */
  const quint8 field_width_;

  /**
   * @brief Count of the main nonogram field rows.
   */
  const quint8 field_height_;

  /**
   * @brief Max count of row numbers in one row.
   */
  const quint8 max_row_numbers_;

  /**
   * @brief Max count of column numbers in one column.
   */
  const quint8 max_column_numbers_;
};

#endif // NONOGRAM_GAME_NONOGRAM_GUI_SRC_INCL_NONOGRAM_WRAPPER_HPP_
