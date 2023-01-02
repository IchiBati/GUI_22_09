#include "addcountrydialog.h"
#include "ui_addcountrydialog.h"

AddCountryDialog::AddCountryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCountryDialog)
{
    ui->setupUi(this);
}

AddCountryDialog::~AddCountryDialog()
{
    delete ui;
}
