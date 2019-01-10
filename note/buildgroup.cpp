#include "buildgroup.h"
#include "ui_buildgroup.h"

buildGroup::buildGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buildGroup)
{
    ui->setupUi(this);
}

buildGroup::~buildGroup()
{
    delete ui;
}

void buildGroup::on_ok_clicked()
{
    QString name = ui->groupName->text();
    emit groupInfo(name);
}
