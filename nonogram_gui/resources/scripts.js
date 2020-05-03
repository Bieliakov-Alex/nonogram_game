function drawCross(context, color, x_start, y_start, x_end, y_end) {
    context.fillStyle = Qt.rgba(0.6, 0.6, 0.6, 1);
    context.fillRect(x_start, y_start, x_end, y_end);

    context.fillStyle = Qt.rgba(1, 1, 1, 1);
    context.fillRect(x_start + 1, y_start + 1, x_end - 2, y_end - 2);

    context.strokeStyle = context.createPattern(color, Qt.SolidPattern);

    context.beginPath();
    context.moveTo(x_start, y_start);
    context.lineTo(x_end, y_end);
    context.closePath();
    context.stroke();

    context.beginPath();
    context.moveTo(x_end, y_start);
    context.lineTo(x_start, y_end);
    context.closePath();
    context.stroke();
}

function drawEmpty(context, x_start, y_start, x_end, y_end) {
    context.fillStyle = Qt.rgba(0.6, 0.6, 0.6, 1);
    context.fillRect(x_start, y_start, x_end, y_end);

    context.fillStyle = Qt.rgba(1, 1, 1, 1);
    context.fillRect(x_start + 1, y_start + 1, x_end - 2, y_end - 2);
}

function drawMarked(context, x_start, y_start, x_end, y_end) {
    context.fillStyle = Qt.rgba(0.6, 0.6, 0.6, 1);
    context.fillRect(x_start, y_start, x_end, y_end);

    context.fillStyle = Qt.rgba(0, 0, 0, 1);
    context.fillRect(x_start + 1, y_start + 1, x_end - 2, y_end - 2);
}
