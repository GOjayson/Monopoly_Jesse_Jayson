#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <dice.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/jesse/OneDrive/Afbeeldingen/monopolyBord.jpg");
    int w = ui->label_Board->width();
    int h = ui->label_Board->height();
    ui->label_Board->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDice_clicked()
{
   // ui->dice();
}
