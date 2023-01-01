#include "mainwindow.h"

#include <QApplication>
#include "carbonfootprintdatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarbonFootprintDatabase cd = CarbonFootprintDatabase::instance();
    MainWindow w;

    w.show();
    return a.exec();
}
