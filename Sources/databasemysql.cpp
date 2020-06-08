#include "databasemysql.h"

/**
 * Constructor del objeto DatabaseMYSQL donde
 * se indica cómo se usarán los atributos que
 * contiene
 */
DatabaseMYSQL::DatabaseMYSQL(const QString &Database,
                             const QString &User,
                             const QString &Password,
                             const QString &Host,
                             int Port)
{
    MYSQLdb = QSqlDatabase::addDatabase("QMYSQL");
    MYSQLdb.setDatabaseName(Database);
    MYSQLdb.setUserName(User);
    MYSQLdb.setPassword(Password);
    MYSQLdb.setHostName(Host);
    MYSQLdb.setPort(Port);
}

/**
 * Esta función abre la conexión a la
 * base de datos utilizando los valores que se le
 * introduzcan en los atributos previamente
 * inicializados.
 * No recibe ningún parámetro pero devuelve un valor
 * de tipo booleano true si la conexión se logra
 */
bool DatabaseMYSQL::openConnection()
{
   return MYSQLdb.open();
}

/**
 * Esta función cierra la conexión a la
 * base de datos utilizando los valores que se le
 * introduzcan en los atributos previamente
 * inicializados.
 * No recibe ningún parámetro ni devuelve valores
 */
void DatabaseMYSQL::closeConnection(){
   MYSQLdb.close();
}
