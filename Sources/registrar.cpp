#include "../Headers/registrar.h"
#include "ui_registrar.h"

/**
 * Constructor del objeto Registrar donde
 * se indica los valores y cómo se usarán
 * los atributos que contiene
*/
Registrar::Registrar(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::Registrar),
                                        mysqldatabase("b8zoi8ke3joixsmcphqk",
                                                      "unpbr9fhpxgwop4s",
                                                      "4dUkZgd2ULJtrYFbqzkd",
                                                      "b8zoi8ke3joixsmcphqk-mysql.services.clever-cloud.com",
                                                      3306)
{
    ui->setupUi(this);
    //Verifica si se puede establecer la conexion a la base de datos
    try
    {
        if (!mysqldatabase.openConnection())
            throw "mysqldatabase.lastError";
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
Registrar::~Registrar()
{
    mysqldatabase.closeConnection();
    delete ui;
}
//Accion que se tomara al oprimir el boton de registrar en la UI
void Registrar::on_pushButton_clicked()
{
    try
    {
        // Extrae los datos ingresados en la UI y las guarda en variables de tipo QString
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

        //Crea e introduce los datos en un archivo de texto de respaldo
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

        //Se crea una variable que contenga la instruccion en lenguaje SQL para introducir los datos a la base de datos
        QString buffer;
        buffer.append("INSERT INTO registro VALUES ('" + nss + "','" + nombre + "','" + apellp + "','" +
                      apellm + "','" + edad + "','" + sexo + "','" + sangre + "','" + alergias + "','" +
                      ocupacion + "','" + telefono + "');");

        //Se crea un objeto que ejecuta la orden que esta en buffer
        QSqlQuery registro;
        registro.prepare(buffer);

        //Se ejecuta la variable registro
        if (!registro.exec())
            throw registro.lastError().text();
      
        //Se limpian las casillas luego de registrar el paciente con exito
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
    }

    //Manejador de las excepciones
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
        QMessageBox::critical(this, "Error", "Error por defecto");
    }
}

/**
 * Esta función es la acción que se ejecuta
 * al presionar le botón -Ver pacientes-
 * creando un objeto de tipo ver_pacientes
 * y lo muestra en pantalla
 */
void Registrar::on_pushButton_2_clicked()
{
    ver_pacientes *ver = new ver_pacientes;
    ver->show();
}

/**
 * Funcion que devuelve una variable booleana y recibe
 * una variable de tipo String para validar si es
 * un número entero válido
*/
bool Registrar::isValidInt(string str)
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

