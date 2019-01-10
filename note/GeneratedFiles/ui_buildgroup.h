/********************************************************************************
** Form generated from reading UI file 'buildgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDGROUP_H
#define UI_BUILDGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buildGroup
{
public:
    QLabel *label;
    QPushButton *ok;
    QLineEdit *groupName;
    QPushButton *cancle;

    void setupUi(QWidget *buildGroup)
    {
        if (buildGroup->objectName().isEmpty())
            buildGroup->setObjectName(QStringLiteral("buildGroup"));
        buildGroup->resize(400, 109);
        label = new QLabel(buildGroup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 72, 15));
        ok = new QPushButton(buildGroup);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(40, 70, 93, 28));
        groupName = new QLineEdit(buildGroup);
        groupName->setObjectName(QStringLiteral("groupName"));
        groupName->setGeometry(QRect(180, 30, 113, 21));
        cancle = new QPushButton(buildGroup);
        cancle->setObjectName(QStringLiteral("cancle"));
        cancle->setGeometry(QRect(190, 70, 93, 28));

        retranslateUi(buildGroup);

        QMetaObject::connectSlotsByName(buildGroup);
    } // setupUi

    void retranslateUi(QWidget *buildGroup)
    {
        buildGroup->setWindowTitle(QApplication::translate("buildGroup", "Form", nullptr));
        label->setText(QApplication::translate("buildGroup", "\347\276\244\347\273\204\345\220\215\347\247\260", nullptr));
        ok->setText(QApplication::translate("buildGroup", "\347\241\256\345\256\232", nullptr));
        cancle->setText(QApplication::translate("buildGroup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buildGroup: public Ui_buildGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDGROUP_H
