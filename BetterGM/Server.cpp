#include "Server.h"

#include <QDebug>
#include <QSettings>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QString>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTimer>

Server::Server(QObject *parent) :
    QObject(parent),
    mServer(0),
    mNetworkSession(0)
{
    //start();
}

void Server::setName(QString name) {
    mName = name;
}

void Server::start() {
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
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
    } else {
        sessionOpened();
    }
}

void Server::sessionOpened() {
    if (mNetworkSession) {
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
    
    mServer = new QTcpServer(this);
    connect(mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    
    QList<QHostAddress> ipAdressList = QNetworkInterface::allAddresses();
    qDebug() << ipAdressList;
    for (int i = 0; i < ipAdressList.size(); i++) {
        if (ipAdressList.at(i) != QHostAddress::LocalHost && ipAdressList.at(i).toIPv4Address() && !ipAdressList.at(i).toString().contains("169.254") && !ipAdressList.at(i).toString().contains("192.168")) {
            mIPAddress = ipAdressList.at(i).toString();
            //emit newIP(mIPAddress);
            //emit newPort(QString::number(mServer->serverPort()));
            break;
        }
    }
    
    if (mIPAddress.isEmpty()) {
        mIPAddress = QHostAddress(QHostAddress::LocalHost).toString();
        //emit newIP(mIPAddress);
        //emit newPort(QString::number(mServer->serverPort()));
    }
    
    if (!mServer->listen(QHostAddress::Any, 1337)) {
        qDebug() << "server no start\nis a sad";
        qDebug() << "tried ip" << mIPAddress;
        return;
    } else {
        qDebug() << "Server successfully started!";
        //emit newIP(mIPAddress + " maybe?");
        //emit newIP(mServer->serverAddress().toString());
        //emit newPort(QString::number(mServer->serverPort()));
    }
}

void Server::newConnection() {
    qDebug() << "New connection!";
    
    QByteArray msg = "0 Host Welcome!";
    
    QTcpSocket *soc = mServer->nextPendingConnection();
    
    connect(soc, SIGNAL(readyRead()), this, SLOT(clienRead()));
    connect(soc, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    
    soc->write(msg);
    mClients << soc;
    
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(sendAddUser()));
    timer->setSingleShot(true);
    timer->start(100);
}

void Server::sendMessage(QString from, QString message) {
    QByteArray msg = from.toUtf8() + ' ' + message.toUtf8();
    
    foreach (QTcpSocket *client , mClients) {
        client->write(msg);
    }
}

void Server::sendAddUser() {
    QString addUser = QString::number(MSG_ADD) + " " + mName;
    sendMessage(addUser, "");
}

void Server::clienRead() {
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    QByteArray data = client->read(1024*1024);
    
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
        
        foreach (QTcpSocket *c , mClients) {
            if (c != client) {
                c->write(data);
            }
        }
    }
        break;
    }
}

void Server::clientDisconnected() {
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    client->deleteLater();
}
