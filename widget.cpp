#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_model = new myList;
    ui->listView->setModel(m_model);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int row = m_model->rowCount();
    m_model->insertRows(row, 1);

    QModelIndex index = m_model->index(row);

    ui->listView->setCurrentIndex(index);
    m_model->list.replace(index.row(), ui->lineEdit->text());
    ui->lineEdit->clear();


}

