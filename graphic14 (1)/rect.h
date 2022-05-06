#ifndef RECT_H
#define RECT_H

#include "figure.h"

class my_rect : public figure
{
public:
    explicit my_rect(QObject *parent = nullptr);

    void draw(QPainter *p) override; // рисование прямоугольника
};

#endif // RECT_H
