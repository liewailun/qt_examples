#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQmlContext>
#include <QSortFilterProxyModel>
#include "employeemodel.h"
#include "employeesortfilter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    EmployeeModel model;
    model.load();
    model.print();
    EmployeeSortFilter filterModel;
    filterModel.setSourceModel(&model);
    viewer.rootContext()->setContextProperty("employeeModel",&filterModel);
    viewer.setMainQmlFile(QStringLiteral("qml/TableViewTest/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
