#ifndef MYLIST_H
#define MYLIST_H

#include <QAbstractListModel>

class myList : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit myList(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;


    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QStringList list;


private:

};

#endif // MYLIST_H
