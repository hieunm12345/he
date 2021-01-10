#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "qmessagebox.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void sendData(QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    bool isSoNguyenDuong(QString);

private:
    Ui::Form *ui;
};

#endif // FORM_H
