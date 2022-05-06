#include "figure.h"

figure::figure(QObject *parent) : QObject(parent)
{

}

void figure::draw(QPainter *p)
{
    Q_UNUSED(p);
}

void figure::setBrushStyle(int newBrushStyle)
{
    brushStyle = newBrushStyle;
}

void figure::choseOutColor()
{
    if(validFlag)   // если предыдущий выбранный цвет валидный, то вызываем диалог выбора следующего цвета
    {
        color_out = QColorDialog::getColor(Qt::white, nullptr, "Выбор цвета обводки");
        if(!color_out.isValid())
        {
            validFlag = false;
        }
    }
}

void figure::choseInColor()
{
    if(validFlag)   // если предыдущий выбранный цвет валидный, то вызываем диалог выбора следующего цвета
    {
        if(brushStyle == Qt::NoBrush)   // если заливка через сплошной цвет
        {
            color_in = QColorDialog::getColor(Qt::white, nullptr, "Выбор цвета заливки");
            if(!color_in.isValid())
            {
                validFlag = false;
            }
        }
    }
}

void figure::applyOutColor(QPainter *p)
{
    if(flagApplyOutColor)
    {
        QPen pen = p->pen();
    //    QPen *pen = new QPen;
        pen.setBrush(QBrush(color_out));
        pen.setWidth(penWidth);

        Qt::PenStyle style = Qt::PenStyle(type_out);
        pen.setStyle(style);
        p->setPen(pen);
    }
    // else - ничего не выполнится
}

void figure::applyInColor(QPainter *p)
{
    if(brushStyle == Qt::NoBrush)   // если тип заливки не выбран
    {
        if(color_in.isValid())
        {
            p->setBrush(QBrush(color_in));  // то устанавливаем сплошной цвет
        }
    }
    else // если выбран стиль
    {
        p->setBrush(Qt::BrushStyle(brushStyle));    // устанавливаем стиль
    }
}

void figure::resizePoints()
{
    if(mas_x != nullptr)
    {
        delete [] mas_x;
        mas_x = nullptr;
    }
    if(mas_y != nullptr)
    {
        delete [] mas_y;
        mas_y = nullptr;
    }


    if(points_count > 0)
    {
        mas_x = new int [points_count];
        mas_y = new int [points_count];
    }
}
