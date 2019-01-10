/********************************************************************************
** Form generated from reading UI file 'new_book.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_BOOK_H
#define UI_NEW_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_book
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *OK;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancle;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *des;

    void setupUi(QWidget *new_book)
    {
        if (new_book->objectName().isEmpty())
            new_book->setObjectName(QStringLiteral("new_book"));
        new_book->resize(400, 194);
        layoutWidget = new QWidget(new_book);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 110, 251, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        OK = new QPushButton(layoutWidget);
        OK->setObjectName(QStringLiteral("OK"));

        horizontalLayout_2->addWidget(OK);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cancle = new QPushButton(layoutWidget);
        cancle->setObjectName(QStringLiteral("cancle"));

        horizontalLayout_2->addWidget(cancle);

        layoutWidget1 = new QWidget(new_book);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 10, 251, 81));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        name = new QLineEdit(layoutWidget1);
        name->setObjectName(QStringLiteral("name"));
        name->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        des = new QLineEdit(layoutWidget1);
        des->setObjectName(QStringLiteral("des"));
        des->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(des);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(new_book);

        QMetaObject::connectSlotsByName(new_book);
    } // setupUi

    void retranslateUi(QWidget *new_book)
    {
        new_book->setWindowTitle(QApplication::translate("new_book", "Form", nullptr));
        OK->setText(QApplication::translate("new_book", "\347\241\256\345\256\232", nullptr));
        cancle->setText(QApplication::translate("new_book", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("new_book", "\347\254\224\350\256\260\346\234\254\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("new_book", "\347\254\224\350\256\260\346\217\217\350\277\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_book: public Ui_new_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_BOOK_H
