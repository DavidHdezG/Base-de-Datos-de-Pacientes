#ifndef DATABASEMYSQL_H
#define DATABASEMYSQL_H
#include <QString>
#include <QSqlDatabase>
//Se crea la clase que contiene los atributos necesarios para establecer la conexion a la base de datos
class DatabaseMYSQL
{
public:
    //Objeto que recibe los parametros necesarios para la conexion
    DatabaseMYSQL(const QString &Database,
                  const QString &User,
                  const QString &Password,
                  const QString &Host,
                  int Port);
    //Funcion que abre la conexion
    bool openConnection();
    void closeConnection();
private:
    //Se crea un objeto de tipo QSqlDatabase para crear la base de datos
    QSqlDatabase MYSQLdb;
};

#endif // DATABASEMYSQL_H
