#ifndef MWPLACE_H
#define MWPLACE_H

#include "place.h"
#include <QDialog>
#include <QMainWindow>
#include "mailer.h"

namespace Ui {
class mwplace;
}

class mwplace : public QDialog
{
    Q_OBJECT

public:
    explicit mwplace(QWidget *parent = nullptr);
    ~mwplace();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();






    void on_pb_supprimer_clicked();

    void on_pb_show_clicked();

    //void on_tabplace_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pb_retour_clicked();





    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::mwplace *ui;
    Place tmp;
    Mailer *m;
};

#endif // MWPLACE_H
