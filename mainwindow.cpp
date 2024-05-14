#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "investmentcalculator.h"
#include <QVariant>
#include <QRegularExpression>//>
#include <QThread>


static QRegularExpression multi ("[0-9]+$");
static QRegularExpression two ("[0-9][0-9]$");


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QValidator *validator = new QRegularExpressionValidator(multi);
    QValidator *validator2 = new QRegularExpressionValidator(two);

    ui->lineEdit_Interest->setValidator(validator2);
    ui->lineEdit_Investment->setValidator(validator);

    thread = new QThread(this);
     calc = new InvestmentCalculator;
     calc->moveToThread(thread);

    connect(thread,SIGNAL(started()),calc,SLOT(process()));
    connect(calc, SIGNAL(numberChange(double)),this,SLOT(sumTotal(double)));
    connect(calc, SIGNAL(finished(double)), this, SLOT(sumTotal(double)));
    connect(calc, SIGNAL(finished(double)), thread, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clear()
{
    ui->lineEdit_Interest->clear();
    ui->lineEdit_Investment->clear();
    ui->spinBox_Years->setValue(0);
    ui->listWidget->clear();

}

void MainWindow::on_pushButton_calculate_clicked()
{

    calc->setYears(ui->spinBox_Years->value());
    QVariant tmp = ui->lineEdit_Interest->text();
    calc->setInterest(tmp.toDouble());
    tmp = ui->lineEdit_Investment->text();
    calc->setinitialAmount(tmp.toDouble());

    thread->start();
    clear();

}
void MainWindow::sumTotal(double number)
{
    QVariant tmp = number;
    ui->listWidget->addItem(tmp.toString());
}
