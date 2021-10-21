#include "login.h"
#include "ui_login.h"
#include "mwc.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connect_clicked()
{
    mwc a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}
