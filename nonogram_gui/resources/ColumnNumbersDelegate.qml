import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

Item {
    Rectangle {
        width: cell_dimension
        height: cell_dimension
        border.color: "#000000"
        border.width: 1
        color: "#A9A9A9"
        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: model.column_number_text
        }
    }
}
