#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <QObject>
#include "employeemodel.h"
#include "employeesortfilter.h"

class BusinessLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(EmployeeSortFilter* model READ model NOTIFY modelChanged)
public:
    explicit BusinessLogic(QObject *parent = 0);

    EmployeeSortFilter* model();

    void loadModel();

signals:
    void modelChanged();

public slots:
    void addEmployee(QString lastName, QString firstName, QString title);
    void doubleClicked(int row);

private:
    EmployeeModel m_model;
    EmployeeSortFilter m_filterModel;

};

#endif // BUSINESSLOGIC_H
