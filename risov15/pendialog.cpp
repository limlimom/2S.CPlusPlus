#include "pendialog.h"
#include "ui_pendialog.h"

PenDialog::PenDialog(QWidget *parent) : // Конструктор
    QDialog(parent),
    ui(new Ui::PenDialog)
{

    ui->setupUi(this);

    buttonPalette = ui->pushButtonColor->palette();
}

PenDialog::~PenDialog() // Деструктор
{

    delete ui;
}

void PenDialog::openDialog(QString title, Pen * newPenPtr, bool isPixel)  // Обработчик открытия диалога
{

    // Применяем полученные данные
    ui->labelHeader->setText("Инструмент: " + title);
    penPtr = newPenPtr;
    thisPen = *penPtr;
    thisIsPixel = isPixel;

    // Применяем на форме значения из карандаша
    ui->comboBoxStyle->setCurrentIndex(penPtr->getStyle());
    ui->spinBoxWeight->setValue(penPtr->getWeight());
    int rr, gg, bb, aa;
    penPtr->getRGBA(rr, gg, bb, aa);
    buttonPalette.setColor(QPalette::Button, QColor(rr, gg, bb, aa));
    ui->pushButtonColor->setPalette(buttonPalette);

    if (thisPen.getStyle() == 0)
    {
        // Если выбрано "Без линии"
        ui->labelWeight->hide();
        ui->spinBoxWeight->hide();
        ui->pushButtonColor->hide();
    }
    if (isPixel)
    {
        // У точки не должно быть стиля
        ui->labelStyle->hide();
        ui->comboBoxStyle->hide();
    }

    // Открываем диалог
    exec();
}

void PenDialog::on_comboBoxStyle_activated(int index) // Обработчик выбора стиля карандаша
{

    thisPen.setStyle(index);
    if (index == 0)
    {
        // Если выбрано "Без линии"
        ui->labelWeight->hide();
        ui->spinBoxWeight->hide();
        ui->pushButtonColor->hide();
    }
    else
    {
        // Если выбран нормальный стиль
        ui->labelWeight->show();
        ui->spinBoxWeight->show();
        ui->pushButtonColor->show();
    }
}


void PenDialog::on_spinBoxWeight_valueChanged(int arg1) // Обработчик изменения толщины карандаша
{
    thisPen.setWeight(arg1);
}


void PenDialog::on_pushButtonColor_clicked()  // Обработчик получение нового цвета
{

    int rr, gg, bb, aa;
    // Загрузка старого цвета и выбор нового
    thisPen.getRGBA(rr, gg, bb, aa);
    QColor newClr = QColorDialog::getColor(QColor(rr, gg, bb, aa), this, "Выбор цвета");
    if (newClr.isValid())
    {
        // Если выбран корректный цвет, то окрашиваем кнопку в него и устанавливает этот цвет в карандаш
        buttonPalette.setColor(QPalette::Button, newClr);
        ui->pushButtonColor->setPalette(buttonPalette);
        newClr.getRgb(&rr, &gg, &bb, &aa);
        thisPen.setRGBA(rr, gg, bb, aa);
    }
}

void PenDialog::on_buttonBox_accepted()  // ОК
{

    *penPtr = thisPen;
    close();
}


void PenDialog::on_buttonBox_rejected()  // Отмена
{

    close();
}
