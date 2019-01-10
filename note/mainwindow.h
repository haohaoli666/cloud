#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include "login.h"
#include "register.h"
#include "new_book.h"
#include "buildgroup.h"
#include "buildnote.h"
#include "QListWidget"
#include "QListWidgetItem"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void printServerMessage();

    void on_log_clicked();
    void Login(QString name,QString password);
    void getLog();

    void ToRegister(QString name,QString password);
    void on_register_2_clicked();
    void getRgs();

    void toNewBook(QString,QString);
    void get_new_book();
    void on_new_book_clicked();

    void get_group();
    void get_book();
    void get_notes();
    void get_content();

    void on_new_group_clicked();
    void new_group();
    void toNewGroup(QString);

    void on_new_note_clicked();
    void toNewNote(QString);
    void new_note();

    void on_group_itemClicked(QListWidgetItem *item);

    void deleteAllSlot(int);

    void reget_group();



    QString get_string(QString);

    void on_book_itemClicked(QListWidgetItem *item);

    void on_note_itemClicked(QListWidgetItem *item);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpSocket *client;
    login *log;
    Register * rgs;
    new_book *book;
    buildGroup *bg;
    buildNote *bn;

    QString now_group;
    QString now_book;
    QString now_note;


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
