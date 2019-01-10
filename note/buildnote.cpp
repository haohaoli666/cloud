#include "buildnote.h"
#include "ui_buildnote.h"

buildNote::buildNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buildNote)
{
    ui->setupUi(this);
}

buildNote::~buildNote()
{
    delete ui;
}

void buildNote::on_OK_clicked()
{
    QString name = ui->note_name->text();
    emit noteInfo(name);
}
