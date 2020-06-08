#include "../Headers/offver_database.h"
#include "ui_offver_database.h"

/**
 * Constructor del objeto offver_database donde
 * se indica los valores y cómo se usarán
 * los atributos que contiene
*/
offver_database::offver_database(QWidget *parent) : QDialog(parent),
                                                    ui(new Ui::offver_database)
{
    ui->setupUi(this);

    //Se abre la base de datos localizada en la carpeta del ejecutable
    QSqlDatabase mDatabase2;
    mDatabase2 = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase2.setDatabaseName(QDir::currentPath() + "/registro.db");
    mDatabase2.open();
    //Se crea una tabla que almacenara la que esta en la base de datos
    mModel = new QSqlTableModel(this);
    mModel->setTable("registro");
    mModel->select();
    //Semuestra la tabla creada
    ui->tableView->setModel(mModel);

    // Se crea el filtro para las búsquedas
    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(mModel);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
}

/**
 * Se invoca el destructor del objeto al cerrar
 * la ventana para destruirlo
 */
offver_database::~offver_database()
{
    delete ui;
}

/**
 * Esta función se activa al presionar el
 * botón -Eliminar paciente- para eliminar
 * la fila del paciente que se esté seleccionando,
 * luego recarga la tabla
 */
void offver_database::on_pushButton_clicked()
{
    //Remueve la fila del paciente seleccionado por el usuario
    mModel->removeRow(ui->tableView->currentIndex().row());
    mModel->select();
}

/**
 * Esta función se activa al presionar el
 * botón -Buscar- para buscar en la base de
 * datos alguna coincidencia con el texto
 * que el usuario introdujo
 */
void offver_database::on_buscar_clicked()
{
    //Se almacena el texto introducido por el usuario en la busqueda del paciente
    QString busqueda = ui->lineEdit->text();

    //Se crea una nueva tabla donde solo aparezca las filas que contenga el texto introducido por el usuario
    proxy->setFilterFixedString(busqueda);

    //Se muestra en el cuadro de la tabla el filtro
    ui->tableView->setModel(proxy);
}

/**
 * Esta función se activa al presionar el
 * botón -Ver lista completa- para abrir una
 * ventana donde aparece el archivo .txt que se guardó como
 * respaldo
 */
void offver_database::on_pacientes_eliminados_clicked()
{
    ver_pacientes_offline *ver = new ver_pacientes_offline;
    ver->show();
}
