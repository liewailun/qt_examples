#include "widget.h"
#include "ui_widget.h"
#include "server.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButtonConnect,SIGNAL(clicked()),this,SLOT(startServer()));
    QObject::connect(ui->pushButtonSend,SIGNAL(clicked()),this,SLOT(write()));
    QObject::connect(&server,SIGNAL(msgReceived(QString)),this,SLOT(msgReceived(QString)));
    ui->spinBox->setMaximum(65535);
    ui->spinBox->setValue(6789);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startServer()
{
    server.startServer(ui->spinBox->value());
}

void Widget::write()
{
    server.sendMessage(ui->textEditSend->toPlainText());
}

void Widget::msgReceived(QString msg)
{
    ui->textEditReceive->setText(msg);
}
