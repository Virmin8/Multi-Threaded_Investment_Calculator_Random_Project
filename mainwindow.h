#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "investmentcalculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QThread *thread;

private slots:
    void on_pushButton_calculate_clicked();

private:
    Ui::MainWindow *ui;
    void clear();
    InvestmentCalculator* calc;
public slots:
    void sumTotal(double);
};

#endif // MAINWINDOW_H
