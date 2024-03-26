#ifndef ANIMEBATTLE_H
#define ANIMEBATTLE_H

#include <QMainWindow>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Animebattle;
}
QT_END_NAMESPACE

class Animebattle : public QMainWindow
{
    Q_OBJECT

private slots:
    void goToParamWindow();
    void showEvent(QShowEvent *event) override;


public:
    Animebattle(QWidget *parent = nullptr);
    static bool musicStarted;
    ~Animebattle();

private:
    Ui::Animebattle *ui;
    QMediaPlayer *player;
    bool loopMusic;

};
#endif // ANIMEBATTLE_H
