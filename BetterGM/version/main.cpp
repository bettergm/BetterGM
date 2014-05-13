#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    
    QDir dir = QDir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    dir.cdUp();
    QString path = dir.path() + "/Version.h";
    
    QFile file(path);
    
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "error";
        return -1;
    }
    
    QTextStream stream(&file);
    
    QString code = stream.readAll();
    
    if (code.isEmpty()) {
        code = "#ifndef VERSION_H\n"
               "#define VERSION_H\n"
               "static const int BUILD_NUMBER = 1;\n"
               "#endif // VERSION_H\n";
        stream << code;
        file.flush();
        file.close();
        
        return 0;
    } else if (code.contains("=")) {
        int index = code.indexOf("=");
        index++;
        QString number;
        for (int i = index; i < code.length(); i++) {
            if (code[i] == ';' || code[i] == '\n') {
                break;
            }
            
            if (code[i] != ' ') {
                number += code[i];
            }
        }
        int n = number.toInt();
        n++;
        number = QString::number(n);
        qDebug() << number;
        
        code.replace(index + 1, number.length(), number);
        
        if (!code.contains(";")) {
            index = code.indexOf(number);
            code.insert(index + number.length(), ";");
        }
        
        file.close();
        
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "error";
            return -1;
        }
        
        stream << code;
        file.flush();
        file.close();
        
        return 0;
    }
    
    file.close();
    
    return a.exec();
}
