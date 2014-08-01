#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "server.h"

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
    void startServer();
    void write();
    void msgReceived(QString msg);

private:
    Ui::Widget *ui;
    Server server;
};

#endif // WIDGET_H
