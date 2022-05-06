#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPaintEvent"
#include <QColor>
#include <QMessageBox>
#include "QPixmap"
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_delete_stars->setEnabled(false);
    ui->pushButton_draw_stars->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    fl_draw = false;

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::drawHouse() //рисование дома
{
    QPainter painter (&ui->widget->im); //куда делать "вывод"
    {

                QPoint rect[4]; //небо
                rect[0].setX(0);
                rect[0].setY(0);
                rect[1].setX(1000);
                rect[1].setY(0);
                rect[2].setX(1000);
                rect[2].setY(400);
                rect[3].setX(0);
                rect[3].setY(400);


                QBrush brush;
                QPen pen;

                QColor sky; //цвет неба
                sky.setRgb(0,47,85);

                pen.setColor(sky);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(10);
                painter.setPen(pen);

                brush.setColor(sky);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);


             {
                //земля

                rect[0].setX(0);
                rect[0].setY(400);
                rect[1].setX(1000);
                rect[1].setY(400);
                rect[2].setX(1000);
                rect[2].setY(1000);
                rect[3].setX(0);
                rect[3].setY(1000);

                QBrush brush;
                QPen pen;

                QColor ground; //цвет земли
                ground.setRgb(0,69,36);

                pen.setColor(ground);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(10);
                painter.setPen(pen);

                brush.setColor(ground);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);
             }

             {
                //дом

                    rect[0].setX(100);
                    rect[0].setY(150);
                    rect[1].setX(400);
                    rect[1].setY(150);
                    rect[2].setX(400);
                    rect[2].setY(500);
                    rect[3].setX(100);
                    rect[3].setY(500);

                    QBrush brush;
                    QPen pen;

                    QColor house; //цвет дома
                    house.setRgb(138,102,66);

                    pen.setColor(Qt::black);
                    pen.setStyle(Qt::SolidLine);
                    pen.setWidth(5);
                    painter.setPen(pen);

                    brush.setColor(house);
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);

                    painter.drawPolygon(rect,4,Qt::OddEvenFill);
             }

             {
                //крыша

                rect[0].setX(50);
                rect[0].setY(150);
                rect[1].setX(250);
                rect[1].setY(50);
                rect[2].setX(450);
                rect[2].setY(150);

                QBrush brush;
                QPen pen;

                QColor roof; //цвет крыши
                roof.setRgb(80,61,51);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);

                brush.setColor(roof);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,3,Qt::OddEvenFill);
             }

             {
                //дверь

                rect[0].setX(150);
                rect[0].setY(320);
                rect[1].setX(250);
                rect[1].setY(320);
                rect[2].setX(250);
                rect[2].setY(500);
                rect[3].setX(150);
                rect[3].setY(500);

                QBrush brush;
                QPen pen;
                QColor door; //цвет двери
                door.setRgb(65,74,76);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);

                brush.setColor(door);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);
             }

             {
                //крыльцо
                //1 ступенька


                rect[0].setX(150);
                rect[0].setY(480);
                rect[1].setX(250);
                rect[1].setY(480);
                rect[2].setX(250);
                rect[2].setY(490);
                rect[3].setX(150);
                rect[3].setY(490);

                QBrush brush;
                QPen pen;
                QColor stairs; //цвет лестницы
                stairs.setRgb(68,45,37);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);

                brush.setColor(stairs);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);

                //2 ступенька
                rect[0].setX(150);
                rect[0].setY(490);
                rect[1].setX(250);
                rect[1].setY(490);
                rect[2].setX(250);
                rect[2].setY(500);
                rect[3].setX(150);
                rect[3].setY(500);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);

                brush.setColor(stairs);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4 ,Qt::OddEvenFill);

                //3 ступенька
                rect[0].setX(150);
                rect[0].setY(500);
                rect[1].setX(250);
                rect[1].setY(500);
                rect[2].setX(250);
                rect[2].setY(510);
                rect[3].setX(150);
                rect[3].setY(510);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);

                brush.setColor(stairs);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4 ,Qt::OddEvenFill);
             }


            {
                //дверная рчука
                QPen pen;
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(10);
                painter.setPen(pen);

                painter.drawLine(175, 400, 175, 410);
            }

            {

                // 1 окно
                rect[0].setX(150);
                rect[0].setY(200);
                rect[1].setX(250);
                rect[1].setY(200);
                rect[2].setX(250);
                rect[2].setY(275);
                rect[3].setX(150);
                rect[3].setY(275);

                QBrush brush;
                QPen pen;

                QColor window_col1; //цвет окна
                window_col1.setRgb(26,21,63);
                QColor window_col2; //цвет окна
                window_col2.setRgb(255,223,132);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);


                brush.setColor(window_col1);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);

                // 2 окно
                rect[0].setX(285);
                rect[0].setY(200);
                rect[1].setX(380);
                rect[1].setY(200);
                rect[2].setX(380);
                rect[2].setY(275);
                rect[3].setX(285);
                rect[3].setY(275);

                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                pen.setWidth(5);
                painter.setPen(pen);


                brush.setColor(window_col1);
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);

                painter.drawPolygon(rect,4,Qt::OddEvenFill);

            // 3 окно
                    rect[0].setX(285);
                    rect[0].setY(350);
                    rect[1].setX(380);
                    rect[1].setY(350);
                    rect[2].setX(380);
                    rect[2].setY(420);
                    rect[3].setX(285);
                    rect[3].setY(420);

                    pen.setColor(Qt::black);
                    pen.setStyle(Qt::SolidLine);
                    pen.setWidth(5);
                    painter.setPen(pen);


                    brush.setColor(window_col2);
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);


                    //paint.drawLine(350,350,300,300);
                    painter.drawPolygon(rect,4,Qt::OddEvenFill);
                    painter.drawLine(300,350,350,350);

            }



     }

}






void MainWindow::on_pushButton_clicked()
{
    fl_draw=!false;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *)
{

    if (fl_draw)
    {
        QPainter painter (this); //создали художника
        QPen pen; //создали карандаш
        pen.setColor(Qt::green);//цвет
        pen.setWidth(5);// толщина
        pen.setStyle(Qt::DotLine);//стиль
        pen.setCapStyle(Qt::RoundCap); //закругление
        painter.setPen(pen); //вручили карандаш художнику
        painter.drawLine(50,50,150,200); //нарисовали линию
    }
}

void MainWindow::on_pushButton_drawIm_clicked()
{
    QPainter painter (&ui->widget->im);
    painter.drawLine(30,90,0,300);
    repaint();

}

void MainWindow::on_pushButton_Circle_clicked()
{
    QPainter painter (&ui->widget->im);
    painter.drawEllipse(100,100,20,20);
    repaint();

}


void MainWindow::on_pushButton_draw_house_clicked() //при нажатии кнопки "Нарисовать дом"
{

    drawHouse(); //вызов функции рисования дома


    ui->pushButton_draw_stars->setEnabled(true); // после появления рисунка можно рисовать звезды, делаем активной кнопку звезд
    ui->lineEdit->setEnabled(true); // после появления рисунка позволяем пользователю нарисовать звезды
    repaint();

}

void MainWindow::on_pushButton_draw_stars_clicked() //при нажатии кнопки "Нарисовать звезды"
{



    bool ok = false;

    int size = ui->lineEdit->text().toInt(&ok); //получение количества звезд и его преобразование
    if ((size < 0)) //проверка полученного числа звезд на отрицательные
    {

        QMessageBox::information(this, "Ошибка", "Меньше 1 добавить нельзя");//сообщение об ошибке
        return;
    }

    if (!ok)  //проверка успешности чтения/преобразования количества значений
    {
        QMessageBox::information(this, "Ошибка", "Введите корректное число");//сообщение об ошибке
        return;                     //выход из процедуры при ошибке данных
    }
    if (size > 100000) //задание максимального количества добавляемых звезд
    {
        QMessageBox::information(this,"Ошибка", "Максимальное количество звезд - "  + QString::number(100000));
        return;
    }



    int i;  int p=0;
    for(i=0;i<size;i++) // цикл для формирования координат звезды
    {
        int  x=1+rand()%1000;  //рандомное формирование координаты X
        int y=1+rand()%400;   //рандомное формирование координаты Y

        while (!(QColor(ui->widget->im.pixel(x,y))==QColor(0,47,85)))  //   проверка отображения звезд только на небе
        {



            x=1+rand()%1000; //рандомное формирование координаты X  пока точка не попадет на небо
            y=1+rand()%400;  //рандомное формирование координаты Y  пока точка не попадет на небо

            p++;
            if (p>=1000000) //если попыток поиска координат более 1000000, то выдать ошибку
            {
                if (QMessageBox::question(this,"Внимание!", "Достигнуто максимальное количество звезд.\n" "Очистить небо?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) //при практически полность заполненном небе
                {
                    //если пользователь выбрал Yes
                    //drawHouse(); //убираем звезды
                }
                return;
            }

        }
        (ui->widget->im.setPixelColor(x,y, QColor(Qt::yellow)));  //отображение точки на рисунке

    }

    ui->pushButton_delete_stars->setEnabled(true); //после создания звезд их можно будет удалить, открываем доступ к этой кнопке

    repaint();  //перерисовка формы

}


void MainWindow::on_pushButton_delete_stars_clicked() //при нажатии кнопки "удалить звезды"
{


    drawHouse(); //вызов функции отрисовки дома

    repaint(); //перерисовка формы

}


//https://colorscheme.ru/html-colors.html


void MainWindow::on_pushButton_delete_all_clicked() //при нажатии кнопки "удалить все"
{
    ui->widget->im.fill(0);

    ui->pushButton_delete_stars->setEnabled(false); //звезд нет, удалять нечего, делаем кнопку неактивной
    ui->pushButton_draw_stars->setEnabled(false);  //рисунка нет, зведы рисовать не на чем, делаем кнопку неактивной
    ui->lineEdit->clear();
    ui->lineEdit->setEnabled(false);
    repaint();
}
