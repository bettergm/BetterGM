#ifndef GETNAMEDIALOG_H
#define GETNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class GetNameDialog;
}

class GetNameDialog : public QDialog {
    Q_OBJECT
    
public:
    explicit GetNameDialog(QString name, QWidget *parent = 0);
    ~GetNameDialog();
    
    QString getName();
    
private:
    Ui::GetNameDialog *ui;
};

#endif // GETNAMEDIALOG_H
