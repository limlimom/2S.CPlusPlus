#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <QColorDialog>

class figure : public QObject
{
    Q_OBJECT
public:
    explicit figure(QObject *parent = nullptr);

    int *mas_x = nullptr;
    int *mas_y = nullptr;
    int points_count = 0;   // количество точек (элеменнтов в массиве)
    QColor color_out;
    QColor color_in;
    int radius_1 = 0;
    int radius_2 = 0;
    int type_out = 0;   // тип обводки
    int figure_type = 0;
    int penWidth = 5;
    int angle1 = 0; // углы для дуги
    int angle2 = 0;
    bool validFlag = true;
    int brushStyle = Qt::NoBrush;
    bool flagApplyOutColor = true;  // флаг разрешения применения внешнего цвета

    virtual void draw(QPainter *p);

    void choseOutColor();   // функцция выбора внешнего цвета
    void choseInColor();   // функцция выбора внешнего цвета

    void applyOutColor(QPainter *p);   // применить внешний цвет
    void applyInColor(QPainter *p);    // применить внутренний цвет

    void resizePoints();    // выделить память под массив точек

    void setBrushStyle(int newBrushStyle);

signals:

};

#endif // FIGURE_H
