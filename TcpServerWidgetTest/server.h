#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

signals:
    void msgReceived(QString msg);

public slots:
    void startServer(int port);
    void receiveMessage();
    void sendMessage(QString msg);

    void newClient();

private:
    QTcpServer server;
    QTcpSocket *socket;

};

#endif // SERVER_H
