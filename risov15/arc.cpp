#include "arc.h"

// Конструктор
Arc::Arc()
{
    type = PrimitiveTypes::ArcT;
    pen = new Pen();
    startAngle = 0;
    spanAngle = 0;
}

// Установка начального угла
bool Arc::setStartAngle(int angle)
{
    if (angle < 0 || angle > INT32_MAX) return false;
    startAngle = angle;
    return true;
}

// Установка угла дуги
bool Arc::setSpanAngle(int angle)
{
    if (angle < 0 || angle > INT32_MAX) return false;
    spanAngle = angle;
    return true;
}

// Возвращение начального угла
int Arc::getStartAngle()
{
    return startAngle;
}

// Возвращение угла дуги
int Arc::getSpanAngle()
{
    return spanAngle;
}

// Рисование дуги
void Arc::draw(QImage * im)
{
    QPainter painter(im);

    int r, g, b, a;
    pen->getRGBA(r, g, b, a);
    QPen qpen(QColor(r, g, b, a));
    qpen.setWidth(this->pen->getWeight());
    qpen.setStyle(Qt::PenStyle(this->pen->getStyle()));

    painter.setPen(qpen);
    painter.drawArc(getX() - getRadius1(), getY() - getRadius2(), getRadius1() * 2, getRadius2() * 2, getStartAngle() * 16, getSpanAngle() * 16);
}
