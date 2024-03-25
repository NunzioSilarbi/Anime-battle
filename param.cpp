#include "param.h"
#include "ui_param.h"
#include <QMediaPlayer>

Param::Param(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Param)
{
    ui->setupUi(this);

    // Define the file name variable
    QString musicFileName = "Overdrive.mp3";

    // Create a QMediaPlayer object
    QMediaPlayer *player = new QMediaPlayer;

    // Set the media source to the background music file using the variable
    player->setMedia(QUrl("qrc:/static/Music/" + musicFileName));

    // Play the background music
    player->play();
}

Param::~Param()
{
    delete ui;
}
