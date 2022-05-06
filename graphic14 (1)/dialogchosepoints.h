#ifndef DIALOGCHOSEPOINTS_H
#define DIALOGCHOSEPOINTS_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DialogChosePoints;
}

class DialogChosePoints : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChosePoints(QWidget *parent = nullptr);
    ~DialogChosePoints();

    int *getMas_x() const;

    int *getMas_y() const;

    int getPoints_count() const;

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_apply_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DialogChosePoints *ui;

    int *mas_x = nullptr;
    int *mas_y = nullptr;
    int points_count = 0;
};

#endif // DIALOGCHOSEPOINTS_H
