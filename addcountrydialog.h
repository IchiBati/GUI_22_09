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
    int co2EditText() const;


private slots:


    void on_buttonBox_accepted();

    void disableEmptyLineEdit();

private:
    Ui::AddCountryDialog *ui;
    QString m_countryEditText;
    int m_co2EditText;
};

#endif // ADDCOUNTRYDIALOG_H
