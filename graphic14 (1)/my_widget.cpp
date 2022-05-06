#include "my_widget.h"

my_widget::my_widget(QWidget *parent) : QWidget(parent)
{
}

void my_widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(drawsObject != nullptr)
    {
        if(drawsObject->validFlag)
        {
            // цвет валидный, рисуем
            drawsObject->draw(&painter); // вызываем функцию рисования
        }
        else
        {
            // игноририруем и ничего не рисуем
        }
    }
    e->accept();
}
