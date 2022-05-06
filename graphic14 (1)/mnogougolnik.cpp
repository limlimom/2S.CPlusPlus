#include "mnogougolnik.h"

mnogougolnik::mnogougolnik(QObject *parent) : figure(parent)
{

}

void mnogougolnik::draw(QPainter *p)
{
    applyOutColor(p);   // применяем цвет обводки

    applyInColor(p);  // применяем цвет внутренней заливки

    QPolygonF polygon;
    for(int i=0; i<points_count; i++)
    {
        QPointF point;
        point.setX(mas_x[i]);
        point.setY(mas_y[i]);
        polygon.append(point);  // Добавляем точку в фигуру
    }
    p->drawPolygon(polygon);
}
