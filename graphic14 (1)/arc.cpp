#include "arc.h"

Arc::Arc(QObject *parent) : figure(parent)
{
    points_count = 1;   // для данной фигуры нужна 1 точка
    resizePoints(); // выделяю память под необходимое количество точек
}

void Arc::draw(QPainter *p)
{
    applyOutColor(p);   // применяем цвет обводки

    p->drawArc(mas_x[0], mas_y[0], radius_1, radius_2, angle1 * 16, angle2 * 16);
}
