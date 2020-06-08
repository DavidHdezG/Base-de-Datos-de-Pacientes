#include "../Headers/ver_pacientes.h"
#include "ui_ver_pacientes.h"

/**
 * Constructor del objeto ver_pacientes donde
 * se indica los valores y cómo se usarán
 * los atributos que contiene
*/
ver_pacientes::ver_pacientes(QWidget *parent) : QDialog(parent),
                                                ui(new Ui::ver_pacientes)
{
    ui->setupUi(this);
    //Se muestran los datos de la base de datos
    mModelOnline = new QSqlTableModel(this);
    mModelOnline->setTable("registro");
    mModelOnline->select();
    ui->tableView->setModel(mModelOnline);

    // Se crea el filtro para las búsquedas

    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(mModelOnline);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
}

/**
 * Se invoca el destructor del objeto al cerrar
 * la ventana para destruír el objeto
 */
ver_pacientes::~ver_pacientes()
{
    delete ui;
}

/**
 * Esta función se activa al presionar el
 * botón -Eliminar paciente- para eliminar
 * la fila del paciente que se esté seleccionando,
 * luego recarga la tabla
 */
void ver_pacientes::on_pushButton_clicked()
{
    //Remueve toda la fila que el usuario este seleccionando
    mModelOnline->removeRow(ui->tableView->currentIndex().row());
    proxy->removeRow(ui->tableView->currentIndex().row());
    mModelOnline->select();
}

/**
 * Esta función se activa al presionar el
 * botón -Buscar- para buscar en la base de
 * datos alguna coincidencia con el texto
 * que el usuario introdujo
 */
void ver_pacientes::on_buscar_clicked()
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
void ver_pacientes::on_pushButton_2_clicked()
{
    ver_pacientes_offline *ver = new ver_pacientes_offline;
    ver->show();
}
