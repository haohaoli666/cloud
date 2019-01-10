/********************************************************************************
** Form generated from reading UI file 'buildnote.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDNOTE_H
#define UI_BUILDNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buildNote
{
public:
    QLabel *label;
    QPushButton *OK;
    QLineEdit *note_name;
    QPushButton *cancle;

    void setupUi(QWidget *buildNote)
    {
        if (buildNote->objectName().isEmpty())
            buildNote->setObjectName(QStringLiteral("buildNote"));
        buildNote->resize(400, 300);
        label = new QLabel(buildNote);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 72, 15));
        OK = new QPushButton(buildNote);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(50, 100, 93, 28));
        note_name = new QLineEdit(buildNote);
        note_name->setObjectName(QStringLiteral("note_name"));
        note_name->setGeometry(QRect(180, 40, 113, 21));
        cancle = new QPushButton(buildNote);
        cancle->setObjectName(QStringLiteral("cancle"));
        cancle->setGeometry(QRect(200, 100, 93, 28));

        retranslateUi(buildNote);

        QMetaObject::connectSlotsByName(buildNote);
    } // setupUi

    void retranslateUi(QWidget *buildNote)
    {
        buildNote->setWindowTitle(QApplication::translate("buildNote", "Form", nullptr));
        label->setText(QApplication::translate("buildNote", "\347\254\224\350\256\260\345\220\215", nullptr));
        OK->setText(QApplication::translate("buildNote", "\347\241\256\345\256\232", nullptr));
        cancle->setText(QApplication::translate("buildNote", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buildNote: public Ui_buildNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDNOTE_H
