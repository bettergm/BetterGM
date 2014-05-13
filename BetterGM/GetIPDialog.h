#ifndef GETIPDIALOG_H
#define GETIPDIALOG_H

#include <QDialog>

namespace Ui {
class GetIPDialog;
}

class GetIPDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GetIPDialog(QWidget *parent = 0);
    ~GetIPDialog();
    
private:
    Ui::GetIPDialog *ui;
};

#endif // GETIPDIALOG_H
