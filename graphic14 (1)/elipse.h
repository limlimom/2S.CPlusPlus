#ifndef ELIPSE_H
#define ELIPSE_H

#include "figure.h"

class elipse : public figure
{
public:
    elipse();

    void draw(QPainter *p) override;
};

#endif // ELIPSE_H
