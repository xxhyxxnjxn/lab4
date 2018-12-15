#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class TcpSocket;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //void test();
private slots:
    void on_pushButton_clicked();
    void read();
    void sendmsg();
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    TcpSocket* socket;
signals:
    void signal(int s);
};

#endif // DIALOG_H
