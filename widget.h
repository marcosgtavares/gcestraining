#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mylist.h"
#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    myList *m_model;
    QSortFilterProxyModel *myFilter;

};
#endif // WIDGET_H
