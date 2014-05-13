#include "JoinDialog.h"
#include "ui_JoinDialog.h"

#include <QLineEdit>

JoinDialog::JoinDialog(QString ip, QWidget *parent):
    QDialog(parent),
    ui(new Ui::JoinDialog)
{
    ui->setupUi(this);
    
    ui->ipEdit->setText(ip);
    
    ui->ipEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->portEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
}

JoinDialog::~JoinDialog() {
    delete ui;
}

QStringList JoinDialog::getIPAndPort() {
    if (exec() != QDialog::Accepted) {
        return QStringList();
    }
    
    QStringList ipAndPort;
    ipAndPort << ui->ipEdit->text();
    ipAndPort << ui->portEdit->text();
    
    return ipAndPort;
}
