#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQmlContext>
#include <QQmlComponent>
#include <QSortFilterProxyModel>
#include "businesslogic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    qmlRegisterType<EmployeeSortFilter>("EmployeeSortFilter",1,0,"EmployeeSortFilter");
    BusinessLogic business;
    business.loadModel();

    viewer.rootContext()->setContextProperty("business",&business);
    viewer.setMainQmlFile(QStringLiteral("qml/TableViewTest/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
