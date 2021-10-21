#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("farouk");
db.setPassword("esprit19");

if (db.open())
test=true;
else throw QString ("Erreur Paramétres"+test);
    return  test;
}

void Connection::closeconnect(){db.close();}
