#include <QtGui/QApplication>
#include "organizer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Organizer w;
    w.show();
    return a.exec();
}
