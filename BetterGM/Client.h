#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QWidget>

class Client : public QWidget {
    Q_OBJECT
public:
    explicit Client(QString ip, QString port, QWidget *parent = 0);
    
    enum MessageType {
        MSG_CHAT = 0,
        MSG_CURSOR = 1,
        MSG_CODE = 2,
        MSG_FILE = 3,
        MSG_ADD = 4,
        MSG_REMOVE = 5,
        MSG_KEY = 6
    };
    
    QString getIP() {
        return mIPAddress;
    }
    
    void tryConnect();

    void sendMessage(QString from, QString message);
    
    QByteArray intToQbyteArray(quint32 number);
    
public slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    
    void read();
    
signals:
    void newMessage(QString, QString);
    void clientCursorMoved(QString, int);
    void addUser(QString);
    void clientKeyPressed(QString, QString);
    
private:
    QString mIPAddress;
    QString mPort;
    
    QTcpSocket *mSocket;
    quint16 blocksize;
    
    QNetworkSession *mNetworkSession;
};

#endif // CLIENT_H
