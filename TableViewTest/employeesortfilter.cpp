#include "employeesortfilter.h"

EmployeeSortFilter::EmployeeSortFilter(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

void EmployeeSortFilter::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column,order);
}
