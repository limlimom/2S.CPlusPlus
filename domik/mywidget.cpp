#include "mywidget.h"

myWidget::myWidget(QWidget *parent) : QWidget(parent)
{
   //im=QImage(500,500,QImage::Format_ARGB32_Premultiplied);
    im=QImage(1400,1000,QImage::Format_ARGB32_Premultiplied);
}






void myWidget::paintEvent (QPaintEvent *)
{
    QPainter painter (this);


   /* QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    QPen pen; //создали карандаш
    pen.setColor(Qt::red);//цвет
    pen.setWidth(3);// толщина

    painter.setPen(pen); //вручили карандаш художнику

     painter.drawEllipse(30,30,50,50); */

    painter.drawImage(0,0, im);

}
