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


    // Connectez le signal endOfMedia à la fonction pour relancer la musique une fois terminée
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            // Relancer la musique si loopMusic est vrai
            if (loopMusic) {
                player->setPosition(0);
                player->play();
            }
        }
    });

    // Jouez automatiquement la musique au lancement de la fenêtre Animebattle
    player->play();

    // Par défaut, la musique boucle
    loopMusic = true;

    connect(ui->button_param, &QPushButton::clicked, this, &Animebattle::goToParamWindow);
    connect(ui->button_JcIA, &QPushButton::clicked, this, &Animebattle::goToCharacterSelectWindow);
}

void Animebattle::goToParamWindow()
{
    // Fermez la fenêtre Animebattle
    this->close();

    // Créez une nouvelle instance de la fenêtre Param
    Param *paramWindow = new Param(nullptr, player);
    paramWindow->show();
}

void Character_select::goToCharacterSelectWindow()
{
    this->close();
    Character_select *characterSelectWindow = new Character_select(nullptr);
    characterSelectWindow->show();
}

void Animebattle::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

    // Lancez la musique si elle n'a pas déjà été lancée
    if (!musicStarted) {
        //player->setMedia(QUrl("qrc:/static/Music/Struggle_of_sadness.mp3"));
        //player->setVolume(50);
        player->play();
        musicStarted = true; // Mettez à jour le drapeau
    }
}


Animebattle::~Animebattle()
{
    delete ui;
}
