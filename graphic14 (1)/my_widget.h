#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include "figure.h"

class my_widget : public QWidget
{
    Q_OBJECT
public:
    explicit my_widget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);

    figure *drawsObject = nullptr;

signals:

};

#endif // MY_WIDGET_H
