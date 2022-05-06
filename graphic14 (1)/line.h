#ifndef LINE_H
#define LINE_H

#include "figure.h"

class line : public figure
{
public:
    line();

    void draw(QPainter *p) override;
};

#endif // LINE_H
