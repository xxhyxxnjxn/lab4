#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked() // push 1
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("1");
    }
    else{
        ui->lineEdit_3->setText("1");
    }
}

void Dialog::on_pushButton_2_clicked() // push 2
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("2");
    }
    else{
        ui->lineEdit_3->setText("2");
    }
}

void Dialog::on_pushButton_3_clicked() // push 3
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("3");
    }
    else{
        ui->lineEdit_3->setText("3");
    }
}


void Dialog::on_pushButton_4_clicked() // push 4
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("4");
    }
    else{
        ui->lineEdit_3->setText("4");
    }
}

void Dialog::on_pushButton_5_clicked() // push 5
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("5");
    }
    else{
        ui->lineEdit_3->setText("5");
    }
}

void Dialog::on_pushButton_6_clicked() // push 6
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("6");
    }
    else{
        ui->lineEdit_3->setText("6");
    }
}

void Dialog::on_pushButton_7_clicked() // push 7
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("7");
    }
    else{
        ui->lineEdit_3->setText("7");
    }
}

void Dialog::on_pushButton_8_clicked() // push 8
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("8");
    }
    else{
        ui->lineEdit_3->setText("8");
    }
}


void Dialog::on_pushButton_9_clicked() // push 9
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("9");
    }
    else{
        ui->lineEdit_3->setText("9");
    }
}

void Dialog::on_pushButton_10_clicked() // push 0
{
    if(QString::compare(ui->lineEdit_2->text(),"")==0){
        ui->lineEdit->setText("0");
    }
    else{
        ui->lineEdit_3->setText("0");
    }
}

void Dialog::on_pushButton_12_clicked() // push +
{
    ui->lineEdit_2->setText("+");
}

void Dialog::on_pushButton_13_clicked() // push -
{
    ui->lineEdit_2->setText("-");
}

void Dialog::on_pushButton_14_clicked() // push *
{
    ui->lineEdit_2->setText("*");
}

void Dialog::on_pushButton_15_clicked() // push /
{
    ui->lineEdit_2->setText("/");
}

void Dialog::on_pushButton_11_clicked() // push =
{
    if(ui->lineEdit_2->text()=="+"){
        ui->lineEdit_4->setText(QString::number(ui->lineEdit->text().toInt(NULL,10)+ui->lineEdit_3->text().toInt(NULL,10)));
    }
    else if(ui->lineEdit_2->text()=="-"){
        ui->lineEdit_4->setText(QString::number(ui->lineEdit->text().toInt(NULL,10)-ui->lineEdit_3->text().toInt(NULL,10)));
    }
    else if(ui->lineEdit_2->text()=="*"){
        ui->lineEdit_4->setText(QString::number(ui->lineEdit->text().toInt(NULL,10)*ui->lineEdit_3->text().toInt(NULL,10)));
    }
    else if(ui->lineEdit_2->text()=="/"){
        ui->lineEdit_4->setText(QString::number(ui->lineEdit->text().toInt(NULL,10)/ui->lineEdit_3->text().toInt(NULL,10)));
    }
}

void Dialog::on_pushButton_16_clicked() // push c
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}
