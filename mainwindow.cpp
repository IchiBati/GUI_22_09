#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "carbonfootprintdatabase.h"
#include <addcountrydialog.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userlistmodel(CarbonFootprintDatabase::instance().countries(), this)

{
    ui->setupUi(this);

    ui->userTableView->setModel(&m_userlistmodel);


}

MainWindow::~MainWindow()
{
    delete ui;
}

UserListModel &MainWindow::userlistModel()
{
    return m_userlistmodel;
}





void MainWindow::on_addButton_clicked()
{

    AddCountryDialog dialog;

    if(dialog.exec() == QDialog::Accepted){
        m_userlistmodel.insertRows(CarbonFootprintDatabase::instance().countries().length(), 1, CountryFootprint(dialog.countryEditText(), dialog.co2EditText()));
    }
}

