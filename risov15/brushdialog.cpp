#include "brushdialog.h"
#include "ui_brushdialog.h"

// Конструктор
BrushDialog::BrushDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrushDialog)
{
    ui->setupUi(this);

    buttonPalette = ui->pushButtonColor->palette();
}

// Деструктор
BrushDialog::~BrushDialog()
{
    delete ui;
}

// Обработчик открытия диалога
void BrushDialog::openDialog(QString title, Brush * newBrushPtr)
{
    // Применяем полученные данные
    ui->labelHeader->setText("Инструмент: " + title);
    brushPtr = newBrushPtr;
    thisBrush = *brushPtr;

    // Применяем на форме значения из карандаша
    ui->comboBoxStyle->setCurrentIndex(brushPtr->getStyle());
    int rr, gg, bb, aa;
    brushPtr->getRGBA(rr, gg, bb, aa);
    buttonPalette.setColor(QPalette::Button, QColor(rr, gg, bb, aa));
    ui->pushButtonColor->setPalette(buttonPalette);

    // Проверка на нулевые первоначальные значения
    if (thisBrush.getStyle() == 0)
    {
        // Если выбрано "Без линии"
        ui->pushButtonColor->hide();
    }

    // Открываем диалог
    exec();
}

// Обработчик выбора стиля карандаша
void BrushDialog::on_comboBoxStyle_activated(int index)
{
    thisBrush.setStyle(index);
    if (index == 0)
    {
        // Если выбрано "Без линии"
        ui->pushButtonColor->hide();
    }
    else
    {
        // Если выбран нормальный стиль
        ui->pushButtonColor->show();
    }
}

// Обработчик получение нового цвета
void BrushDialog::on_pushButtonColor_clicked()
{
    int rr, gg, bb, aa;
    // Загрузка старого цвета и выбор нового
    thisBrush.getRGBA(rr, gg, bb, aa);
    QColor newClr = QColorDialog::getColor(QColor(rr, gg, bb, aa), this, "Выбор цвета");
    if (newClr.isValid())
    {
        // Если выбран корректный цвет, то окрашиваем кнопку в него и устанавливает этот цвет в карандаш
        buttonPalette.setColor(QPalette::Button, newClr);
        ui->pushButtonColor->setPalette(buttonPalette);
        newClr.getRgb(&rr, &gg, &bb, &aa);
        thisBrush.setRGBA(rr, gg, bb, aa);
    }
}

// Обработчик нажатия на "ОК"
void BrushDialog::on_buttonBox_accepted()
{
    *brushPtr = thisBrush;
    close();
}

// Обработчик нажатия на "Отмена"
void BrushDialog::on_buttonBox_rejected()
{
    close();
}
