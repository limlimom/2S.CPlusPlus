#ifndef BROKENLINE_H
#define BROKENLINE_H

#include "figure.h"
#include "line.h"

class BrokenLine : public figure
{
public:
    explicit BrokenLine(QObject *parent = nullptr);

    void draw(QPainter *p) override;
};

#endif // BROKENLINE_H
