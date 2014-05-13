#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w(&a);
    setMainWindow(&w);
    w.showMaximized();
    
    return a.exec();
}
