#ifndef ADDCOUNTRYDIALOG_H
#define ADDCOUNTRYDIALOG_H

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

private:
    Ui::AddCountryDialog *ui;
};

#endif // ADDCOUNTRYDIALOG_H
