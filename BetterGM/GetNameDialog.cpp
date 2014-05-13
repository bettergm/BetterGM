#include "GetNameDialog.h"
#include "ui_GetNameDialog.h"

#include <QLineEdit>

GetNameDialog::GetNameDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetNameDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->lineEdit->setText(name);
    ui->lineEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
}

GetNameDialog::~GetNameDialog() {
    delete ui;
}

QString GetNameDialog::getName() {
    if (exec() != QDialog::Accepted) {
        return "";
    }
    
    return ui->lineEdit->text();
}
