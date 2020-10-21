import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

Rectangle {
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.margins: 1

    width: model.field_width * cell_dimension
    height: model.max_column_numbers * cell_dimension

    border.color: "#000000"
    border.width: 1

    GridView {
        id: column_numbers_grid_view
        model: ColumnNumbersModel {
            id: column_numbers_model
            nonogram: nonogramWrapper
        }

        anchors.fill: parent

        cellWidth: cell_dimension
        cellHeight: cell_dimension

        delegate: ColumnNumbersDelegate {
            id: column_numbers_delegate
        }
    }
}
