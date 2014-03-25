#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H

#include <QAbstractTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>


class EmployeeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit EmployeeModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QHash<int, QByteArray> roleNames() const;

    void load();
    void clear();

    void print();

    void addItem(QString lastName, QString firstName, QString title);

signals:

public slots:

private:
    QList<QList<QString> > m_list;

};

#endif // EMPLOYEEMODEL_H
