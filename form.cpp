#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    QMessageBox a;
    a.setWindowTitle("Close");
    a.setText("Ban co muon close khong?");
    a.setInformativeText("Nhan Yes de close");
    a.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    a.setDefaultButton(QMessageBox::No);
    a.setIcon(QMessageBox::Warning);
    int ketQua = a.exec();
    switch (ketQua) {
        case QMessageBox::Yes:
        close();
        break;
    case QMessageBox::No:
        break;
}
}

bool Form::isSoNguyenDuong(QString str)
{
    if(str.length() == 0)
    {
        return false;
    }
    if((str.at(0) < '0' || str.at(0) > '9') && str.at(0) != '-')
    {
        return false;
    }
    if(str.at(0) == '-' && str.length() == 1)
    {
        return false;
    }
    for(int i = 1;i < str.length(); i++)
    {
        if(str.at(i) < '0' || str.at(i) > '9')
        {
            return false;
        }
    }
    return true;
}

void Form::on_pushButton_clicked()
{
    QString str;
    str = ui->lineEdit->text();
    if(isSoNguyenDuong(str))
    {
        emit sendData(str);
    } else
    {
        emit sendData("0");
    }
    close();
}

