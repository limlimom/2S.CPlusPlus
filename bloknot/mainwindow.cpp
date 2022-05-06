#include "mainwindow.h"
#include "ui_mainwindow.h"

//конструктор
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

//деструктор
MainWindow::~MainWindow()
{
    delete ui;
}

//кнопка "открыть"
void MainWindow::on_Menu_open_triggered()
{
    if (!fl1) //Если в файл не внесены изменения
    {
        QString fileName=QFileDialog::getOpenFileName(this,"Открыть файл",QDir::currentPath(), tr("Text files (*.txt)"));
        if(fileName == "")
        {
            QMessageBox::warning(this, "Ошибка", "Файл не выбран");
            return;
        }
        if(!fileName.endsWith(".txt"))
        {
            QMessageBox::warning(this, "Ошибка", "Это не txt файл");
            return;
        }
        QFile sFile(fileName);//создаем переменную для файла с названием в переменной file
        if(sFile.open(QFile::ReadOnly | QFile::Text)) //Если файл выбран
        {
            currentFile = fileName; //Текущий файл
            QTextStream in(&sFile);
            in.setCodec("UTF-8"); //Изменение кодировки
            QString text = in.readAll();//чтение
            ui->textEdit->setText(text); //Запись текста
            sFile.close(); //Закрытие
            QStringList parts = fileName.split("/");
            QString lastBit = parts.at(parts.size()-1); //Название файла
            setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
            fl1=false;
            fl2=true;
        }
        else //Если файл не выбран
        {
            QMessageBox::warning(this,"Ошибка","Файл не выбран");
        }
    }
    else //Если в файл внесены изменения
    {
        int r = QMessageBox::warning(this, tr("Выход"),tr("Сохранить изменения?"),QMessageBox::No,QMessageBox::Yes | QMessageBox::Default,QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::Cancel)
        {
            return;
        }
        else if (r== QMessageBox::Yes)

            if(fl2)
            {
                on_Menu_Save_triggered();
                on_Menu_open_triggered();
            }
            else
            {


                QString fileName;//строка для имени файла
                fileName=QFileDialog::getSaveFileName(this,tr("Сохранить файл"),"",tr("Text files(*.txt)"));
                if (fileName.isEmpty())//файл не выбран
                {
                    QMessageBox::warning(this,"Ошибка","Файл не выбран");
                    return;
                }
                else
                {
                    QFile file;//класс файлов
                    file.setFileName(fileName);//связываем с файлом
                    file.open(QIODevice::WriteOnly);//Открываем на запись
                    file.write(ui->textEdit->toPlainText().toUtf8());
                    QString fileName=file.fileName();//Название файла
                    currentFile=fileName;
                    QStringList parts = fileName.split("/");
                    QString lastBit = parts.at(parts.size()-1);//Название файла
                    setWindowTitle(lastBit + " - Блокнот");//название текстового документа с припиской Блокнот
                    fl2=true;//файл сохранен
                    fl1=false;
                }

                fileName=QFileDialog::getOpenFileName(this,"Открыть файл",QDir::currentPath(), tr("Text files (*.txt)"));
                QFile sFile(fileName);
                if(sFile.open(QFile::ReadOnly | QFile::Text))
                {
                    currentFile=fileName;
                    QFile file;//класс файлов
                    file.setFileName(fileName);//связываем с файлом
                    fileName=file.fileName();//название файла
                    QTextStream in(&sFile);
                    in.setCodec("UTF-8"); //Изменение кодировки
                    QString text = in.readAll();//чтение
                    ui->textEdit->setText(text); //Запись текста
                    sFile.close(); //Закрытие
                    QStringList parts = fileName.split("/");
                    QString lastBit = parts.at(parts.size()-1); //Название файла
                    setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
                    fl1=false;
                    fl2=true;
                }
                else
                {
                    QMessageBox::warning(this,"Ошибка","Файл не выбран");
                }

            }

        else if (r == QMessageBox::No)
        {
            QString fileName;//строка для имени файла
            fileName=QFileDialog::getOpenFileName(this,"Открыть файл",QDir::currentPath(), tr("Text files (*.txt)"));
            QFile sFile(fileName);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                currentFile=fileName;
                QFile file;//класс файлов
                file.setFileName(fileName);//связываем с файлом
                fileName=file.fileName();//название файла
                QTextStream in(&sFile);
                in.setCodec("UTF-8"); //Изменение кодировки
                QString text = in.readAll();//чтение
                ui->textEdit->setText(text); //Запись текста
                sFile.close(); //Закрытие
                QStringList parts = fileName.split("/");
                QString lastBit = parts.at(parts.size()-1); //Название файла
                setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
                fl1=false;
                fl2=true;
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Файл не выбран");
            }
        }
    }
}

//обработка закрытия
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!fl1)//если файл не был изменен или был сохранен, то выход без диалогового окна, с предлолжением сохранить документ
    {
        qApp->quit();//закрытие блокнота
    }
    else
    {
        int r = QMessageBox::warning(this, tr("Выход"),tr("Сохранить изменения?"),QMessageBox::No,QMessageBox::Yes | QMessageBox::Default,QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::Cancel)
            event->ignore();
        else if (r == QMessageBox::Yes)
        {
            QString fileName;//строка для имени файла

            fileName=QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::currentPath(),tr("Text files(*.txt)"));//экранируем слеши
            //или
            //fileName=QFileDialog::getOpenFileName(this,tr("Сохранить файл"),"",tr("Text files(*.txt)"));//Linux запись
            if (fileName.isEmpty())//файл не выбран
            {
                //       ui->textEdit->append("Файл не выбран");
                QMessageBox::warning(this,"Ошибка","Файл не выбран");
                event->ignore();//закрываем диалоговое окно
            }
            else
            {
                //       ui->textEdit->append(fileName);
                QFile file;//класс файлов
                file.setFileName(fileName);//связываем с файлом
                file.open(QIODevice::WriteOnly);//Открываем на запись
                file.write(ui->textEdit->toPlainText().toUtf8());//изменение кодировки
                file.close();//закрываем файл
                qApp->quit();//закрытие блокнота

            }
        }
        else if (r == QMessageBox::No)
        {
            qApp->quit();//закрытие блокнота
        }
    }
}

//проверка на сохранение
bool MainWindow::getFlagSaving()
{
    QString currentText = ui->textEdit->toPlainText();
    QFile fileSaving(currentFile);
    bool flagSaving = true;
    if(fileSaving.open(QIODevice::ReadOnly))
    {
        QString fileSavingText = fileSaving.readAll();
        fileSaving.close();
        if(fileSavingText == currentText)
        {
            flagSaving = false;
        }
    }
    return flagSaving;
}

//кнопка "сохранить как"
void MainWindow::on_Menu_SaveAs_triggered()
{
    QString fileName;//строка для имени файла
    fileName=QFileDialog::getSaveFileName(this,tr("Сохранение"),QDir::currentPath(),tr("Text files(*.txt)"));
    if (fileName.isEmpty())//файл не выбран
    {
        QMessageBox::warning(this,"Ошибка","Файл не выбран");
    }
    else
    {
        QFile file; //Класс файлов
        file.setFileName(fileName); //Связываем с файлом
        file.open(QIODevice::WriteOnly); //Только на запись
        file.write(ui->textEdit->toPlainText().toUtf8()); //Запись в файл
        fl1 = false;
        fl2 = true;
        file.close(); //Закрываем файл
        QStringList parts = fileName.split("/");
        QString lastBit = parts.at(parts.size()-1); //Название файла
        setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
        currentFile = fileName; //Текущий файл
    }
}

//кнопка "сохранить"
void MainWindow::on_Menu_Save_triggered()
{
    if(fl2) //Если файл сохранен на компьютере
    {
        QFile sFile(currentFile);
        if (sFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&sFile);
            out.setCodec("UTF-8"); //Изменение кодировки

            out<< ui->textEdit->toPlainText();//сохранение текста

            sFile.flush();
            sFile.close();//закрываем файл


            QStringList parts = currentFile.split("/");
            QString lastBit = parts.at(parts.size()-1); //Название файла
            setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
            fl1=false;
        }
    }
    else  //Если файл не сохранен на компьютере
    {
        on_Menu_SaveAs_triggered();
    }
}

//кнопка "выход"
void MainWindow::on_Menu_exit_triggered()
{
    if(!fl1)//если файл не был изменен или был сохранен, то выход без диалогового окна, с предлолжением сохранить документ
    {
        qApp->quit();//закрытие блокнота
    }
    else
    {
        int r = QMessageBox::warning(this, tr("Выход"),tr("Сохранить изменения?"),QMessageBox::No,QMessageBox::Yes | QMessageBox::Default,QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::Cancel)
            return;
        else if (r == QMessageBox::Yes)
        {
            QString fileName;//строка для имени файла

            fileName=QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::currentPath(),tr("Text files(*.txt)"));//экранируем слеши
            //или
            //fileName=QFileDialog::getOpenFileName(this,tr("Сохранить файл"),"",tr("Text files(*.txt)"));//Linux запись
            if (fileName.isEmpty())//файл не выбран
            {
                QMessageBox::warning(this,"Ошибка","Файл не выбран");
                return;
            }
            else
            {
                //       ui->textEdit->append(fileName);
                QFile file;//класс файлов
                file.setFileName(fileName);//связываем с файлом
                file.open(QIODevice::WriteOnly);//Открываем на запись
                file.write(ui->textEdit->toPlainText().toUtf8());//изменение кодировки
                file.close();//закрываем файл
                qApp->quit();//закрытие блокнота
            }
        }
        else if (r == QMessageBox::No)
        {
            qApp->quit();//закрытие блокнота
        }
    }
}

//кнопка "создать"
void MainWindow::on_Menu_create_triggered()
{
    fl2=false;//созданный пока еще не сохранен, поэтому false
    if (!fl1)
    {
        currentFile.clear();//очищаем текущий файл
        ui->textEdit->setText("");//очищаем текущий файл
        fl1=false;//true для выхода без диалогового окна с предложением сохранить
    }
    else
    {
        bool flagSaving = getFlagSaving();
        if(flagSaving)
        {
            int r = QMessageBox::warning(this, tr("Выход"),tr("Сохранить изменения?"),QMessageBox::No,QMessageBox::Yes | QMessageBox::Default,QMessageBox::Cancel | QMessageBox::Escape);
            if (r == QMessageBox::Cancel)
            {
                return;
            }
            else if (r== QMessageBox::Yes)
            {
                QString fileName;//строка для имени файла
                fileName=QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::currentPath(),tr("Text files(*.txt)"));//экранируем слеши
                if (fileName.isEmpty())//файл не выбран
                {
                    QMessageBox::warning(this,"Ошибка","Файл не выбран");
                }
                else
                {
                    QFile file;//класс файлов
                    file.setFileName(fileName);//связываем с файлом
                    file.open(QIODevice::WriteOnly);//Открываем на запись
                    file.write(ui->textEdit->toPlainText().toUtf8());//меняем кодировку
                    currentFile.clear();//очищаем текущий файл
                    ui->textEdit->setText("");//очищаем текущий файл
                    fl1=false;//true для выхода без диалогового окна с предложением сохранить
                }
            }
        }

        currentFile.clear();//очищаем текущий файл
        ui->textEdit->setText("");//создаем пустой блокнот
        fl1=false;//true для выхода без диалогового окна с предложением сохранить
    }
}

//изменение текста
void MainWindow::on_textEdit_textChanged()
{
    if (fl2) //Если файл сохранен на компьютере
    {
        QStringList parts = currentFile.split("/");
        QString lastBit = parts.at(parts.size()-1); //Название файла
        if(getFlagSaving())
        {
            setWindowTitle("*"+lastBit + " - Блокнот"); //Изменение названия окна
        }
        else
        {
            setWindowTitle(lastBit + " - Блокнот"); //Изменение названия окна
        }
        fl1 = true;
    }
    else //Если файл не сохранен на компьютере
    {
        if (ui->textEdit->toPlainText().isEmpty()) //Если файл пустой
        {
            this->setWindowTitle("Безымянный - Блокнот"); //Изменение названия окна
            fl1 = false;
        }
        else //Если в файле есть текст
        {
            this->setWindowTitle("*Безымянный - Блокнот"); //Изменение названия окна
            fl1 = true;
        }
    }

}
