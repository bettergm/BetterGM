#ifndef JOINDIALOG_H
#define JOINDIALOG_H

#include <QDialog>

namespace Ui {
class JoinDialog;
}

class JoinDialog : public QDialog {
    Q_OBJECT
    
public:
    explicit JoinDialog(QString ip, QWidget *parent = 0);
    ~JoinDialog();
    
    QStringList getIPAndPort();
    
private:
    Ui::JoinDialog *ui;
};

#endif // JOINDIALOG_H
