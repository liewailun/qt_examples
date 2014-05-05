#include <QCoreApplication>
#include <QLibrary>
#include <QDebug>

typedef void (*hello)();
typedef void (*test)(void (*a)(const char *));

void func(const char *str)
{
    qDebug() << str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLibrary l("DllTest.dll");

    if(l.load())
    {
        hello helloLib = (hello) l.resolve("DllTest.dll",QString("hello").toLatin1());
        test funcLib = (test) l.resolve("DllTest.dll",QString("test").toLatin1());

        helloLib();
        funcLib(func);
    }
    else
        qDebug() << "FAIL";

    return a.exec();
}
