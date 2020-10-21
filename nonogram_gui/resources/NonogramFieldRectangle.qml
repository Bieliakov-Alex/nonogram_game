import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

Rectangle {
    property var column_numbers_prop
    id: nonogram_field

    anchors.top: column_numbers_prop.bottom
    anchors.right: column_numbers_prop.right

    width: model.field_width * cell_dimension
    height: model.field_height * cell_dimension

    border.color: "#000000"
    border.width: 1
    color: "#ffffff"

    GridView {
        id: main_grid_view
        model: NonogramFieldModel {
            id: nonogram_field_model
            nonogram: nonogramWrapper
        }

        cellWidth: cell_dimension
        cellHeight: cell_dimension
        delegate: NonogramDelegate {
            parent_cell_dimension: cell_dimension
            parent_view: main_grid_view
        }
    }
}
