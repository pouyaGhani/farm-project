#include "shovel_market.h"
#include "ui_shovel_market.h"

Shovel_market::Shovel_market(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shovel_market)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    ui->label->setText(QString::number(store->Get_object(1)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

Shovel_market::~Shovel_market()
{
    delete ui;
}

void Shovel_market::on_pushButton_clicked()// 1 --> sell              2 --> buy
{
    if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
        // qmessagebox --> "number of buying and selling items is 0"
        QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
        return;
    }

    if(ui->spinBox->text().toInt() != 0){                                                   //
        if(store->Get_object(1) < ui->spinBox->text().toInt()){                             //
            //qmessagbox --> "not enough shovels to sell"                                   //
            QMessageBox::critical(this,"NOT ENOUGH SHOVELS","not enough shovels to sell");  //
        }                                                                                   // sell
        else{                                                                               //
            store->Delete(1, ui->spinBox->text().toInt());                                  //
            user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*30);              //
        }                                                                                   //
    }                                                                                       //

    if(ui->spinBox_2->text().toInt() != 0){ // buy                                                   //
        if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){  //
            //qmessagebox --> "not enough space in store"                                            //
            QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store");              //
        }                                                                                            //
        else{                                                                                        //
            store->Add(1, ui->spinBox_2->text().toInt());                                            // buy
            user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*50);                     //
            user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*8);          //
        }                                                                                            //
    }                                                                                                //
}

