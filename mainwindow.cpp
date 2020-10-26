#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QSizePolicy>
#include <QScrollArea>
#include <dice.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pix("C:/Users/jesse/OneDrive/Afbeeldingen/monopolyBoard.jpg")
{
    ui->setupUi(this);

 /*   int w = ui->label_Board->width();
    int h = ui->label_Board->height();
    ui->label_Board->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));*/

    ui->label_Board->setPixmap (pix);
    ui->label_Board->setScaledContents(true);
    QScrollArea *scrollArea = new QScrollArea();

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(ui->label_Board);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}


