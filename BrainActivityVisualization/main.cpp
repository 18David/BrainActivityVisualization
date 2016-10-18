#include "gmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GMainWindow w;
    w.show();

    return a.exec();
}
