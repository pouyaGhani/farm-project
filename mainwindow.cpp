#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signuppage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(880,630);
}

MainWindow::~MainWindow()
{
    delete ui;
}

