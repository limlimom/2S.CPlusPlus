#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Menu_open_triggered();

    void on_Menu_SaveAs_triggered();

    void on_Menu_Save_triggered();

    void on_Menu_exit_triggered();

    void on_Menu_create_triggered();

    void on_textEdit_textChanged();

    void closeEvent(QCloseEvent *event); //Изменение обработчика закрытия формы

private:
    Ui::MainWindow *ui;
    QString currentFile= "";
    bool fl1=false; //Ввнесены ли в файл изменения
    bool fl2=false; //Сохранен ли файл на компьютере

    bool getFlagSaving();

};

#endif // MAINWINDOW_H
