#include "../Headers/offregistro.h"
#include "ui_offregistro.h"

/**
 * Constructor del objeto offregistro donde
 * se indica los valores y cómo se usarán
 * los atributos que contiene
*/
offregistro::offregistro(QWidget *parent) : QDialog(parent),
                                            ui(new Ui::offregistro),
                                            sqlitedatabase(QDir::currentPath() + "/registro.db")

{
    ui->setupUi(this);
    try
    {
        if (!sqlitedatabase.openConnection())
            throw "Error de conexión";
    }
    catch (const char *msg)
    {
        QMessageBox::critical(this, "Error", msg);
    }
}

/**
 * Se invoca el destructor del objeto al cerrar
 * la ventana, primero cierra la conexión de la
 * base de datos y luego destruye el objeto
 */
offregistro::~offregistro()
{
    sqlitedatabase.closeConnection();
    delete ui;
}

/**
 * Esta función se activa al presionar el botón -Ver pacientes-
 * para cargar la tabla de los datos que fueron
 * introducidos por el usuario en la base de datos
 * dentro del archivo con extensión .db
 */
void offregistro::on_pushButton_2_clicked()
{
    //Se muestra la ventana correspondiente
    offver_database *verSqlite = new offver_database;
    verSqlite->show();
}

/**
 * Esta función se activa al presionar el botón -Registrar-
 * para guardar los datos que fueron introducidos
 * por el usuario (después de ser validados) en una
 * base de datos dentro de un archivo con
 * extensión .db y en un archivo de texo como respaldo
 */
void offregistro::on_pushButton_clicked()
{
    try
    {

        // Extrae los datos introducidos por el usuario en una variable de tipo QString
        QString nss = ui->nss->text();
        QString nombre = ui->nombre->text();
        QString apellp = ui->apellp->text();
        QString apellm = ui->apellm->text();
        QString edad = ui->edad->text();
        QString sexo = ui->sexo->text();
        QString sangre = ui->sangre->text();
        QString alergias = ui->alergias->text();
        QString ocupacion = ui->ocupacion->text();
        QString telefono = ui->telefono->text();

        //Valida los datos ingresados por el usuario
        if (nss.length() == 0 || nss.length() != 11)
            throw "La casilla de Número de Seguro Social no es válida";
        if (nombre.length() == 0)
            throw "El Nombre no es válido";
        if (apellp.length() == 0)
            throw "El Apellido Paterno no es válido";
        if (apellm.length() == 0)
            throw "El Apellido Materno no es válido";
        if (telefono.length() != 0 && isValidInt(telefono.toStdString())==false)
            throw "El Teléfono es inválido";
        if (edad.length() != 0 && isValidInt(edad.toStdString())==false)
            throw "La edad no es válida";

        //Se crea un archivo de texto de respaldo y se introducen los datos
        ofstream myfile("Pacientes.txt", ofstream::app);
        myfile << "Número de Seguro Social: " << nss.toStdString() << endl;
        myfile << "Nombre(S): " << nombre.toStdString() << endl;
        myfile << "Apellido Paterno: " << apellp.toStdString() << endl;
        myfile << "Apellido Materno: " << apellm.toStdString() << endl;
        myfile << "Edad: " << edad.toStdString() << endl;
        myfile << "Sexo: " << sexo.toStdString() << endl;
        myfile << "Tipo de Sangre: " << sangre.toStdString() << endl;
        myfile << "Alergias: " << alergias.toStdString() << endl;
        myfile << "Ocupación: " << ocupacion.toStdString() << endl;
        myfile << "Telefono: " << telefono.toStdString() << endl;
        myfile << "\t\t-----------------------" << endl;

        //Objeto que guarda las instrucciones en lenguaje SQL para crear una tabla y se ejecuta
        QSqlQuery crear;
        if (!crear.exec("CREATE TABLE IF NOT EXISTS registro "
                        "(NSS VARCHAR(20) NOT NULL PRIMARY KEY, Nombres VARCHAR(30) NOT NULL,"
                        "Apellido_Paterno VARCHAR(20) NOT NULL, Apellido_Materno VARCHAR(20) NOT NULL,"
                        "Edad VARCHAR(10), Sexo VARCHAR(10), Sangre VARCHAR(20),"
                        "Alergias VARCHAR(20),Ocupación VARCHAR(30), Teléfono VARCHAR(20))"))
            throw crear.lastError().text();

        //Se crea un objeto que guarda las instrucciones en lenguaje SQL
        QString buffer2;
        buffer2.append("INSERT INTO registro VALUES ('" + nss + "','" + nombre + "','" + apellp + "','" +
                       apellm + "','" + edad + "','" + sexo + "','" + sangre + "','" + alergias + "','" +
                       ocupacion + "','" + telefono + "');");

        //Objeto que guarda el objeto buffer2
        QSqlQuery registrar;
        registrar.prepare(buffer2);

        //Se ejecuta la instruccion
        if (!registrar.exec())
            throw "Error al registrar, Número de Seguro Social repetido";

        QMessageBox exito;
        exito.setText("Registrado con éxito");
        exito.show();

        //Se limpian los campos de texto al registrar un paciente con exito
        ui->nss->clear();
        ui->nombre->clear();
        ui->apellp->clear();
        ui->apellm->clear();
        ui->edad->clear();
        ui->sexo->clear();
        ui->sangre->clear();
        ui->alergias->clear();
        ui->ocupacion->clear();
        ui->telefono->clear();


        //Manejador de excepciones
    }
    catch (const char *msg)
    {
        QMessageBox::critical(this, "Error", msg);
    }
    catch (exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());
    }
    catch (...)
    {
        QMessageBox::critical(this, "Error", "Error por defecto, vuelva a intentar");
    }
}

/**
 * Funcion que devuelve una variable booleana y recibe
 * una variable de tipo String para validar si es
 * un número entero válido
*/
bool offregistro::isValidInt(string str)
{

    int inicio = 0, i = 0;
    bool valido = true, signo = false;

    if (str.length() == 0)
        valido = false;

    if (str.at(0) == '-' || str.at(0) == '+')
    {
        signo = true;
        inicio = 1;
    }
    if (signo && str.length() == 1)
        valido = false;

    i = inicio;
    for (i = inicio; valido && i < int(str.length()); i++)
    {
        if (!isdigit(str.at(i)))
            valido = false;
    }
    return valido;
}
