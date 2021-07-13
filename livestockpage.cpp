#include "livestockpage.h"
#include "ui_livestockpage.h"

LivestockPage::LivestockPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LivestockPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    ui->label->setText(QString::number(livestock->Get_level()));
    ui->label_2->setText(QString::number(livestock->Get_used_storage()) + "/" + QString::number(livestock->Get_total_storage()));
    ui->label_3->setText(QString::number(livestock->Get_feeding_timer()));
}

LivestockPage::~LivestockPage()
{
    delete ui;
}

void LivestockPage::on_pushButton_clicked()
{
    switch (livestock->Build()){
    case 1:
        //qmessagebox --> "livestock is locked"
        QMessageBox::critical(this,"LOCKED","livestock is still locked");
        break;
    case 2:
        //qmessagebox --> "not enough coins for building livestock"
        QMessageBox::critical(this,"COINS","not enough coins for building livestock");
        break;
    case 3:
        //qmessagebox --> "not enough nails for building livestock"
        QMessageBox::critical(this,"NAILS","not enough nails for building livestock");
        break;
    case 4:
        //qmessagebox --> "not enough shovels for building livestock"
        QMessageBox::critical(this,"SHOVELS","not enough shovels for building livestock");
        break;
    case 5:
        //qmessagebox --> "timer set for building"
        QMessageBox::information(this,"START","timer set for building");
        break;
    }
}


void LivestockPage::on_pushButton_2_clicked()
{

    switch(livestock->Upgrade()){
    case 1:
        //qmessagebox --> "livestock is not built yet"
        QMessageBox::critical(this,"NOT BUILT","livestock is not built yet");
        break;
    case 2:
        //qmessagebox --> "to upgrade you have to wait until feeding timer finishes and collect milks"
        QMessageBox::critical(this,"FEEDING OR PRODUCT READY","to upgrade you have to wait until feeding timer finishes and collect milks");
        break;
    case 3:
        //qmessagebox --> "you cannot upgrade livestock until you reach level 5"
        QMessageBox::critical(this,"LEVEL","livestock is not built yet");
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading");
        break;
    case 5:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAILS","not enough nails for upgrading");
        break;
    case 6:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::informaStion(this,"START","timer set for upgrading");
        break;
    }
}


void LivestockPage::on_pushButton_3_clicked()
{
    switch(livestock->Feed()){
    case 1:
        //qmessagbox --> "livestock is empty"
        QMessageBox::critical(this,"EMPTY","livestock is empty");
        break;
    case 2:
        //qmessagebox --> "you have already fed cows"
        QMessageBox::critical(this,"ALREADY FED","you have already fed cows");
        break;
    case 3:
        //qmessagebox --> "to feed cows first collect milks"
        QMessageBox::critical(this,"READY PRODUCT","to feed cows first collect milks");
        break;
    case 4:
        //qmessagebox --> "not enough alfalfa for feeding cows"
        QMessageBox::critical(this,"NOT ENOUGH ALFALFA","not enough alfalfa for feeding cows");
        break;
    case 5:
        //qmessagbox --> "timer set for milk"
        QMessageBox::information(this,"START","timer set for milk");
        break;
    case 6:
        //qmessagebox  --> "livestock is not built yet"
        QMessageBox::critical(this,"NOT BUILT","livestock is not built yet");
        break;
    }
}


void LivestockPage::on_pushButton_4_clicked()
{
    switch (livestock->Collect()) {
    case 1:
        //qmessagebox --> "no milk to collect"
        QMessageBox::critical(this,"NO MILK","no milk to collect");
        break;
    case 2:
        //qmessagebox --> "not enough space in store for milk"
        QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store for milk");
        break;
    case 3:
        //qmessagebox --> "milks collected successfully"
        QMessageBox::information(this,"SUCCESS","milks collected successfully");
        break;
    case 4:
        //qmessagebox --> "livestock is not built yet"
        QMessageBox::information(this,"NOT BUILT","livestock is not built yet");
        break;
    }
}

