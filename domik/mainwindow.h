#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void drawHouse(); //рисование картинки с домом

private slots:
    void on_pushButton_clicked();

    void on_pushButton_drawIm_clicked();

    void on_pushButton_Circle_clicked();

    void on_pushButton_delete_all_clicked();

    void on_pushButton_draw_house_clicked();

    void on_pushButton_draw_stars_clicked();

    void on_pushButton_delete_stars_clicked();



protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    bool fl_draw;

};
#endif // MAINWINDOW_H
