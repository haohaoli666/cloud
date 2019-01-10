#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_Register_2_clicked()
{

    QString name = ui->user_name->text();
    QString password = ui->user_password->text();
    emit info(name,password);
}
