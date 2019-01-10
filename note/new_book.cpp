#include "new_book.h"
#include "ui_new_book.h"

new_book::new_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_book)
{
    ui->setupUi(this);
}

new_book::~new_book()
{
    delete ui;
}

void new_book::on_OK_clicked()
{
    QString name = ui->name->text();
    QString des = ui->des->text();
    emit bookInfo(name,des);
}
