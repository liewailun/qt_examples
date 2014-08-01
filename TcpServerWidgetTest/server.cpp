#include "server.h"
#include <QDebug>

Server::Server(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&server,SIGNAL(newConnection()),this,SLOT(newClient()));
}

void Server::startServer(int port)
{
    qDebug() << "server started";
    server.listen(QHostAddress::Any,port);
}

void Server::receiveMessage()
{
    qDebug() << "received message";
    emit msgReceived(socket->readAll());
}

void Server::sendMessage(QString msg)
{
    qDebug() << "sent message";
    if(socket)
        socket->write(msg.toUtf8());
}

void Server::newClient()
{
    qDebug() << "new client";
    socket = server.nextPendingConnection();
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(receiveMessage()),Qt::UniqueConnection);
}
