#ifndef MAILER_H
#define MAILER_H

#include <QDialog>
#include <QMainWindow>
#include "smtp.h"
#include <QtWidgets/QMessageBox>

namespace Ui {
class Mailer;
}

class Mailer : public QDialog
{
    Q_OBJECT

public:
    explicit Mailer(QWidget *parent = nullptr);
    ~Mailer();

private slots:
    void sendMail();
    void mailSent(QString);


    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Mailer *ui;
};

#endif // MAILER_H
