#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "client.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void connect();
    void write();
    void receivedMsg(QByteArray msg);

private:
    Ui::Widget *ui;

private:
    Client client;
};

#endif // WIDGET_H
