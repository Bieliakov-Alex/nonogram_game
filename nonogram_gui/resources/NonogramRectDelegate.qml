import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

Item {
    Rectangle {
        x: 10
        y: 10

        width: (model.max_row_numbers + model.field_width) * cell_dimension + 2
        height: (model.max_column_numbers + model.field_height) * cell_dimension + 2

        color: "#ffffff"
        border.color: "#000000"
        border.width: 1

        ColumnNumbersRectangle {
            id: column_numbers
        }

        NonogramFieldRectangle {
            id: nonogram_field
            column_numbers_prop: column_numbers
        }

        RowNumbersRectangle {
            id: row_numbers
            column_numbers_prop: column_numbers
            nonogram_field_prop: nonogram_field
        }
    }
}
