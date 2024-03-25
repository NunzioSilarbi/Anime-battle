// param.cpp

#include "param.h"
#include "ui_param.h"
#include "animebattle.h" // Incluez le fichier d'en-tête d'Animebattle si nécessaire

Param::Param(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Param)
{
    ui->setupUi(this);

    // Ajoutez vos musiques à la liste déroulante
    ui->comboBox_music->addItem("Music 1");
    ui->comboBox_music->addItem("Music 2");
    ui->comboBox_music->addItem("Music 3");

    // Connectez le signal activated du QComboBox à la fonction onMusicChanged
    connect(ui->comboBox_music, QOverload<int>::of(&QComboBox::activated), this, &Param::onMusicChanged);

    // Initialisez le lecteur multimédia
    player = new QMediaPlayer(this);

    // Jouez automatiquement la musique "Wildfire" au lancement de l'application
    playMusic("Music 1");

    // Connectez le signal clicked du bouton "Go Back" à la fonction goBack
    connect(ui->button_param_back, &QPushButton::clicked, this, &Param::goBack);
}

Param::~Param()
{
    delete ui;
}

void Param::onMusicChanged(int index)
{
    // Récupérez le nom de la musique sélectionnée
    QString musicName = ui->comboBox_music->currentText();

    // Faites quelque chose avec le nom de la musique sélectionnée (par exemple, jouer la musique)
    playMusic(musicName);
}

void Param::playMusic(const QString &musicName)
{
    // Définissez le chemin de la musique en fonction de son nom
    QString musicFileName;

    if (musicName == "Music 1") {
        musicFileName = "Wildfire.mp3";
    } else if (musicName == "Music 2") {
        musicFileName = "Mass_Destruction.mp3";
    } else if (musicName == "Music 3") {
        musicFileName = "Get_Wild.mp3";
    }

    // Jouez la musique
    player->setMedia(QUrl("qrc:/static/Music/" + musicFileName));

    // Connectez le signal endOfMedia à la fonction pour relancer la musique une fois terminée
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Param::onMediaStatusChanged);

    player->play();
}

void Param::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        // Relancer la musique
        player->setPosition(0);
        player->play();
    }
}

void Param::goBack()
{
    // Instanciez la fenêtre Animebattle
    Animebattle *animeBattle = new Animebattle();

    // Affichez la fenêtre Animebattle
    animeBattle->show();

    // Fermez la fenêtre Param
    this->close();
}
