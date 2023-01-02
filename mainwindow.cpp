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





void MainWindow::on_editButton_clicked()
{
    AddCountryDialog dialog;
    dialog.exec();
}

