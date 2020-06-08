#include "registro.h"
#include "ui_registro.h"
#include "registro.h"
#include <bits/stdc++.h>
using namespace std;
registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
}

registro::~registro()
{
    delete ui;
}
