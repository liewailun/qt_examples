#include "employeesortfilter.h"

EmployeeSortFilter::EmployeeSortFilter(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

void EmployeeSortFilter::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column,order);
}

bool EmployeeSortFilter::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    // index = 0 to filter only first column
    QModelIndex index = sourceModel()->index(source_row, 0 , source_parent);
    return sourceModel()->data(index).toString().contains(filterRegExp());
}
