#include "tochka.h"

tochka::tochka()
{
    points_count = 1;   // для данной фигуры нужна 1 точка
    resizePoints(); // выделяю память под необходимое количество точек
}

void tochka::draw(QPainter *p)
{
    applyOutColor(p);   // применяем цвет обводки

    p->setBrush(color_out);
    p->drawRect(*mas_x, *mas_y, 5, 5);
}
