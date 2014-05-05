#ifndef EMPLOYEESORTFILTER_H
#define EMPLOYEESORTFILTER_H

#include <QSortFilterProxyModel>

class EmployeeSortFilter : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit EmployeeSortFilter(QObject *parent = 0);

signals:

public slots:
    void sort(int column, Qt::SortOrder order);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

    QString getLastName(int row);

};

#endif // EMPLOYEESORTFILTER_H
