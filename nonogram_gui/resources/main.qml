import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

import "qrc:/resources"

ApplicationWindow {
    visible: true
    title: qsTr("Nonogram GUI")
    width: 700
    height: 500

    property var cell_dimension: 20

    ListView{
        anchors.margins: 2
        model: NonogramRectModel {
            nonogram: nonogramWrapper
        }

        delegate: NonogramRectDelegate {
            id: nonogram_rect_delegate
        }
    }
}
