#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "carbonfootprintdatabase.h"
#include <addcountrydialog.h>
#include <QItemSelectionModel>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userlistmodel(CarbonFootprintDatabase::instance().countries(), this)

{
    ui->setupUi(this);


    ui->editButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->actionDelete->setEnabled(false);
    ui->userTableView->setModel(&m_userlistmodel);
    m_select = ui->userTableView->selectionModel();


    connect(m_select, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(EnableDeleteWhenSelected()));
    connect(m_select, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(EnableEditWhenSelected()));


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
    dialog.setWindowTitle("Add Country");

    if(dialog.exec() == QDialog::Accepted){
        m_userlistmodel.insertRows(CarbonFootprintDatabase::instance().countries().length(), 1, CountryFootprint(dialog.countryEditText(), dialog.co2EditText().toInt()));
    }
}


void MainWindow::on_actionAdd_triggered()
{
    on_addButton_clicked();
}



void MainWindow::on_deleteButton_clicked()
{
    QItemSelectionModel *select = ui->userTableView->selectionModel();
    m_userlistmodel.removeRows(select->selectedRows()[0].row(), 1);
}


void MainWindow::on_actionDelete_triggered()
{
    on_deleteButton_clicked();
}



void MainWindow::EnableDeleteWhenSelected()
{
    if(m_select->hasSelection()){
        ui->deleteButton->setEnabled(true);
        ui->actionDelete->setEnabled(true);
    }else{
        ui->deleteButton->setEnabled(false);
        ui->actionDelete->setEnabled(false);
    }



}


void MainWindow::EnableEditWhenSelected()
{
    if(m_select->hasSelection()){
        ui->editButton->setEnabled(true);
        ui->actionEdit->setEnabled(true);
    }else{
        ui->editButton->setEnabled(false);
        ui->actionEdit->setEnabled(false);
    }
}







void MainWindow::on_editButton_clicked()
{
    AddCountryDialog dialog;
    dialog.setWindowTitle("Edit Country");
    QModelIndex index = m_select->selectedRows()[0];
    CountryFootprint country = m_userlistmodel.countries()[index.row()];
    dialog.setCountryEditText(country.nameOfCountry());
    dialog.setco2EditText(QString::number(country.co2InKilogram()));

    if(dialog.exec() == QDialog::Accepted){
        CountryFootprint country(dialog.countryEditText(), dialog.co2EditText().toInt());
        QVariant countryVariant(QVariant::fromValue(country));
        m_userlistmodel.setData(index, countryVariant);
    }

}

