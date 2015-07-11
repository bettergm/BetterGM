/********************************************************************************
** Form generated from reading UI file 'GetNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETNAMEDIALOG_H
#define UI_GETNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *GetNameDialog)
    {
        if (GetNameDialog->objectName().isEmpty())
            GetNameDialog->setObjectName(QStringLiteral("GetNameDialog"));
        GetNameDialog->resize(400, 103);
        buttonBox = new QDialogButtonBox(GetNameDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 60, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(GetNameDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 370, 40));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(GetNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetNameDialog);
    } // setupUi

    void retranslateUi(QDialog *GetNameDialog)
    {
        GetNameDialog->setWindowTitle(QApplication::translate("GetNameDialog", "Set Name", 0));
        label->setText(QApplication::translate("GetNameDialog", "Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class GetNameDialog: public Ui_GetNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETNAMEDIALOG_H
