#ifndef TOCHKA_H
#define TOCHKA_H

#include <figure.h>

class tochka : public figure
{
public:
    tochka();

    void draw(QPainter *p) override;
};

#endif // TOCHKA_H
