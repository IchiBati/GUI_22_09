#include "demo.h"
#include "ui_demo.h"

demo::demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo)
{
    ui->setupUi(this);
}

demo::~demo()
{
    delete ui;
}
