#ifndef ACERCA_DE_H
#define ACERCA_DE_H
#include <QDialog>

//Se crea el espacio de trabajo que representa la ventana Acerca de
namespace Ui
{
    //Se crea la clase
    class Acerca_de;
} // namespace Ui

//Constructor
class Acerca_de : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit Acerca_de(QWidget *parent = nullptr);
    ~Acerca_de();

private:
    //Apuntador a un objeto del tipo de la clase Acerca_de
    Ui::Acerca_de *ui;
};

#endif // ACERCA_DE_H
