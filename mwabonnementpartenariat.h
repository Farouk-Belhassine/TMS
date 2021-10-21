#ifndef MWABONNEMENTPARTENARIAT_H
#define MWABONNEMENTPARTENARIAT_H

#include <QDialog>
#include <QString>
#include "modifier_abonnement.h"
#include "modifier_partenariat.h"

namespace Ui {
class mwabonnementpartenariat;
}

class mwabonnementpartenariat : public QDialog
{
    Q_OBJECT

public:
    explicit mwabonnementpartenariat(QWidget *parent = nullptr);
    ~mwabonnementpartenariat();

private slots:
    void on_pushButton_clicked();

    void on_supprimer_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_rech_textChanged(const QString &arg1);

    void on_rech_textEdited(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_rechpar_textChanged(const QString &arg1);

    void on_rechpar_textEdited(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::mwabonnementpartenariat *ui;
    modifier_abonnement mtable;
    modifier_partenariat mptable;
};

#endif // MWABONNEMENTPARTENARIAT_H
