#include "mailer.h"
#include "ui_mailer.h"

Mailer::Mailer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mailer)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

Mailer::~Mailer()
{
    delete ui;
}

void Mailer::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Mailer::mailSent(QString status)
{
    if(status == "Message sent")
       { QMessageBox::critical(nullptr, QObject::tr("L'email"),
                    QObject::tr("email envoyé.\n"
                                ), QMessageBox::Cancel);}}



void Mailer::on_pushButton_clicked()
{

    Mailer::setStyleSheet("background-color: white");
    ui->label->setStyleSheet("color: black");
    ui->label_2->setStyleSheet("color: black");
    ui->label_3->setStyleSheet("color: black");
    ui->label_4->setStyleSheet("color: black");
    ui->label_5->setStyleSheet("color: black");
    ui->label_6->setStyleSheet("color: black");
    ui->label_7->setStyleSheet("color: black");
    ui->pushButton->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_5->setStyleSheet("background-color:#c4c4c4");
    ui->sendBtn->setStyleSheet("background-color:#c4c4c4");
    ui->exitBtn->setStyleSheet("background-color:#c4c4c4");
}

void Mailer::on_pushButton_5_clicked()
{
    Mailer::setStyleSheet("background-color: black");
    ui->label->setStyleSheet("color: white");
    ui->label_2->setStyleSheet("color: white");
    ui->label_3->setStyleSheet("color: white");
    ui->label_4->setStyleSheet("color: white");
    ui->label_5->setStyleSheet("color: white");
    ui->label_6->setStyleSheet("color: white");
    ui->label_7->setStyleSheet("color: white");
    ui->pushButton->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_5->setStyleSheet("background-color:#c4c4c4");
    ui->sendBtn->setStyleSheet("background-color:#c4c4c4");
    ui->exitBtn->setStyleSheet("background-color:#c4c4c4");
}
