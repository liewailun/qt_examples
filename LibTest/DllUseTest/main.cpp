#include <QCoreApplication>
#include <QLibrary>
#include <QDebug>

#define LIBFILE "../DllTest/release/DllTest.dll"

typedef void (*hello)();
typedef void (*test)(void (*a)(const char *));

void func(const char *str)
{
    qDebug() << str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLibrary l(LIBFILE);

    if(l.load())
    {
        hello helloLib = (hello) l.resolve(LIBFILE,QString("hello").toLatin1());
        test funcLib = (test) l.resolve(LIBFILE,QString("test").toLatin1());

        helloLib();
        funcLib(func);
    }
    else
        qDebug() << "FAIL";

    return a.exec();
}
