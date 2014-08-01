#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButtonConnect,SIGNAL(clicked()),this,SLOT(connect()));
    QObject::connect(ui->pushButtonSend,SIGNAL(clicked()),this,SLOT(write()));
    QObject::connect(&client,SIGNAL(msgRead(QByteArray)),this,SLOT(receivedMsg(QByteArray)));
    ui->lineEditIp->setText("localhost");
    ui->spinBoxPort->setMaximum(65535);
    ui->spinBoxPort->setValue(6789);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect()
{
    client.connect(ui->lineEditIp->text(),ui->spinBoxPort->value());
}

void Widget::write()
{
    client.write(ui->textEditSend->toPlainText());
}

void Widget::receivedMsg(QByteArray msg)
{
    ui->textEditReceive->setText(QString(msg));
}
