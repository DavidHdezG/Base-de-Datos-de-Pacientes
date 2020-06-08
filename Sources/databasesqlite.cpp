#include "databasesqlite.h"

/**
 * Constructor del objeto DatabaseMYSQL donde
 * se indica cómo se usarán los atributos que
 * contiene
*/
databaseSqlite::databaseSqlite(const QString &DatabaseName)
{
    SQLITEdb = QSqlDatabase::addDatabase("QSQLITE");
    SQLITEdb.setDatabaseName(DatabaseName);
}

/**
 * Esta función abre la conexión a la
 * base de datos ubicada en un archivo con
 * extensión database, utilizando la ubicación que
 * se le introduzca.
 * No recibe ningún parámetro pero devuelve un valor
 * de tipo booleano true si la conexión se logra
 */
bool databaseSqlite::openConnection()
{
    return SQLITEdb.open();
}

/**
 * Esta función cierra la conexión a la
 * base de datos utilizando los valores que se le
 * introduzcan en los atributos previamente
 * inicializados.
 * No recibe ningún parametro ni devuelve valores
 */
void databaseSqlite::closeConnection(){
   SQLITEdb.close();
}
