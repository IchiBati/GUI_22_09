#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userlistmodel.h"
#include <QItemSelectionModel>

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

    void on_actionAdd_triggered();

    void on_deleteButton_clicked();

    void EnableDeleteWhenSelected();

    void EnableEditWhenSelected();

    void on_actionDelete_triggered();

    void on_editButton_clicked();

private:
    Ui::MainWindow *ui;
    UserListModel m_userlistmodel;
    QItemSelectionModel* m_select;
};
#endif // MAINWINDOW_H
