#include "animebattle.h"
#include "param.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/static/Ico/ABLogo.ico"));
    Animebattle w;
    w.setFixedSize(940, 567);
    w.show();
    return a.exec();
}
