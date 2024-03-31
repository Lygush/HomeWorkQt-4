#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setText("Percent");
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setText("Current value");

    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);

    ui->pushButton->setText("Ok");
    ui->pushButton->setCheckable(true);

    ui->comboBox->addItem("Black");
    ui->comboBox->addItem("Green");
    ui->comboBox->addItem("Blue");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_clicked()
{
    ui->progressBar->setFormat("%p%");
}


void MainWindow::on_radioButton_2_clicked()
{
     ui->progressBar->setFormat("%v");
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->progressBar->value() == ui->progressBar->maximum()) {
        ui->progressBar->setValue(0);
    }
    else {
    ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->pushButton->setStyleSheet("color: black");
        break;
    case 1:
        ui->pushButton->setStyleSheet("color: green");
        break;
    case 2:
        ui->pushButton->setStyleSheet("color: blue");
        break;
    default:
        break;
    }
}

