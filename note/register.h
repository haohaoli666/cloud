#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_Register_2_clicked();

private:
    Ui::Register *ui;

signals:
    void info(QString name,QString password);
};

#endif // REGISTER_H
