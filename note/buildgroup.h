#ifndef BUILDGROUP_H
#define BUILDGROUP_H

#include <QWidget>

namespace Ui {
class buildGroup;
}

class buildGroup : public QWidget
{
    Q_OBJECT

public:
    explicit buildGroup(QWidget *parent = nullptr);
    ~buildGroup();

private slots:
    void on_ok_clicked();

private:
    Ui::buildGroup *ui;

signals:
    void groupInfo(QString);
};

#endif // BUILDGROUP_H
