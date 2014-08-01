#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&socket,SIGNAL(readyRead()),this,SLOT(read()));
}

void Client::connect(QString ip, int port)
{
    qDebug() << "connect to host";
    socket.connectToHost(ip,port,QTcpSocket::ReadWrite);
}

void Client::read()
{
    qDebug() << "received message ";
    emit msgRead(socket.readAll());
}

void Client::write(QString msg)
{
    socket.write(msg.toUtf8());
}
