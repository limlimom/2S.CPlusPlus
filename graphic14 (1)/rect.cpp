#include "rect.h"

my_rect::my_rect(QObject *parent) : figure(parent)
{
    points_count = 2;   // для данной фигуры нужна 1 точка
    resizePoints(); // выделяю память под необходимое количество точек
}

void my_rect::draw(QPainter *p)
{
    applyOutColor(p);   // применяем цвет обводки
    applyInColor(p);  // применяем цвет внутренней заливки


    int x = mas_x[0];   // x начала
    int y = mas_y[0];   // y начала
    int w = mas_x[1] - mas_x[0];    // ширина
    int h = mas_y[1] - mas_y[0];    // высота
    p->drawRect(x, y, w, h);

}
