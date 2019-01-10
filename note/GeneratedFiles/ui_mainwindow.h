/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *book;
    QListWidget *note;
    QLabel *title;
    QPushButton *log;
    QPushButton *register_2;
    QTextEdit *note_edit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *new_book;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *new_note;
    QListWidget *group;
    QLabel *label_5;
    QLabel *user;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *new_group;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1234, 732);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        book = new QListWidget(centralWidget);
        book->setObjectName(QStringLiteral("book"));
        book->setGeometry(QRect(167, 110, 191, 581));
        note = new QListWidget(centralWidget);
        note->setObjectName(QStringLiteral("note"));
        note->setGeometry(QRect(357, 110, 201, 581));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(1, 4, 1111, 51));
        log = new QPushButton(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(830, 20, 93, 28));
        register_2 = new QPushButton(centralWidget);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(970, 20, 93, 28));
        note_edit = new QTextEdit(centralWidget);
        note_edit->setObjectName(QStringLiteral("note_edit"));
        note_edit->setGeometry(QRect(600, 110, 611, 581));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 60, 611, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        save = new QPushButton(layoutWidget);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout->addWidget(save);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(168, 60, 193, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        new_book = new QPushButton(layoutWidget1);
        new_book->setObjectName(QStringLiteral("new_book"));
        new_book->setMaximumSize(QSize(50, 100));

        horizontalLayout_2->addWidget(new_book);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(360, 60, 201, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        new_note = new QPushButton(layoutWidget2);
        new_note->setObjectName(QStringLiteral("new_note"));
        new_note->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(new_note);

        group = new QListWidget(centralWidget);
        group->setObjectName(QStringLiteral("group"));
        group->setGeometry(QRect(20, 111, 151, 581));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 20, 72, 15));
        user = new QLabel(centralWidget);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(290, 20, 72, 15));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 60, 151, 30));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        new_group = new QPushButton(widget);
        new_group->setObjectName(QStringLiteral("new_group"));
        new_group->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(new_group);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1234, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QString());
        log->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        register_2->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\347\254\224\350\256\260", nullptr));
        save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\254\224\350\256\260\346\234\254", nullptr));
        new_book->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\254\224\350\256\260", nullptr));
        new_note->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250", nullptr));
        user->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\347\276\244\347\273\204", nullptr));
        new_group->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
