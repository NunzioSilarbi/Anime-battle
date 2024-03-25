#include "animebattle.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/static/Ico/ABLogo.ico"));
    Animebattle w;
    w.show();
    return a.exec();
}

