#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QList>

class Server : public QObject {
    Q_OBJECT
    
public:
    explicit Server(QObject *parent = 0);
    
    enum MessageType {
        MSG_CHAT = 0,
        MSG_CURSOR = 1,
        MSG_CODE = 2,
        MSG_FILE = 3,
        MSG_ADD = 4,
        MSG_REMOVE = 5
    };
    
    void start();
    
    QString getIP() {
        return mIPAddress;
    }
    
    QString getPort() {
        return mPort;
    }
    
    void setName(QString name);
    
    void sendMessage(QString from, QString message);
    
public slots:
    void newConnection();
    void sessionOpened();
    void clienRead();
    void clientDisconnected();
    
    void sendAddUser();
    
signals:
    void newIP(QString);
    void newPort(QString);
    
    void newMessage(QString, QString);
    void serverCursorMoved(QString, int);
    void addUser(QString);
    
private:
    QTcpServer *mServer;
    QNetworkSession *mNetworkSession;
    QString mIPAddress;
    QString mPort;
    QList<QTcpSocket*> mClients;
    QString mName;
};

#endif // SERVER_H
