#include "hex.h"
#include "ui_hex.h"
#include "qmessagebox.h"

hex::hex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hex)
{
    ui->setupUi(this);
    connect(a, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
}

hex::~hex()
{
    delete ui;
}

QString hex::convertDecToHex(QString str)
{
    QString output = "";
    if(str.toInt() == 0)
    {
        output = "0x0";
    } else
    {
        int n = str.toInt();
        int intTemp;
        while(n > 0)
        {
            intTemp = n % 16;
            if(intTemp > 9)
            {
                switch(intTemp)
                {
                case 10:
                output = "A" + output;
                break;
                case 11:
                output = "B" + output;
                break;
                case 12:
                output = "C" + output;
                break;
                case 13:
                output = "D" + output;
                break;
                case 14:
                output = "E" + output;
                break;
                case 15:
                output = "F" + output;
                break;
                }
            } else
            {
                output = QString::number(intTemp) + output;
            }
            n = n / 16;
        }
        output = "0x" + output;
    }

    return output;
}

void hex::on_pushButton_clicked()
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

void hex::receiveData(QString str)
{
    ui->lineEdit->setText(convertDecToHex(str));
}
