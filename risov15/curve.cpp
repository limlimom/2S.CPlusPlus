#include "curve.h"

// Конструктор
Curve::Curve()
{
    type = PrimitiveTypes::CurveT;
    pen = new Pen();
    points = new QVector<Point>(2);
}

// Рисование ломанной
void Curve::draw(QImage * im)
{
    QPainter painter(im);

    QPainterPath path;

    int cx, cy;
    (*points)[0].getXY(cx, cy);
    path.moveTo(cx, cy);
    int count = points->count();
    for (int i = 1; i < count; i++)
    {
        (*points)[i].getXY(cx, cy);
        path.lineTo(cx, cy);
    }

    int r, g, b, a;
    pen->getRGBA(r, g, b, a);
    QPen qpen(QColor(r, g, b, a));
    qpen.setWidth(pen->getWeight());
    qpen.setStyle(Qt::PenStyle(pen->getStyle()));

    painter.setPen(qpen);
    painter.drawPath(path);
}
