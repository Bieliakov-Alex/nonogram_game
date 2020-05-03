import QtQuick 2.14
import QtQuick.Controls 2.12

import NonogramModel 1.0

Item {
    property var parent_cell_dimension
    property var parent_view

    anchors.margins: 50
    height: parent_cell_dimension
    width: parent_cell_dimension

    Rectangle {
        anchors.fill: parent
        NonogramCanvas{
            id: delegate_canvas
            canvas_parent_view: parent_view
        }
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                switch(mouse.button) {
                case Qt.LeftButton: {
                    model.state = (model.state == NonogramFieldModel.Marked ? NonogramFieldModel.Empty : NonogramFieldModel.Marked);
                    break;
                }
                case Qt.RightButton: {
                    model.state = (model.state == NonogramFieldModel.Crossed ? NonogramFieldModel.Empty :
                                   NonogramFieldModel.Crossed);
                    break;
                }
                }
                delegate_canvas.requestPaint();
            }
        }
    }
}
