#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

signals:
    void msgRead(QByteArray msg);

public slots:
    void connect(QString ip, int port);
    void read();
    void write(QString msg);

private:
    QTcpSocket socket;

};

#endif // CLIENT_H
