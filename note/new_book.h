#ifndef NEW_BOOK_H
#define NEW_BOOK_H

#include <QWidget>

namespace Ui {
class new_book;
}

class new_book : public QWidget
{
    Q_OBJECT

public:
    explicit new_book(QWidget *parent = nullptr);
    ~new_book();

private slots:
    void on_OK_clicked();

private:
    Ui::new_book *ui;

signals:
    void bookInfo(QString name,QString des);
};

#endif // NEW_BOOK_H
