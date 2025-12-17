#include "mainwindow.h"
#include <QApplication>
#include "page_login.h"
#include "stusql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    stuSql sql;
    return a.exec();
}
