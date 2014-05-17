#include "Client.h"

#include <QNetworkConfigurationManager>
#include <QSettings>
#include <QMessageBox>

Client::Client(QString ip, QString port, QWidget *parent) :
    QWidget(parent),
    mIPAddress(ip),
    mPort(port),
    mNetworkSession(0)
{
    mSocket = new QTcpSocket(this);
    
    qDebug() << "client constructor";
    qDebug() << "client ip = " << mIPAddress;
    qDebug() << "client port = " << mPort;
    
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(mSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        qDebug() << "client constructor";
        
        QSettings settings(QSettings::UserScope, QLatin1String("BetterGM"));
        settings.beginGroup(QLatin1String("Network"));
            const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();
        
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }
        
        mNetworkSession = new QNetworkSession(config, this);
        connect(mNetworkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        mNetworkSession->open();
    }
}

void Client::tryConnect() {
    qDebug() << "try connect";
    blocksize = 0;
    mSocket->abort();
    mSocket->connectToHost(mIPAddress, mPort.toInt());
}

void Client::displayError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::information(this, tr("BetterGM Client"),
                                 tr("Host closed"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("BetterGM Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("BetterGM Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the BetterGM server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("BetterGM Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(mSocket->errorString()));
    }
}

void Client::sessionOpened() {
    qDebug() << "client session open";
    QNetworkConfiguration config = mNetworkSession->configuration();
    QString id;
    
    if (config.type() == QNetworkConfiguration::UserChoice) {
        id = mNetworkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    } else {
        id = config.identifier();
    }
    
    QSettings settings(QSettings::UserScope, QLatin1String("BetterGM"));
    settings.beginGroup(QLatin1String("Network"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();
}

void Client::read() {
    QByteArray data = mSocket->read(1024*1024);
    
    QString tmp = QString(data);
    QString user;
    QString msg;
    QString type;
    int msgType;
    
    int i = 0;
    for (; i < tmp.length(); i++) {
        if (tmp[i] != ' ') {
            type += tmp[i];
        } else {
            i++;
            break;
        }
    }
    
    msgType = type.toInt();
    
    switch (msgType) {
    case MSG_CHAT: {
        bool userFound = false;
        for (; i < tmp.length(); i++) {
            if (!userFound) {
                if (tmp[i] == ' ') {
                    userFound = true;
                    continue;
                }
                user += tmp[i];
            } else {
                msg += tmp[i];
            }
        }
        
        emit newMessage(user, msg);
        break;
    }
    case MSG_CURSOR: {
        QString pos, usr;
        bool userFound = false;
        for (; i < tmp.length(); i++) {
            if (!userFound) {
                if (tmp[i] == ' ') {
                    userFound = true;
                    continue;
                }
                usr += tmp[i];
            } else {
                pos += tmp[i];
            }
        }
        emit clientCursorMoved(usr, pos.toInt());
        break;
    }
    case MSG_ADD: {
        QString usr;
        for (; i < tmp.length(); i++) {
            if (tmp[i] != ' ') {
                usr += tmp[i];
            }
        }
        emit addUser(usr);
        break;
    }
    }
}

void Client::sendMessage(QString from, QString message) {
    QByteArray msg = from.toUtf8() + ' ' + message.toUtf8();
    mSocket->write(msg);
}

QByteArray Client::intToQbyteArray(quint32 number) {
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << number;
    return temp;
}
