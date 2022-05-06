#include "dialogchosepoints.h"
#include "ui_dialogchosepoints.h"

DialogChosePoints::DialogChosePoints(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChosePoints)
{
    ui->setupUi(this);

    ui->tableWidget_points->setRowCount(3);
}

DialogChosePoints::~DialogChosePoints()
{
    delete ui;
}

void DialogChosePoints::on_pushButton_add_clicked()
{
    // увеличиваем количество точек на 1
    int rowsCount = ui->tableWidget_points->rowCount();
    rowsCount++;
    ui->tableWidget_points->setRowCount(rowsCount);
}


void DialogChosePoints::on_pushButton_remove_clicked()
{
    // уменьшаем количество точек на 1
    int rowsCount = ui->tableWidget_points->rowCount();
    if(rowsCount > 0)
    {
        rowsCount--;
        ui->tableWidget_points->setRowCount(rowsCount);
    }
}


void DialogChosePoints::on_pushButton_apply_clicked()
{
    // очищаем старые данные
    if(mas_x != nullptr)
        delete [] mas_x;
    if(mas_y != nullptr)
        delete [] mas_y;

    points_count = 0;

    // получаем новые данные
    points_count = ui->tableWidget_points->rowCount();  // количетсво точек равно количеству строк в таблице
    if(points_count == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Вы не ввели точки");
        return;
    }
    mas_x = new int [points_count];
    mas_y = new int [points_count];
    for (int i=0; i<points_count; i++)
    {
        QTableWidgetItem *item_x = ui->tableWidget_points->item(i, 0);
        QTableWidgetItem *item_y = ui->tableWidget_points->item(i, 1);
        int x = 0, y = 0;
        if(item_x != nullptr && item_y != nullptr)
        {
            bool flag1 = false;
            bool flag2 = false;

            x = item_x->text().toInt(&flag1);
            y = item_y->text().toInt(&flag2);

            if(!flag1 || !flag2)
            {
                if(!flag1)
                {
                   QMessageBox::information(this, "Ошибка", "Ошибка в координате Х в строке " + QString::number(i+1));
                }
                else if (!flag2)
                {
                    QMessageBox::information(this, "Ошибка", "Ошибка в координате Y в строке " + QString::number(i+1));
                }
                points_count = 0;
                delete [] mas_x;
                delete [] mas_y;

                mas_x = nullptr;
                mas_y = nullptr;

                return;
            }
        }
        else    // если память хотя бы под одну ячейку не выделена
        {
            if(item_x == nullptr)
            {
               QMessageBox::information(this, "Ошибка", "Ошибка в координате Х в строке " + QString::number(i+1));
            }
            else if (item_y == nullptr)
            {
                QMessageBox::information(this, "Ошибка", "Ошибка в координате Y в строке " + QString::number(i+1));
            }
            points_count = 0;
            delete [] mas_x;
            delete [] mas_y;

            mas_x = nullptr;
            mas_y = nullptr;

            return;
        }

        mas_x[i] = x;
        mas_y[i] = y;
    }

    this->close();
}

int DialogChosePoints::getPoints_count() const
{
    return points_count;
}

int *DialogChosePoints::getMas_y() const
{
    int *mas_y_copy = new int [points_count];
    for (int i=0; i<points_count; i++)
    {
        mas_y_copy[i] = mas_y[i];
    }
    return mas_y_copy;
}

int* DialogChosePoints::getMas_x() const
{
    int *mas_x_copy = new int [points_count];
    for (int i=0; i<points_count; i++)
    {
        mas_x_copy[i] = mas_x[i];
    }
    return mas_x_copy;
}


void DialogChosePoints::on_pushButton_cancel_clicked()
{
    this->close();
}

