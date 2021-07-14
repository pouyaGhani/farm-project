#include "cowmarket.h"
#include "ui_cowmarket.h"

CowMarket::CowMarket(User* _user, Livestock* _livestock, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CowMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    user = _user;
    livestock = _livestock;

    ui->label->setText(QString::number(livestock->Get_used_storage()));
    ui->label_2->setText(QString::number(livestock->Get_total_storage()- livestock->Get_used_storage()));
}

CowMarket::~CowMarket()
{
    delete ui;
}

void CowMarket::on_pushButton_clicked() // buy -> 1             sell -> 2
{
    if(livestock->Get_building_status() != 2){
        //qmessagebox --> "you must build livestock to buy or sell cow"
        QMessageBox::critical(this,"LIVESTOCK NOT BUILT","you must build livestock to buy or sell cow");
    }
    else{
        if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
            //qmessagebox --> "number of buying and selling items is 0"
            QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
            return;
        }

        if((ui->spinBox->text().toInt() != 0)&&(ui->spinBox_2->text().toInt() != 0)){
            // qmessagebox --> "you cannot buy and sell at the same time"
            QMessageBox::critical(this,"BUY AND SELL","you cannot buy and sell at the same time");
            return;
        }

        if(ui->spinBox_2->text().toInt() != 0){                                                                     //
            if(livestock->Get_used_storage() < ui->spinBox_2->text().toInt()){                                      //
                //qmessagebox --> "not enough cows to sell"                                                         //
                QMessageBox::critical(this,"NOT ENOUGH COWS","not enough cows to sell");                            //
            }                                                                                                       //
            else{                                                                                                   // sell
                livestock->Delete(1, ui->spinBox_2->text().toInt());                                                //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*50);                                //
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);                       //
            }                                                                                                       //
        }

        if(ui->spinBox->text().toInt() != 0){                                                                       //
            if(livestock->Get_total_storage() - livestock->Get_used_storage() < ui->spinBox->text().toInt()){       //
                //qmessagebox --> "not enough space in livestock"                                                   //
                QMessageBox::critical(this,"NOT ENOUGH SAPCE","not enough space in livestock");                     //
            }                                                                                                       //
            else{                                                                                                   // buy
                livestock->Add(1, ui->spinBox->text().toInt());                                                     //
                user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*70);                                  //
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);                      //
            }                                                                                                       //
        }                                                                                                           //
    }
}

