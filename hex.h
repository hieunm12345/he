#ifndef HEX_H
#define HEX_H

#include <QWidget>
#include <form.h>

namespace Ui {
class hex;
}

class hex : public QWidget
{
    Q_OBJECT

public:
    explicit hex(QWidget *parent = nullptr);
    ~hex();

private slots:
    void on_pushButton_clicked();
    void receiveData(QString);
    QString convertDecToHex(QString);

private:
    Ui::hex *ui;
    Form *a = new Form();
};

#endif // HEX_H
