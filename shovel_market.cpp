#include "shovel_market.h"
#include "ui_shovel_market.h"

Shovel_market::Shovel_market(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shovel_market)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    user = _user;
    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
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

    if((ui->spinBox->text().toInt() != 0)&&(ui->spinBox_2->text().toInt() != 0)){
        // qmessagebox --> "you cannot buy and sell at the same time"
        QMessageBox::critical(this,"BUY AND SELL","you cannot buy and sell at the same time");
        return;
    }

    if(ui->spinBox->text().toInt() != 0){                                                         //
        if(user->Get_level() >= 2){                                                               //
            if(store->Get_object(1) < ui->spinBox->text().toInt()){                               //
                //qmessagbox --> "not enough shovels to sell"                                     //
                QMessageBox::critical(this,"NOT ENOUGH SHOVELS","not enough shovels to sell");    //
            }                                                                                     // sell
            else{                                                                                 //
                store->Delete(1, ui->spinBox->text().toInt());                                    //
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*30);                //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);   //
                                                                                                  //
                if(ui->spinBox->text().toInt() == 1){//                                           //
                    //qmessagebox --> "shovel is sold successfully"                               //
                    QMessageBox::information(this,"SUCCESSFUL TRADE", "1 shovel is sold");        //
                }                                                                                 //
                else{                                                                             //
                    //qmessagebox --> "shovel is sold successfully"                               //
                    QMessageBox::information(this,"SUCCESSFUL TRADE",                             //
                    QString::number(ui->spinBox->text().toInt()) + " shovels are sold");          //
                }                                                                                 //
            }                                                                                     //
        }                                                                                         //
        else{                                                                                     //
            //qmessagebox --> "you must reach level 2 to sell stuff"                              //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to sell stuff");           //
        }                                                                                         //
    }                                                                                             //

    if(ui->spinBox_2->text().toInt() != 0){ // buy                                                                    //
        if(user->Get_level() >= 2){                                                                                   //
            if(user->Get_coin() < ui->spinBox_2->text().toInt()*50){                                                  //
                //qmessagebox --> "not enough coins to buy this number of shovels"                                    //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this number of shovels");      //
            }                                                                                                         //
            else{                                                                                                     //
                if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){           //
                    //qmessagebox --> "not enough space in store"                                                     //
                    QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store");                       //
                }                                                                                                     //
                else{                                                                                                 //
                    store->Add(1, ui->spinBox_2->text().toInt());                                                     // buy
                    user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*50);                              //
                    user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*2);                   //
                                                                                                                      //
                    if(ui->spinBox_2->text().toInt() == 1){//                                                         //
                        //qmessagebox --> "shovel is bought successfully"                                             //
                        QMessageBox::information(this,"SUCCESSFUL TRADE", "1 shovel is bought");                      //
                    }                                                                                                 //
                    else{                                                                                             //
                        //qmessagebox --> "shovel is bought successfully"                                             //
                        QMessageBox::information(this,"SUCCESSFUL TRADE",                                             //
                        QString::number(ui->spinBox_2->text().toInt()) + " shovels are bought");                      //
                    }                                                                                                 //
                }                                                                                                     //
            }                                                                                                         //
        }                                                                                                             //
        else{                                                                                                         //
            //qmessagebox --> "you must reach level 2 to buy stuff"                                                   //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy stuff");                                //
        }                                                                                                             //
    }                                                                                                                 //
}

void Shovel_market::Set_values(){
    ui->label->setText(QString::number(store->Get_object(1)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}
