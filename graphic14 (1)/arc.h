#ifndef ARC_H
#define ARC_H

#include "figure.h"

class Arc : public figure
{
public:
    explicit Arc(QObject *parent = nullptr);

    void draw(QPainter *p) override;
};

#endif // ARC_H
