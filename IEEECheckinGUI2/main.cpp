#include "ieeecheckingui2.h"
#include "ieeecheckin.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    IEEECheckin w;
    w.show();

    return a.exec();
}
