#ifndef BUILDNOTE_H
#define BUILDNOTE_H

#include <QWidget>

namespace Ui {
class buildNote;
}

class buildNote : public QWidget
{
    Q_OBJECT

public:
    explicit buildNote(QWidget *parent = nullptr);
    ~buildNote();

private slots:
    void on_OK_clicked();

private:
    Ui::buildNote *ui;

signals:
    void noteInfo(QString);
};

#endif // BUILDNOTE_H
