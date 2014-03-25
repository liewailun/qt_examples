#include "businesslogic.h"

BusinessLogic::BusinessLogic(QObject *parent) :
    QObject(parent)
{
}

EmployeeSortFilter *BusinessLogic::model()
{
    m_filterModel.setSourceModel(&m_model);
    return &m_filterModel;
}

void BusinessLogic::loadModel()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT LastName, FirstName, Title FROM Employee;");
    q.exec();
    while(q.next())
    {
        m_model.addItem(q.value(0).toString(),q.value(1).toString(),q.value(2).toString());
    }
}

void BusinessLogic::addEmployee(QString lastName, QString firstName, QString title)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("INSERT INTO Employee(LastName,FirstName,Title) VALUES (:lname, :fname, :title)");
    q.bindValue(":lname",lastName);
    q.bindValue(":fname",firstName);
    q.bindValue(":title",title);
    if(q.exec())
    {
        m_model.addItem(lastName,firstName,title);
        m_filterModel.invalidate();
    }
}
