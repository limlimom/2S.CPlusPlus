#include "brokenline.h"

BrokenLine::BrokenLine(QObject *parent) : figure(parent)
{

}

void BrokenLine::draw(QPainter *p)
{
//    QPen pen;
//    pen.setBrush(QBrush(color_out));
//    pen.setWidth(penWidth);
//    p->setPen(pen);

    applyOutColor(p);   // применяем цвет обводки

    line *lines_massive = new line [points_count-1];
    for(int i=0; i<points_count-1; i++)
    {
        lines_massive[i].mas_x = new int [2];
        lines_massive[i].mas_y = new int [2];

        lines_massive[i].mas_x[0] = mas_x[i];
        lines_massive[i].mas_y[0] = mas_y[i];
        lines_massive[i].mas_x[1] = mas_x[i+1];
        lines_massive[i].mas_y[1] = mas_y[i+1];

        lines_massive[i].color_out = this->color_out;
        lines_massive[i].penWidth = this->penWidth;
    }

    for(int i=0; i<points_count-1; i++)
    {
//        int x_start = lines_massive[i].mas_x[0];
//        int y_start = lines_massive[i].mas_y[0];

//        int x_end = lines_massive[i].mas_x[1];
//        int y_end = lines_massive[i].mas_y[1];

        lines_massive[i].flagApplyOutColor = false; // Блокирем применение цвета, т.к. он уже применён
        lines_massive[i].draw(p);
    }

    delete [] lines_massive;


}
