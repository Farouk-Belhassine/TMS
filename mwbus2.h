#ifndef MWBUS2_H
#define MWBUS2_H

#include <bus2.h>
#include <QDialog>
#include "mailer.h"

namespace Ui {
class mwbus2;
}

class mwbus2 : public QDialog
{
    Q_OBJECT

public:
    explicit mwbus2(QWidget *parent = nullptr);
    ~mwbus2();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();



    void on_pb_supprimer_clicked();

    void on_pb_show_clicked();

    void on_tabplace_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void on_pb_retour_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::mwbus2 *ui;
    bus2 tmp;
    Mailer *m;
};

#endif // MWBUS2_H
