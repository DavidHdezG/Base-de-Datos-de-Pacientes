#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>

namespace Ui {
class registro;
}

class registro : public QWidget
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    ~registro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registro *ui;
};

#endif // REGISTRO_H
