#include "mylist.h"

myList::myList(QObject *parent)
    : QAbstractListModel(parent)
{
}

int myList::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    return list.count();

    // FIXME: Implement me!
}

QVariant myList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    if (index.row() >= list.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return list.at(index.row());

    // FIXME: Implement me!
    return QVariant();
}

bool myList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

            list.replace(index.row(), value.toString());
            emit dataChanged(index, index, {role});
            return true;
        }
        return false;
}


Qt::ItemFlags myList::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool myList::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for(int row=0; row < rows; row++){
        list.insert(position, "");
    }

    endInsertRows();
    return true;
}

bool myList::removeRows(int position, int rows, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for(int row=0; row < rows; row++){
        list.removeAt(position);
    }

    endRemoveRows();
    return true;
}

