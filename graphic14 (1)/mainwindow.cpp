#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    figure_types[0] = "Точка";
    figure_types[1] = "Линия";
    figure_types[2] = "Элипс";
    figure_types[3] = "Прямоугольник";
    figure_types[4] = "Ломаная";
    figure_types[5] = "Многоугольник";
    figure_types[6] = "Дуга";

    for (int i=0; i<7; i++)
    {
        ui->comboBox_ements->addItem(figure_types[i]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_draw_clicked()
{
    int element_type = ui->comboBox_ements->currentIndex();

    bool flag = false;
    int x_start = ui->lineEdit_x_start->text().toInt(&flag);
    if(!flag && ui->lineEdit_x_start->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в координате Х начала");
        return;
    }
    int y_start = ui->lineEdit_y_start->text().toInt(&flag);
    if(!flag && ui->lineEdit_y_start->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в координате Y начала");
        return;
    }

    int x_end = ui->lineEdit_x_end->text().toInt(&flag);
    if(!flag && ui->lineEdit_x_end->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в координате Х конца");
        return;
    }
    int y_end = ui->lineEdit_y_end->text().toInt(&flag);
    if(!flag && ui->lineEdit_y_end->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в координате Y конца");
        return;
    }

    int radius_1 = ui->lineEdit_radius_1->text().toInt(&flag);
    if(!flag && ui->lineEdit_radius_1->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в радиусе 1");
        return;
    }
    int radius_2 = ui->lineEdit_radius_2->text().toInt(&flag);
    if(!flag && ui->lineEdit_radius_2->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в радиусе 2");
        return;
    }
    int penWidth = ui->spinBox_penWidth->value();


    int angle1 = ui->lineEdit_angle_1->text().toInt(&flag);
    if(!flag && ui->lineEdit_angle_1->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в углу 1");
        return;
    }
    int angle2 = ui->lineEdit_angle_2->text().toInt(&flag);
    if(!flag && ui->lineEdit_angle_2->isVisible())
    {
        QMessageBox::information(this, "Ошибка", "Ошибка в углу 2");
        return;
    }

    int penStyle = ui->comboBox_type_out->currentIndex();

    int maxX = ui->widget_draw->width();    // ширина поля для рисования
    int maxY = ui->widget_draw->height();   // высота поля для рисования

    // проверяем точки начала
    if(x_start < 0 || x_start >= maxX)
    {
        QMessageBox::information(this, "Ошибка", "Координата Х начала выходит за допустимый диапазон!");
        return;
    }
    if(y_start < 0 || y_start >= maxY)
    {
        QMessageBox::information(this, "Ошибка", "Координата Y начала выходит за допустимый диапазон!");
        return;
    }

    // проверяем точки начала
    if(x_end < 0 || x_end >= maxX)
    {
        QMessageBox::information(this, "Ошибка", "Координата Х конца выходит за допустимый диапазон!");
        return;
    }
    if(y_end < 0 || y_end >= maxY)
    {
        QMessageBox::information(this, "Ошибка", "Координата Y конца выходит за допустимый диапазон!");
        return;
    }

    // тип зливки
    int brushStyle = ui->comboBox_brushStyle->currentIndex();   // получаем выбранный стиль

    figure *drawFigure = nullptr;


    // точка
    if(element_type == 0)
    {
        drawFigure = new tochka();

        drawFigure->mas_x[0] = x_start;
        drawFigure->mas_y[0] = y_start;

        drawFigure->choseOutColor();
    }
    // линия
    else if (element_type == 1)
    {
        drawFigure = new line();

        drawFigure->mas_x[0] = x_start;
        drawFigure->mas_y[0] = y_start;

        drawFigure->mas_x[1] = x_end;
        drawFigure->mas_y[1] = y_end;

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }

    }
    // элипс
    else if (element_type == 2)
    {
        // проверяем радиусы
        if(x_start - radius_1 - penWidth < 0 || x_start + radius_1 + penWidth >= maxX)
        {
            QMessageBox::information(this, "Ошибка", "Радиус 1 выходит за допустимый диапазон!");
            return;
        }
        if(y_start - radius_2 - penWidth < 0 || y_start + radius_2 + penWidth >= maxY)
        {
            QMessageBox::information(this, "Ошибка", "Радиус 2 выходит за допустимый диапазон!");
            return;
        }

        drawFigure = new elipse();
        drawFigure->setBrushStyle(brushStyle);  // задаём тип заливки

        drawFigure->mas_x[0] = x_start;
        drawFigure->mas_y[0] = y_start;

        drawFigure->radius_1 = radius_1;
        drawFigure->radius_2 = radius_2;

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }
        drawFigure->choseInColor();


    }
    // прямоугольник
    else if (element_type == 3)
    {
        drawFigure = new my_rect();
        drawFigure->setBrushStyle(brushStyle);  // задаём тип заливки

        drawFigure->mas_x[0] = x_start;
        drawFigure->mas_y[0] = y_start;
        drawFigure->mas_x[1] = x_end;
        drawFigure->mas_y[1] = y_end;

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }
        drawFigure->choseInColor();
    }

    // ломаная
    else if (element_type == 4)
    {
        int pointsCount = dialog.getPoints_count();
        if(pointsCount == 0)
        {
            QMessageBox::information(this, "Ошибка", "Точки не заданы!");
            return;
        }
        drawFigure = new BrokenLine();

        drawFigure->points_count = pointsCount;
        drawFigure->mas_x = dialog.getMas_x();
        drawFigure->mas_y = dialog.getMas_y();

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }
    }

    // многоугольник
    else if (element_type == 5)
    {
        int pointsCount = dialog.getPoints_count();
        if(pointsCount == 0)
        {
            QMessageBox::information(this, "Ошибка", "Точки не заданы!");
            return;
        }
        if(pointsCount < 3)
        {
            QMessageBox::information(this, "Ошибка", "Для рисования многоугольника нужно указать минимум 3 точки!");
            return;
        }
        drawFigure = new mnogougolnik();
        drawFigure->setBrushStyle(brushStyle);  // задаём тип заливки

        drawFigure->points_count = pointsCount;
        drawFigure->mas_x = dialog.getMas_x();
        drawFigure->mas_y = dialog.getMas_y();

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }
        drawFigure->choseInColor();
    }

    // дуга
    else if (element_type == 6)
    {
        drawFigure = new Arc();

        drawFigure->mas_x[0] = x_start;
        drawFigure->mas_y[0] = y_start;

        drawFigure->radius_1 = radius_1;
        drawFigure->radius_2 = radius_2;

        drawFigure->angle1 = angle1;
        drawFigure->angle2 = angle2;

        drawFigure->type_out = penStyle;    // тип обводки

        if(penStyle != Qt::NoPen)
        {
            drawFigure->choseOutColor();
        }
    }

    if(drawFigure != nullptr)
    {
        drawFigure->penWidth = penWidth;

        ui->widget_draw->drawsObject = drawFigure;
        ui->widget_draw->repaint();

        if(!drawFigure->validFlag)
        {
            QMessageBox::warning(this, "Ошибка", "Указан невалидный цвет!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Фигура не выбрана");
    }
}

void MainWindow::on_comboBox_ements_currentIndexChanged(int index)
{
    // точка
    if(index == 0)
    {
        // X начала и конца
        ui->label_x_start->setText("Координа Х");
        ui->label_y_start->setText("Координа Y");

        // тип обводки
        ui->label_type_out->hide();
        ui->comboBox_type_out->hide();

        // тип заливки
        ui->label_brushStyle->hide();
        ui->comboBox_brushStyle->hide();

        // Х начала
        ui->label_x_start->show();
        ui->lineEdit_x_start->show();

        // Y начала
        ui->label_y_start->show();
        ui->lineEdit_y_start->show();

        // X конца
        ui->label_x_end->hide();
        ui->lineEdit_x_end->hide();

        // Y конца
        ui->label_y_end->hide();
        ui->lineEdit_y_end->hide();

        // радиус 1
        ui->label_radius_1->hide();
        ui->lineEdit_radius_1->hide();

        // радиус 2
        ui->label_radius_2->hide();
        ui->lineEdit_radius_2->hide();

        // толщина пера
        ui->label_penWidth->hide();
        ui->spinBox_penWidth->hide();

        // массив точек
        ui->label_pointsMassive->hide();
        ui->pushButton_pointsMassive->hide();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // линия
    else if(index == 1)
    {
        // X начала и конца
        ui->label_x_start->setText("Х начала");
        ui->label_y_start->setText("Y начала");

        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->hide();
        ui->comboBox_brushStyle->hide();

        // Х начала
        ui->label_x_start->show();
        ui->lineEdit_x_start->show();

        // Y начала
        ui->label_y_start->show();
        ui->lineEdit_y_start->show();

        // X конца
        ui->label_x_end->show();
        ui->lineEdit_x_end->show();

        // Y конца
        ui->label_y_end->show();
        ui->lineEdit_y_end->show();

        // радиус 1
        ui->label_radius_1->hide();
        ui->lineEdit_radius_1->hide();

        // радиус 2
        ui->label_radius_2->hide();
        ui->lineEdit_radius_2->hide();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->hide();
        ui->pushButton_pointsMassive->hide();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // элипс
    else if(index == 2)
    {
        // X начала и конца
        ui->label_x_start->setText("Координа Х");
        ui->label_y_start->setText("Координа Y");

        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->show();
        ui->comboBox_brushStyle->show();

        // Х начала
        ui->label_x_start->show();
        ui->lineEdit_x_start->show();

        // Y начала
        ui->label_y_start->show();
        ui->lineEdit_y_start->show();

        // X конца
        ui->label_x_end->hide();
        ui->lineEdit_x_end->hide();

        // Y конца
        ui->label_y_end->hide();
        ui->lineEdit_y_end->hide();

        // радиус 1
        ui->label_radius_1->show();
        ui->lineEdit_radius_1->show();

        // радиус 2
        ui->label_radius_2->show();
        ui->lineEdit_radius_2->show();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->hide();
        ui->pushButton_pointsMassive->hide();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // прямоугольник
    else if(index == 3)
    {
        // X начала и конца
        ui->label_x_start->setText("Координа Х");
        ui->label_y_start->setText("Координа Y");

        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->show();
        ui->comboBox_brushStyle->show();

        // Х начала
        ui->label_x_start->show();
        ui->lineEdit_x_start->show();

        // Y начала
        ui->label_y_start->show();
        ui->lineEdit_y_start->show();

        // X конца
        ui->label_x_end->show();
        ui->lineEdit_x_end->show();

        // Y конца
        ui->label_y_end->show();
        ui->lineEdit_y_end->show();

        // радиус 1
        ui->label_radius_1->hide();
        ui->lineEdit_radius_1->hide();

        // радиус 2
        ui->label_radius_2->hide();
        ui->lineEdit_radius_2->hide();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->hide();
        ui->pushButton_pointsMassive->hide();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // ломаная
    else if(index == 4)
    {
        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->hide();
        ui->comboBox_brushStyle->hide();

        // Х начала
        ui->label_x_start->hide();
        ui->lineEdit_x_start->hide();

        // Y начала
        ui->label_y_start->hide();
        ui->lineEdit_y_start->hide();

        // X конца
        ui->label_x_end->hide();
        ui->lineEdit_x_end->hide();

        // Y конца
        ui->label_y_end->hide();
        ui->lineEdit_y_end->hide();

        // радиус 1
        ui->label_radius_1->hide();
        ui->lineEdit_radius_1->hide();

        // радиус 2
        ui->label_radius_2->hide();
        ui->lineEdit_radius_2->hide();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->show();
        ui->pushButton_pointsMassive->show();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // многоугольник
    else if(index == 5)
    {
        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->show();
        ui->comboBox_brushStyle->show();

        // Х начала
        ui->label_x_start->hide();
        ui->lineEdit_x_start->hide();

        // Y начала
        ui->label_y_start->hide();
        ui->lineEdit_y_start->hide();

        // X конца
        ui->label_x_end->hide();
        ui->lineEdit_x_end->hide();

        // Y конца
        ui->label_y_end->hide();
        ui->lineEdit_y_end->hide();

        // радиус 1
        ui->label_radius_1->hide();
        ui->lineEdit_radius_1->hide();

        // радиус 2
        ui->label_radius_2->hide();
        ui->lineEdit_radius_2->hide();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->show();
        ui->pushButton_pointsMassive->show();

        // угол 1
        ui->label_angle_1->hide();
        ui->lineEdit_angle_1->hide();

        // угол 2
        ui->label_angle_2->hide();
        ui->lineEdit_angle_2->hide();
    }
    // дуга
    else if(index == 6)
    {
        // X начала и конца
        ui->label_x_start->setText("Координа Х");
        ui->label_y_start->setText("Координа Y");

        // тип обводки
        ui->label_type_out->show();
        ui->comboBox_type_out->show();

        // тип заливки
        ui->label_brushStyle->hide();
        ui->comboBox_brushStyle->hide();

        // Х начала
        ui->label_x_start->show();
        ui->lineEdit_x_start->show();

        // Y начала
        ui->label_y_start->show();
        ui->lineEdit_y_start->show();

        // X конца
        ui->label_x_end->hide();
        ui->lineEdit_x_end->hide();

        // Y конца
        ui->label_y_end->hide();
        ui->lineEdit_y_end->hide();

        // радиус 1
        ui->label_radius_1->show();
        ui->lineEdit_radius_1->show();

        // радиус 2
        ui->label_radius_2->show();
        ui->lineEdit_radius_2->show();

        // толщина пера
        ui->label_penWidth->show();
        ui->spinBox_penWidth->show();

        // массив точек
        ui->label_pointsMassive->hide();
        ui->pushButton_pointsMassive->hide();

        // угол 1
        ui->label_angle_1->show();
        ui->lineEdit_angle_1->show();

        // угол 2
        ui->label_angle_2->show();
        ui->lineEdit_angle_2->show();
    }
}


void MainWindow::on_pushButton_pointsMassive_clicked()
{
    dialog.exec();  // вызываем диалог
}


void MainWindow::on_comboBox_type_out_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->spinBox_penWidth->hide();
        ui->label_penWidth->hide();
    }
    else
    {
        ui->spinBox_penWidth->show();
        ui->label_penWidth->show();
    }
}

