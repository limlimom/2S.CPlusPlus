#ifndef MNOGOUGOLNIK_H
#define MNOGOUGOLNIK_H

#include "figure.h"

class mnogougolnik : public figure
{
public:
    explicit mnogougolnik(QObject *parent = nullptr);

    void draw(QPainter *p) override;
};

#endif // MNOGOUGOLNIK_H
