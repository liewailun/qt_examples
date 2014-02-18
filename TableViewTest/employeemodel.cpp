#include "employeemodel.h"

EmployeeModel::EmployeeModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Chinook_Sqlite.sqlite");
}

int EmployeeModel::rowCount(const QModelIndex &parent) const
{
    return m_list.count();
}

int EmployeeModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant EmployeeModel::data(const QModelIndex &index, int role) const
{
    if(role == 0)
    {
        return m_list.at(index.row()).at(0);
    }
    else if(role == 1)
    {
        return m_list.at(index.row()).at(1);
    }
    else if(role == 2)
    {
        return m_list.at(index.row()).at(2);
    }
    return QVariant();
}

QHash<int, QByteArray> EmployeeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "LastName";
    roles[1] = "FirstName";
    roles[2] = "Title";
    return roles;
}

void EmployeeModel::load()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT LastName, FirstName, Title FROM Employee;");
    q.exec();

    while(q.next())
    {
        QList<QString> record;
        record.append(q.value(0).toString());
        record.append(q.value(1).toString());
        record.append(q.value(2).toString());
        m_list.append(record);
    }
}

void EmployeeModel::print()
{
    foreach(QList<QString> record, m_list)
    {
        foreach(QString item, record)
        {
            qDebug() << item;
        }
        qDebug() << "\n\n";
    }
}
