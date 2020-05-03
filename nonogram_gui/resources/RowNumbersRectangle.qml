import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

Rectangle {
    property var column_numbers_prop
    property var nonogram_field_prop
    id: row_numbers

    anchors.top: column_numbers_prop.bottom
    anchors.right: nonogram_field_prop.left

    width: model.max_row_numbers * cell_dimension
    height: model.field_height * cell_dimension

    border.color: "#000000"
    border.width: 1

    GridView {
        id: row_numbers_grid_view
        model: RowNumbersModel {
            id: row_numbers_model
            nonogram: nonogramWrapper
        }

        anchors.fill: parent

        cellWidth: cell_dimension
        cellHeight: cell_dimension

        delegate: RowNumbersDelegate {
            id: row_numbers_delegate
        }
    }
}
