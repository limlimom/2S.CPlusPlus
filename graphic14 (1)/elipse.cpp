#include "elipse.h"

elipse::elipse()
{
    points_count = 1;   // для данной фигуры нужна 1 точка
    resizePoints(); // выделяю память под необходимое количество точек
}

void elipse::draw(QPainter *p)
{
    int x = mas_x[0];
    int y = mas_y[0];

    applyOutColor(p);   // применяем цвет обводки
    applyInColor(p);  // применяем цвет внутренней заливки

    p->drawEllipse(QPoint(x, y), radius_1, radius_2);
}
