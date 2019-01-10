#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_log_clicked()
{
    QString name = ui->user_name->text();
    QString password = ui->password->text();
    emit info(name,password);
}
