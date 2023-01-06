#include "addcountrydialog.h"
#include "ui_addcountrydialog.h"


AddCountryDialog::AddCountryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCountryDialog),
    m_countryEditText(""),
    m_co2EditText("")

{
    ui->setupUi(this);




    //Disable OK Button of Buttonbox while lineedits are empty
    ui->buttonBox->buttons()[0]->setEnabled(!(ui->countryEdit->text().isEmpty() || ui->co2Edit->text().isEmpty()));
    connect(ui->countryEdit, SIGNAL(textEdited(QString)),this, SLOT(disableEmptyLineEdit()));
    connect(ui->co2Edit, SIGNAL(textEdited(QString)),this, SLOT(disableEmptyLineEdit()));
    connect(this, SIGNAL(lineEditTextChanged()), this, SLOT(updateLineEditText()));

}

AddCountryDialog::~AddCountryDialog()
{
    delete ui;
}

QString AddCountryDialog::countryEditText() const
{
    return m_countryEditText;
}

QString AddCountryDialog::co2EditText() const
{
    return m_co2EditText;
}

void AddCountryDialog::setCountryEditText(QString country)
{
    m_countryEditText = country;
    emit lineEditTextChanged();
}

void AddCountryDialog::setco2EditText(QString co2)
{
    m_co2EditText = co2;
    emit lineEditTextChanged();
}




void AddCountryDialog::on_buttonBox_accepted()
{
    m_countryEditText = ui->countryEdit->text();
    m_co2EditText = ui->co2Edit->text();
}


void AddCountryDialog::disableEmptyLineEdit()
{
    if(ui->co2Edit->text().isEmpty() || ui->countryEdit->text().isEmpty()){
        ui->buttonBox->buttons()[0]->setEnabled(false);
    }else{
        ui->buttonBox->buttons()[0]->setEnabled(true);
    }
}

void AddCountryDialog::updateLineEditText()
{
    ui->countryEdit->setText(m_countryEditText);
    ui->co2Edit->setText(m_co2EditText);
}

