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

QString AddCountryDialog::countryEditText() const
{
    return m_countryEditText;
}

int AddCountryDialog::co2EditText() const
{
    return m_co2EditText;
}




void AddCountryDialog::on_buttonBox_accepted()
{
    m_countryEditText = ui->countryEdit->text();
    m_co2EditText = ui->co2Edit->text().toInt();
}

