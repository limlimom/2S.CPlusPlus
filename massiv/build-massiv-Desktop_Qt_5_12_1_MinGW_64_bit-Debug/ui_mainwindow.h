/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QPushButton *pushButtonRandom;
    QPushButton *pushButtonSum;
    QLabel *labelResult;
    QPushButton *pushButtonMin;
    QPushButton *pushButtonMax;
    QPushButton *pushButtonAverage;
    QPushButton *pushButtonSort1;
    QPushButton *pushButtonSort2;
    QPushButton *pushButtonSort3;
    QPushButton *pushButtonSort4;
    QPushButton *pushButtonSort5;
    QPushButton *pushButtonCopies;
    QPushButton *pushButtonSearch1;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonSearch2;
    QPushButton *pushButtonOpenText;
    QPushButton *pushButtonSaveBin;
    QPushButton *pushButtonOpenBin;
    QPushButton *pushButtonSaveText;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(798, 627);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(190, 20, 71, 31));
        spinBox->setMinimum(1);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 151, 531));
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(1);
        pushButtonRandom = new QPushButton(centralwidget);
        pushButtonRandom->setObjectName(QString::fromUtf8("pushButtonRandom"));
        pushButtonRandom->setGeometry(QRect(190, 60, 121, 41));
        pushButtonSum = new QPushButton(centralwidget);
        pushButtonSum->setObjectName(QString::fromUtf8("pushButtonSum"));
        pushButtonSum->setGeometry(QRect(190, 110, 121, 41));
        labelResult = new QLabel(centralwidget);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        labelResult->setGeometry(QRect(327, 109, 131, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelResult->setFont(font);
        pushButtonMin = new QPushButton(centralwidget);
        pushButtonMin->setObjectName(QString::fromUtf8("pushButtonMin"));
        pushButtonMin->setGeometry(QRect(190, 160, 121, 41));
        pushButtonMax = new QPushButton(centralwidget);
        pushButtonMax->setObjectName(QString::fromUtf8("pushButtonMax"));
        pushButtonMax->setGeometry(QRect(190, 210, 121, 41));
        pushButtonAverage = new QPushButton(centralwidget);
        pushButtonAverage->setObjectName(QString::fromUtf8("pushButtonAverage"));
        pushButtonAverage->setGeometry(QRect(190, 260, 121, 41));
        pushButtonSort1 = new QPushButton(centralwidget);
        pushButtonSort1->setObjectName(QString::fromUtf8("pushButtonSort1"));
        pushButtonSort1->setGeometry(QRect(190, 310, 121, 41));
        pushButtonSort2 = new QPushButton(centralwidget);
        pushButtonSort2->setObjectName(QString::fromUtf8("pushButtonSort2"));
        pushButtonSort2->setGeometry(QRect(190, 360, 121, 41));
        pushButtonSort3 = new QPushButton(centralwidget);
        pushButtonSort3->setObjectName(QString::fromUtf8("pushButtonSort3"));
        pushButtonSort3->setGeometry(QRect(190, 410, 121, 41));
        pushButtonSort4 = new QPushButton(centralwidget);
        pushButtonSort4->setObjectName(QString::fromUtf8("pushButtonSort4"));
        pushButtonSort4->setGeometry(QRect(190, 460, 121, 41));
        pushButtonSort5 = new QPushButton(centralwidget);
        pushButtonSort5->setObjectName(QString::fromUtf8("pushButtonSort5"));
        pushButtonSort5->setGeometry(QRect(190, 510, 121, 41));
        pushButtonCopies = new QPushButton(centralwidget);
        pushButtonCopies->setObjectName(QString::fromUtf8("pushButtonCopies"));
        pushButtonCopies->setGeometry(QRect(480, 100, 141, 51));
        pushButtonSearch1 = new QPushButton(centralwidget);
        pushButtonSearch1->setObjectName(QString::fromUtf8("pushButtonSearch1"));
        pushButtonSearch1->setGeometry(QRect(480, 170, 141, 51));
        lineEditSearch = new QLineEdit(centralwidget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));
        lineEditSearch->setGeometry(QRect(630, 180, 141, 31));
        QFont font1;
        font1.setPointSize(10);
        lineEditSearch->setFont(font1);
        pushButtonSearch2 = new QPushButton(centralwidget);
        pushButtonSearch2->setObjectName(QString::fromUtf8("pushButtonSearch2"));
        pushButtonSearch2->setGeometry(QRect(480, 230, 141, 51));
        pushButtonOpenText = new QPushButton(centralwidget);
        pushButtonOpenText->setObjectName(QString::fromUtf8("pushButtonOpenText"));
        pushButtonOpenText->setGeometry(QRect(480, 370, 111, 41));
        pushButtonSaveBin = new QPushButton(centralwidget);
        pushButtonSaveBin->setObjectName(QString::fromUtf8("pushButtonSaveBin"));
        pushButtonSaveBin->setGeometry(QRect(610, 320, 111, 41));
        pushButtonOpenBin = new QPushButton(centralwidget);
        pushButtonOpenBin->setObjectName(QString::fromUtf8("pushButtonOpenBin"));
        pushButtonOpenBin->setGeometry(QRect(610, 370, 111, 41));
        pushButtonSaveText = new QPushButton(centralwidget);
        pushButtonSaveText->setObjectName(QString::fromUtf8("pushButtonSaveText"));
        pushButtonSaveText->setGeometry(QRect(480, 320, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        pushButtonRandom->setText(QApplication::translate("MainWindow", "Random", nullptr));
        pushButtonSum->setText(QApplication::translate("MainWindow", "Sum", nullptr));
        labelResult->setText(QString());
        pushButtonMin->setText(QApplication::translate("MainWindow", "Minimum", nullptr));
        pushButtonMax->setText(QApplication::translate("MainWindow", "Maximum", nullptr));
        pushButtonAverage->setText(QApplication::translate("MainWindow", "Average", nullptr));
        pushButtonSort1->setText(QApplication::translate("MainWindow", "Bubble sort", nullptr));
        pushButtonSort2->setText(QApplication::translate("MainWindow", "Gnome sort", nullptr));
        pushButtonSort3->setText(QApplication::translate("MainWindow", "Quick sort", nullptr));
        pushButtonSort4->setText(QApplication::translate("MainWindow", "Comb sort", nullptr));
        pushButtonSort5->setText(QApplication::translate("MainWindow", "Bogosort", nullptr));
        pushButtonCopies->setText(QApplication::translate("MainWindow", "Delete copies (sort)", nullptr));
        pushButtonSearch1->setText(QApplication::translate("MainWindow", "Linear search", nullptr));
        lineEditSearch->setText(QString());
        pushButtonSearch2->setText(QApplication::translate("MainWindow", "Binary search (sort)", nullptr));
        pushButtonOpenText->setText(QApplication::translate("MainWindow", "Open Text", nullptr));
        pushButtonSaveBin->setText(QApplication::translate("MainWindow", "Save Bin", nullptr));
        pushButtonOpenBin->setText(QApplication::translate("MainWindow", "Open Bin", nullptr));
        pushButtonSaveText->setText(QApplication::translate("MainWindow", "Save Text", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
