#include "canvas.h"

// Конструктор
Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
}

// Событие при обновлении виджета
void Canvas::paintEvent(QPaintEvent *)
{
    if (!imCreated)
    {
        image = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
        image.fill(0);
        imCreated = true;
    }

    QPainter painter(this);
    painter.drawImage(0, 0, image);
}
