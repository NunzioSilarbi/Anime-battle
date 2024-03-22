#ifndef ANIMEBATTLE_H
#define ANIMEBATTLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Animebattle;
}
QT_END_NAMESPACE

class Animebattle : public QMainWindow
{
    Q_OBJECT

public:
    Animebattle(QWidget *parent = nullptr);
    ~Animebattle();

private:
    Ui::Animebattle *ui;
};
#endif // ANIMEBATTLE_H
