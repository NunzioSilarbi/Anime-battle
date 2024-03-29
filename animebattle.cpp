#include "animebattle.h"
#include "ui_animebattle.h"
#include "param.h"
#include "character_select.h"

bool Animebattle::musicStarted = false;

Animebattle::Animebattle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Animebattle)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);


    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            if (loopMusic) {
                player->setPosition(0);
                player->play();
            }
        }
    });

    player->play();

    loopMusic = true;

    connect(ui->button_param, &QPushButton::clicked, this, &Animebattle::goToParamWindow);
    connect(ui->button_JcIA, &QPushButton::clicked, this, &Animebattle::goToCharacterSelectWindow);
    connect(ui->Exit, &QPushButton::clicked, this, &Animebattle::close);
}

void Animebattle::goToParamWindow()
{
    this->close();

    Param *paramWindow = new Param(nullptr, player);
    paramWindow->show();
}

void Animebattle::goToCharacterSelectWindow()
{
    this->close();
    Character_select *characterSelectWindow = new Character_select(nullptr);
    characterSelectWindow->show();
}

void Animebattle::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

    if (!musicStarted) {
        player->setMedia(QUrl("qrc:/static/Music/Struggle_of_sadness.mp3"));
        player->setVolume(50);
        player->play();
        musicStarted = true;
    }
}


Animebattle::~Animebattle()
{
    delete ui;
}
