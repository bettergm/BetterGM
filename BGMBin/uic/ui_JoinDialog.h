/********************************************************************************
** Form generated from reading UI file 'JoinDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINDIALOG_H
#define UI_JOINDIALOG_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portEdit;

    void setupUi(QDialog *JoinDialog)
    {
        if (JoinDialog->objectName().isEmpty())
            JoinDialog->setObjectName(QString::fromUtf8("JoinDialog"));
        JoinDialog->resize(400, 150);
        buttonBox = new QDialogButtonBox(JoinDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(JoinDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 380, 90));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ipEdit = new QLineEdit(verticalLayoutWidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        horizontalLayout->addWidget(ipEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        portEdit = new QLineEdit(verticalLayoutWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout_2->addWidget(portEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(JoinDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), JoinDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), JoinDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(JoinDialog);
    } // setupUi

    void retranslateUi(QDialog *JoinDialog)
    {
        JoinDialog->setWindowTitle(QApplication::translate("JoinDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JoinDialog", "IP:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JoinDialog", "Port:", 0, QApplication::UnicodeUTF8));
        portEdit->setText(QApplication::translate("JoinDialog", "1337", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JoinDialog: public Ui_JoinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINDIALOG_H
