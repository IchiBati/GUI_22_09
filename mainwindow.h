#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userlistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    UserListModel& userlistModel();

private slots:


    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    UserListModel m_userlistmodel;
};
#endif // MAINWINDOW_H
