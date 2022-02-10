#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listView->setModel(s);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int row = s->rowCount();
    s->insertRows(row, 1);

    QModelIndex index = s->index(row);

    ui->listView->setCurrentIndex(index);
    s->list.replace(index.row(), ui->lineEdit->text());
    ui->lineEdit->clear();


}

