#include "CMPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMPlayer w;
    w.show();
    return a.exec();
}
