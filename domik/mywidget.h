#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);
    QImage im;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // MYWIDGET_H
