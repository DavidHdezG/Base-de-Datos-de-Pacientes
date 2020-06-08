
#ifndef REGISTRAR_OFFLINE_H
#define REGISTRAR_OFFLINE_H

#include <QDialog>

namespace Ui {
class registrar_offline;
}

class registrar_offline : public QDialog
{
    Q_OBJECT

public:
    explicit registrar_offline(QWidget *parent = nullptr);
    ~registrar_offline();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::registrar_offline *ui;
    void registrar(Ui::registrar_offline*ui);
};


#endif // REGISTRAR_OFFLINE_H
