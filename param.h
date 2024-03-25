// param.h

#ifndef PARAM_H
#define PARAM_H

#include <QWidget>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Param; }
QT_END_NAMESPACE

class Param : public QWidget
{
    Q_OBJECT

public:
    Param(QWidget *parent = nullptr);
    ~Param();

private slots:
    void onMusicChanged(int index);
    void playMusic(const QString &musicName);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void goBack(); // Nouveau slot pour retourner à Animebattle

private:
    Ui::Param *ui;
    QMediaPlayer *player;
};

#endif // PARAM_H
