#include "alfalfa_landpage.h"
#include "ui_alfalfa_landpage.h"
#include "spacepage.h"
#include <QMessageBox>

Alfalfa_landPage::Alfalfa_landPage(Alfalfa_land* _alfalfa_land, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alfalfa_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1200,530);
    setWindowTitle("Alfalfa land");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    alfalfa_land = _alfalfa_land;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

Alfalfa_landPage::~Alfalfa_landPage()
{
    delete ui;
}

void Alfalfa_landPage::on_pushButton_clicked()
{

    switch(alfalfa_land->Build()){
    case 1:
        //qmessagebox --> "alflfa land is already built"
        QMessageBox::critical(this,"BUILT","alfalfa land is already built");
        break;
    case 2:
        //qmessagebox --> "you cannot build alfalfa land until you reach level 3"
        QMessageBox::critical(this,"LEVEL","you cannot build alfalfa land until you reach level 3");
        break;
    case 3:
        //qmessagebox --> "not enough coins for building alfalfa land"
        QMessageBox::critical(this,"COINS","not enough coins for building alfalfa land \n15 coins are needed");
        break;
    case 4:
        //qmessagebox --> "not enough shovels for building alfalfa land"
        QMessageBox::critical(this,"SHOVELS","not enough shovels for building alfalfa land \n1 shovel is needed");
        break;
    case 5:
        //qmessagebox --> "not enough nails for building alfalfa land"
        QMessageBox::critical(this,"NAILS","not enough nails for building alfalfa land \n1 nail is needed");
        break;
    case 6:
        //qmessagebox --> "timer set for building alfalfa land"
        QMessageBox::information(this,"START","timer set for building alfalfa land");
        break;
    }
}


void Alfalfa_landPage::on_pushButton_2_clicked()
{
    switch (alfalfa_land->Upgrade()) {
    case 1:
        //qmessagebox --> "alfalfa land is not built yet"
        QMessageBox::critical(this,"NOT BUILT","alfalfa land is not built yet");
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade until alfalfs ripen and get harvested"
        QMessageBox::critical(this,"NOT RIPE AND NOT HARVESTED","you cannot upgrade until alfalfs ripen and get harvested");
        break;
    case 3:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVELS","not enough shovels for upgrading \n2 shovels are needed for each unit of area");
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading \n5 coins are needed for each unit of area");
        break;
    case 5:
        //qmessagebox --> "you cannot upgrade alfalfa land until you reach level 4"
        QMessageBox::critical(this,"LEVEL","you cannot upgrade alfalfa land until you reach level 4");
        break;
    case 6:
        QMessageBox::critical(this,"UPGEADING","alfalfa land is already in upgrading situation");
        break;
    case 7:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"START","timer set for upgrading");
        break;
    }
}


void Alfalfa_landPage::on_pushButton_3_clicked()
{
    switch(alfalfa_land->Plow()){
    case 1:
        //qmessagebox --> "alfalfa land is not built yet"
        QMessageBox::critical(this,"NOT BUILT","alfalfa land is not built yet");
        break;
    case 2:
        //qmessagebox --> "After alfalfa land upgraded you can plow"
        QMessageBox::critical(this,"UPGRADIN","After alfalfa land upgraded you can plow");
        break;
    case 3:
        //qmessagebox --> "alfalfa land is getting plowed"
        QMessageBox::critical(this,"GETTING PLOWED","alfalfa land is getting plowed");
        break;
    case 4:
        //qmessagebox --> "alfalfa land is already plowed"
        QMessageBox::critical(this,"PLOWED","alfalfa land is already plowed");
        break;
    case 5:
        //qmessagebox --> "field is cultivated. you cannot plow"
        QMessageBox::critical(this,"CULTIVATED","field is cultivated. you cannot plow");
        break;
    case 6:
        //qmessagebox --> "alfalfa is ripe. first you must harvest then plow"
        QMessageBox::critical(this,"CULTIVATED","alfalfa is ripe. first you must harvest then plow");
        break;
    case 7:
        //qmessagebox --> "not enough coins for plowing"
        QMessageBox::critical(this,"COINS","not enough coins for plowing \n5 coins are needed for each unit of area");
        break;
    case 8:
        //qmessagebox --> "timer set for plowing"
        QMessageBox::information(this,"START","timer set for plowing");
        break;
    }
}

void Alfalfa_landPage::on_pushButton_4_clicked()
{
    if(alfalfa_land->Get_building_status() != 2){
        //qmessagebox --> "alfalfa land is not built yet"
        QMessageBox::critical(this,"NOT BUILT","alfalfa land is not built yet");
    }
    else if(alfalfa_land->Get_upgrade_timer() > 0){
        //qmessagebox --> "alfalfa land is upgrading"
        QMessageBox::critical(this,"UPGRADING","alfalfa land is upgrading");
    }
    else if((alfalfa_land->Get_cultivation_status() == 2)&&(alfalfa_land->Get_cultivation_status() == 3)){
        //qmessagebox --> "alfalfa land is already cultivated"
        QMessageBox::critical(this,"CULTIVATED","alfalfa land is already cultivated");
    }
    else if(/*(alfalfa_land->Get_cultivation_status() == 1)||(*/alfalfa_land->Get_cultivation_status() == 0){
        //qmessagbox --> "alfalfa land is not plowed"
        QMessageBox::critical(this,"NOT PLOWED","alfalfa land is not plowed");
    }
    else if ((alfalfa_land->Get_cultivation_status() == 2)||(alfalfa_land->Get_cultivation_status() == 3)){
        //qmessagebox --> "alfalfa land is cultivated"
        QMessageBox::critical(this,"CULTIVATED","alfalfa land is cultivated");
    }
    else if(alfalfa_land->Get_upgrade_timer()!=0){
        QMessageBox::critical(this,"UPGRADIN","After alfalfa land upgraded you can plow");

    }
    else{
        SpacePage* s=new SpacePage(alfalfa_land);
        s->show();
        this->close();
    }
}

void Alfalfa_landPage::on_pushButton_5_clicked()
{
    switch (alfalfa_land->Harvest()) {
    case 1:
        //qmessagebox --> "alfalfa land is not built yet"
        QMessageBox::critical(this,"NOT BUILT","alfalfa land is not built yet");
        break;
    case 2:
        //qmessagebox --> "no alfalfa to harvest"
        QMessageBox::critical(this,"NO ALFALFA","no alfalfa to harvest");
        break;
    case 3:
        //qmessagebox --> "not enough space in store"
        QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store");
        break;
    case 4:
        //qmessagebox --> "harvested successfully"
        QMessageBox::information(this,"SUCCESS","harvested successfully");
        break;
    }
}

void Alfalfa_landPage::Set_values(){
    ui->label->setText(QString::number(alfalfa_land->Get_level()));
    ui->label_2->setText(QString::number(alfalfa_land->Get_cultivated_area()) + "/" + QString::number(alfalfa_land->Get_total_area()));

    // building_status :
    // 0 == locked
    // 1 == locked but not built
    // 2 == built

    // cultivation_status (for alfalfa_land) :
    // 0 == not cultivated
    // 1 == plowed but not cultivated
    // 2 == cultivated but not ripe
    // 3 == ripe

    if(alfalfa_land->Get_building_status() == 0){
        ui->label_3->setText("locked");
    }
    else if((alfalfa_land->Get_building_status() == 1)&&(alfalfa_land->Get_building_timer() == 0)){
        ui->label_3->setText("Not built");
    }
    else if((alfalfa_land->Get_building_status() == 1)&&(alfalfa_land->Get_building_timer() > 0)){
        ui->label_3->setText("Building..." + QString::number(alfalfa_land->Get_building_timer()));
    }
    else if(alfalfa_land->Get_upgrade_timer() > 0){
        ui->label_3->setText("Upgrading..." + QString::number(alfalfa_land->Get_upgrade_timer()));
    }
    else if((alfalfa_land->Get_cultivation_status() == 0) && (alfalfa_land->Get_plowing_timer() == 0)){
        ui->label_3->setText("Ready to plow");
    }
    else if((alfalfa_land->Get_cultivation_status() == 0)&&(alfalfa_land->Get_plowing_timer() > 0)){
        ui->label_3->setText("Plowing..." + QString::number(alfalfa_land->Get_plowing_timer()));
    }
    else if(alfalfa_land->Get_cultivation_status() == 1){
        ui->label_3->setText("Plowed");
    }
    else if(alfalfa_land->Get_cultivation_status() == 2){
        ui->label_3->setText("Ripening..." + QString::number(alfalfa_land->Get_ripening_timer()));
    }
    else{
        ui->label_3->setText("Ripe");
    }
}
