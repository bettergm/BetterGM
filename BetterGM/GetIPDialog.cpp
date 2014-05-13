#include "GetIPDialog.h"
#include "ui_GetIPDialog.h"

#include <QLineEdit>

GetIPDialog::GetIPDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetIPDialog) 
{
    ui->setupUi(this);
    
    ui->ipEdit->setReadOnly(true);
    ui->ipEdit->setFocus();
    ui->ipEdit->selectAll();
    ui->ipEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
}

GetIPDialog::~GetIPDialog() {
    delete ui;
}
