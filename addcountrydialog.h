#ifndef ADDCOUNTRYDIALOG_H
#define ADDCOUNTRYDIALOG_H

#include "countryfootprint.h"

#include <QDialog>

namespace Ui {
class AddCountryDialog;
}

class AddCountryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCountryDialog(QWidget *parent = nullptr);
    ~AddCountryDialog();

    QString countryEditText() const;
    QString co2EditText() const;

    void setCountryEditText(QString country);
    void setco2EditText(QString co2);


signals:
    void lineEditTextChanged();



private slots:
    void on_buttonBox_accepted();
    void disableEmptyLineEdit();
    void updateLineEditText();

private:
    Ui::AddCountryDialog *ui;
    QString m_countryEditText;
    QString m_co2EditText;
};

#endif // ADDCOUNTRYDIALOG_H
