#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->listWidget->addItem("hello");
    ui->listWidget->addItem("world");
    ui->listWidget->addItem("20153292");
    ui->listWidget->addItem("Jeong");
    ui->listWidget->addItem("Hyeonjin");
}

Dialog::~Dialog()
{
    delete ui;
}
