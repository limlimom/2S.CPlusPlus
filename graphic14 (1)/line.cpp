#include "line.h"

line::line()
{
    points_count = 2;   // для данной фигуры нужна 1 точка
    resizePoints(); // выделяю память под необходимое количество точек
}

void line::draw(QPainter *p)
{
    int x_start = mas_x[0];
    int y_start = mas_y[0];

    int x_end = mas_x[1];
    int y_end = mas_y[1];

    applyOutColor(p);   // применяем цвет обводки

    p->drawLine(x_start, y_start, x_end, y_end);
}
