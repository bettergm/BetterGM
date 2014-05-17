/********************************************************************************
** Form generated from reading UI file 'GetIPDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETIPDIALOG_H
#define UI_GETIPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetIPDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIP;
    QLineEdit *ipEdit;

    void setupUi(QDialog *GetIPDialog)
    {
        if (GetIPDialog->objectName().isEmpty())
            GetIPDialog->setObjectName(QString::fromUtf8("GetIPDialog"));
        GetIPDialog->resize(243, 103);
        buttonBox = new QDialogButtonBox(GetIPDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 60, 220, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(GetIPDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 220, 40));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelIP = new QLabel(horizontalLayoutWidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        horizontalLayout->addWidget(labelIP);

        ipEdit = new QLineEdit(horizontalLayoutWidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        horizontalLayout->addWidget(ipEdit);


        retranslateUi(GetIPDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetIPDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetIPDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetIPDialog);
    } // setupUi

    void retranslateUi(QDialog *GetIPDialog)
    {
        GetIPDialog->setWindowTitle(QApplication::translate("GetIPDialog", "IP", 0, QApplication::UnicodeUTF8));
        labelIP->setText(QApplication::translate("GetIPDialog", "IP", 0, QApplication::UnicodeUTF8));
        ipEdit->setText(QApplication::translate("GetIPDialog", "127.0.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GetIPDialog: public Ui_GetIPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETIPDIALOG_H
