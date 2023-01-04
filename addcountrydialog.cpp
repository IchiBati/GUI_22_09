#include "addcountrydialog.h"
#include "ui_addcountrydialog.h"


AddCountryDialog::AddCountryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCountryDialog)
{
    ui->setupUi(this);

    //Disable OK Button of Buttonbox while lineedits are empty
    ui->buttonBox->buttons()[0]->setEnabled(!(ui->countryEdit->text().isEmpty() || ui->co2Edit->text().isEmpty()));
    connect(ui->countryEdit, SIGNAL(textEdited(QString)),this, SLOT(disableEmptyLineEdit()));
    connect(ui->co2Edit, SIGNAL(textEdited(QString)),this, SLOT(disableEmptyLineEdit()));

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


void AddCountryDialog::disableEmptyLineEdit()
{
    if(ui->co2Edit->text().isEmpty() || ui->countryEdit->text().isEmpty()){
        ui->buttonBox->buttons()[0]->setEnabled(false);
    }else{
        ui->buttonBox->buttons()[0]->setEnabled(true);
    }
}

