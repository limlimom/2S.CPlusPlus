#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure.h"
#include "tochka.h"
#include <QColorDialog>
#include "line.h"
#include "elipse.h"
#include "rect.h"
#include "brokenline.h"
#include "dialogchosepoints.h"
#include "mnogougolnik.h"
#include "arc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString figure_types[7];

private slots:
    void on_pushButton_draw_clicked();

    void on_comboBox_ements_currentIndexChanged(int index);

    void on_pushButton_pointsMassive_clicked();

    void on_comboBox_type_out_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    DialogChosePoints dialog;
};
#endif // MAINWINDOW_H
