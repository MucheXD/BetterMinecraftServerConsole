#include "rootWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rootWindow w;
    w.show();
    return a.exec();
}
