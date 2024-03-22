#include "animebattle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Animebattle w;
    w.show();
    return a.exec();
}
