#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<QString>
#include <string.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    client->connectToHost("127.0.0.1",2000);
    bool b;
    b = connect(client,SIGNAL(readyRead()),this,SLOT(printServerMessage()));

    now_group = "";
    now_book = "";
    now_note = "";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printServerMessage(){
    QString msg = QString(client->readLine());
    msg = get_string(msg);
    if(!strcmp(msg.toStdString().c_str(),"login\n")){
        getLog();
    }
    if(!strcmp(msg.toStdString().c_str(),"register\n")){
        getRgs();
    }
    if(!strcmp(msg.toStdString().c_str(),"new_book\n")){
        get_new_book();
    }
    if(!strcmp(msg.toStdString().c_str(),"new_group\n")){
        new_group();
    }
    if(!strcmp(msg.toStdString().c_str(),"new_note\n")){
        new_note();
    }
    if(!strcmp(msg.toStdString().c_str(),"get_group\n")){
        get_group();
    }
    if(!strcmp(msg.toStdString().c_str(),"get_book\n")){
        get_book();
    }
    if(!strcmp(msg.toStdString().c_str(),"get_notes\n")){
        get_notes();
    }
    if(!strcmp(msg.toStdString().c_str(),"new_content\n")){
        get_content();
    }
    if(!strcmp(msg.toStdString().c_str(),"get_content\n")){
        get_content();
    }
}

void MainWindow::getLog(){
    QString result = QString(client->readLine());
    if(!strcmp(result.toStdString().c_str(),"ok\n")){
        QString user_name = QString(client->readLine());
        ui->user->setText(user_name);
        log->close();
    }
    else{
        QMessageBox::information(this,u8"来自服务端的消息",u8"用户名或密码错误！");
    }
}

void MainWindow::getRgs(){
    QString result = QString(client->readLine());
    if(!strcmp(result.toStdString().c_str(),"ok\n")){
        QMessageBox::information(this,u8"来自服务端的消息",u8"注册成功！");
    }
    else{
        QMessageBox::information(this,u8"来自服务端的消息",u8"用户名已存在！");
    }
}

void MainWindow::get_group(){
    cout<<"now is getting group"<<endl;
    while(1){
        QString result = QString(client->readLine());
		result = get_string(result);
        if(!result.compare("get_group_end\n"))
            break;
        else{
            //添加元素
            QListWidgetItem *item = new QListWidgetItem(result);
            ui->group->addItem(item);
        }
    }
}

void MainWindow::reget_group(){
    const char* cmd = "get_group\n";
    client->write(cmd);
    client->flush();
    cout<< cmd << "reget_group" <<endl;
}

void MainWindow::get_book(){        //获取笔记本
    while(1){
        QString result = QString(client->readLine());
		result = get_string(result);
        if(!result.compare("get_book_end\n"))
            break;
        else{
            //添加元素
            QListWidgetItem *item = new QListWidgetItem(result);
            ui->book->addItem(item);
        }
    }
}

void MainWindow::get_notes(){       //获取笔记
    while(1){
        QString result = QString(client->readLine());
        result = get_string(result);
        if(!result.compare("get_note_end\n"))
            break;
        else{
            //添加元素
            QListWidgetItem *item = new QListWidgetItem(result);
            ui->note->addItem(item);
        }
    }
}

void MainWindow::get_content(){     //获取笔记内容
    while(1){
        QString result = QString(client->readLine());
        result = get_string(result);
        if(!result.compare("get_content_end\n"))
            break;
        else{
            //添加元素
            ui->note_edit->setText(result);
        }
    }
}

//新建
void MainWindow::get_new_book(){    //新建笔记本
    QString result = QString(client->readLine());
	result = get_string(result);
    if(!strcmp(result.toStdString().c_str(),"ok\n")){
        //QMessageBox::information(this,u8"来自服务端的消息",u8"创建笔记本成功！");
        deleteAllSlot(2);
        QListWidgetItem *item;
        on_group_itemClicked(item);
        book->close();
    }
    else{
        QMessageBox::information(this,u8"来自服务端的消息",u8"您可能存在名称相同的笔记本！");
    }
}

void MainWindow::new_group(){       //新建群组
    QString result = QString(client->readLine());
    cout << "55555555555" <<strcmp(result.toStdString().c_str(),"ok\n") <<endl;
    if(!strcmp(result.toStdString().c_str(),"ok\r\n")){
        deleteAllSlot(1);
        reget_group();
        bg->close();
    }
    else{
        QMessageBox::information(this,u8"来自服务端的消息",u8"您可能存在名称相同的群组！");
    }
}


//
void MainWindow::on_log_clicked()
{
    log = new login();
    connect(log,SIGNAL(info(QString,QString)),this,SLOT(Login(QString,QString)));
    log->show();

}

void MainWindow::Login(QString name,QString password){
    name += "\n";
    password += "\n";
    std::string user_name = name.toStdString();
    const char* uname = user_name.c_str();
    std::string user_password = password.toStdString();
    const char* upassword = user_password.c_str();
    const char* cmd = "login\n";
    client->write(cmd);
    client->write(uname);
    client->write(upassword);
    client->flush();
    cout<< cmd << "username: " << uname << "password: " << upassword <<endl;
}

void MainWindow::on_register_2_clicked()
{
    rgs = new Register();
    connect(rgs,SIGNAL(info(QString,QString)),this,SLOT(ToRegister(QString,QString)));
    rgs->show();
}

void MainWindow::ToRegister(QString name,QString password){
    name += "\n";
    password += "\n";
    std::string user_name = name.toStdString();
    const char* uname = user_name.c_str();
    std::string user_password = password.toStdString();
    const char* upassword = user_password.c_str();
    const char* cmd = "register\n";
    client->write(cmd);
    client->write(uname);
    client->write(upassword);
    client->flush();
    cout<< cmd << "username: " << uname << "password: " << upassword <<endl;
}

void MainWindow::on_new_book_clicked()
{
    book = new new_book();
    connect(book,SIGNAL(bookInfo(QString,QString)),this,SLOT(toNewBook(QString,QString)));
    book->show();
}

void MainWindow::toNewBook(QString name,QString des){
    name += "\n";
    des += "\n";
    std::string book_name = name.toStdString();
    std::string bookDes = des.toStdString();
    std::string bookgroup = now_group.toStdString();
    const char *bgroup = bookgroup.c_str();
    const char* bname = book_name.c_str();
    const char* bdes = bookDes.c_str();
    const char* cmd = "new_book\n";
    client->write(cmd);
    client->write(bgroup);
    client->write(bname);
    client->write(bdes);
    client->flush();
    cout<< cmd << "now_group:" << bgroup <<"bookname: " << bname << "bookDescription:" << bdes <<endl;
}

void MainWindow::on_new_group_clicked()
{
    bg = new buildGroup();
    connect(bg,SIGNAL(groupInfo(QString)),this,SLOT(toNewGroup(QString)));
    bg->show();
}

void MainWindow::toNewGroup(QString groupName){
    groupName += "\n";
    std::string group_name = groupName.toStdString();
    const char* gname = group_name.c_str();
    const char* cmd = "new_group\n";
    client->write(cmd);
    client->write(gname);
    client->flush();
    cout<< cmd << "groupname: " << gname <<endl;
}

void MainWindow::on_new_note_clicked()
{
    bn = new buildNote();
    connect(bn,SIGNAL(noteInfo(QString)),this,SLOT(toNewNote(QString)));
    bn->show();
}

void MainWindow::toNewNote(QString name){
    name += "\n";
    std::string note_name = name.toStdString();
    std::string bookgroup = now_group.toStdString();
    std::string book_name = now_book.toStdString();
    const char *bgroup = bookgroup.c_str();
    const char* bname = book_name.c_str();
    const char* note = note_name.c_str();
    const char* cmd = "new_note\n";
    client->write(cmd);
    client->write(bgroup);
    client->write(bname);
    client->write(note);
    client->flush();
    cout<< cmd << "now_group:" << bgroup <<"bookname: " << bname << "bookDescription:" << note <<endl;
}

void MainWindow::new_note(){
    QString result = QString(client->readLine());
    if(!strcmp(result.toStdString().c_str(),"ok\r\n")){
        deleteAllSlot(3);
        QListWidgetItem *item;
        on_book_itemClicked(item);
        bn->close();
    }
    else{
        QMessageBox::information(this,u8"来自服务端的消息",u8"您可能存在名称相同的群组！");
    }
}

void MainWindow::on_group_itemClicked(QListWidgetItem *item)
{
    QListWidgetItem *curItem = ui->group->currentItem();
    QString cur_group = curItem->text();
    now_group = cur_group;
    cur_group += "\n";
    std::string group_name = cur_group.toStdString();
    const char* gname = group_name.c_str();
    const char* cmd = "get_book\n";
    client->write(cmd);
    client->write(gname);
    client->flush();
    cout<< cmd << "groupname: " << gname <<endl;
}

void MainWindow::deleteAllSlot(int mode)
{
    if(mode == 1){
        int counter =ui->group->count();
        for(int index=0;index<counter;index++)
        {
            QListWidgetItem *item = ui->group->takeItem(0);
            delete item;
        }
    }
    if(mode == 2){
        int counter =ui->book->count();
        for(int index=0;index<counter;index++)
        {
            QListWidgetItem *item = ui->book->takeItem(0);
            delete item;
        }
    }
    if(mode == 3){
        int counter =ui->note->count();
        for(int index=0;index<counter;index++)
        {
            QListWidgetItem *item = ui->note->takeItem(0);
            delete item;
        }
    }

}

QString MainWindow::get_string(QString str){
    while (1) {
        if (str == "\r\n") {
            str = QString(client->readLine());
            continue;
        }
        else
            break;
    }
    return str;
}

void MainWindow::on_book_itemClicked(QListWidgetItem *item)
{
    QListWidgetItem *curItem = ui->book->currentItem();
    QString cur_book = curItem->text();
    now_book = cur_book;
    cur_book += "\n";
    std::string book_name = cur_book.toStdString();
    std::string bookgroup = now_group.toStdString();
    const char *bgroup = bookgroup.c_str();
    const char* bname = book_name.c_str();
    const char* cmd = "get_notes\n";
    client->write(cmd);
    client->write(bgroup);
    client->write(bname);
    client->flush();
    cout<< cmd << "groupname: " << bgroup << "bookname:" << bname <<endl;
}

void MainWindow::on_note_itemClicked(QListWidgetItem *item)
{
    QListWidgetItem *curItem = ui->note->currentItem();
    QString cur_note = curItem->text();
    now_note = cur_note;
    cur_note += "\n";
    std::string note_name = cur_note.toStdString();
    std::string notegroup = now_group.toStdString();
    std::string notebook = now_book.toStdString();
    const char *bgroup = notegroup.c_str();
    const char *bbook = notebook.c_str();
    const char* bname = note_name.c_str();
    const char* cmd = "get_notes\n";
    client->write(cmd);
    client->write(bgroup);
    client->write(bbook);
    client->write(bname);
    client->flush();
    cout<< cmd << "groupname: " << bgroup << "bookname:" << bbook << "notename" << bname <<endl;
}
