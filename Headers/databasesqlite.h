#ifndef DATABASESQLITE_H
#define DATABASESQLITE_H
#include <QString>
#include <QSqlDatabase>
#include <QDir>

//Se crea la clase que contiene los atributos necesarios para establecer la conexion a la base de datos
class databaseSqlite
{
public:
    //Objeto que recibe el nombre de la base de datos
    databaseSqlite(const QString &DatabaseName);
    //Funcion que abre la conexión
    bool openConnection();
    //Funcion que cierra la conexión
    void closeConnection();

private:
    //Se crea un objeto de tipo QSqlDatabase que crea la base de datos
    QSqlDatabase SQLITEdb;
};

#endif // DATABASESQLITE_H
