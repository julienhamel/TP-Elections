#include "mongui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    monGui w;
    w.show();
    return a.exec();
}
