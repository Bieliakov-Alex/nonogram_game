import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "scripts.js" as NonogramScripts

Canvas {
    property var canvas_parent_view
    anchors.fill: parent
    onPaint: {
        canvas_parent_view.width = parent_cell_dimension * model.column_count;
        canvas_parent_view.height = parent_cell_dimension * model.row_count;

        var canvas_context = getContext("2d");
        switch(model.state) {
        case NonogramFieldModel.Empty: {
            NonogramScripts.drawEmpty(canvas_context, 0, 0, parent_cell_dimension, parent_cell_dimension);
            break;
        }
        case NonogramFieldModel.Marked: {
            NonogramScripts.drawMarked(canvas_context, 0, 0, parent_cell_dimension, parent_cell_dimension);
            break;
        }
        case NonogramFieldModel.Crossed: {
            NonogramScripts.drawCross(canvas_context, "#000000", 0, 0, parent_cell_dimension, parent_cell_dimension);
            break;
        }
        }
    }
}
