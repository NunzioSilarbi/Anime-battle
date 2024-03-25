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
    ui->comboBox_music->addItem("Struggle of sadness (YuYu akusho)");
    ui->comboBox_music->addItem("Wildfire (Honkai star rail)");
    ui->comboBox_music->addItem("Mass destruction (Persona 3 reload)");
    ui->comboBox_music->addItem("Get wild (City hunter)");
    ui->comboBox_music->addItem("Overdrive (JoJo's Bizarre Adventure)");
    ui->comboBox_music->addItem("Passionate duelist (Yu-Gi-Oh!)");
    ui->comboBox_music->addItem("Hyperdrive (Yu-Gi-Oh 5D's)");
    ui->comboBox_music->addItem("River in the desert (Persona 5 royal)");
    ui->comboBox_music->addItem("Tapion's ocarina (Dragon ball Z)");
    ui->comboBox_music->addItem("Yusha no fue (Dragon ball Z)");
    ui->comboBox_music->addItem("Kaidoku funou (Code geass)");
    ui->comboBox_music->addItem("Pegasus fantasy (Saint Seiya)");
    ui->comboBox_music->addItem("Pegasus forever (Saint Seiya : the Hades chapter Inferno)");
    ui->comboBox_music->addItem("Sign (Naruto Shippuden)");
    ui->comboBox_music->addItem("Bioman (Bernard Minet)");


    // Connectez le signal activated du QComboBox à la fonction onMusicChanged
    connect(ui->comboBox_music, QOverload<int>::of(&QComboBox::activated), this, &Param::onMusicChanged);

    // Initialisez le lecteur multimédia
    player = new QMediaPlayer(this);

    // Définissez le volume initial à 50%
    player->setVolume(50);

    // Jouez automatiquement la musique "Wildfire" au lancement de l'application
    playMusic("Struggle of sadness (YuYu akusho)");

    // Connectez le signal clicked du bouton "Go Back" à la fonction goBack
    connect(ui->button_param_back, &QPushButton::clicked, this, &Param::goBack);

    // Connectez le signal valueChanged du curseur de volume à la fonction adjustVolume
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &Param::adjustVolume);
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

    if (musicName == "Wildfire (Honkai star rail)") {
        musicFileName = "Wildfire.mp3";
    }else if (musicName == "Mass destruction (Persona 3 reload)") {
        musicFileName = "Mass_Destruction.mp3";
    }else if (musicName == "Get wild (City hunter)") {
        musicFileName = "Get_Wild.mp3";
    }else if (musicName == "Overdrive (JoJo's Bizarre Adventure)") {
        musicFileName = "Overdrive.mp3";
    }else if (musicName == "Passionate duelist (Yu-Gi-Oh!)") {
        musicFileName = "Passionate_duelist.mp3";
    }else if (musicName == "River in the desert (Persona 5 royal)") {
        musicFileName = "River_in_the_desert.mp3";
    }else if (musicName == "Tapion's ocarina (Dragon ball Z)") {
        musicFileName = "Tapion_Ocarina.mp3";
    }else if (musicName == "Yusha no fue (Dragon ball Z)") {
        musicFileName = "Yusha_no_fue.mp3";
    } else if (musicName == "Kaidoku funou (Code geass)") {
        musicFileName = "Kaidoku_Funou.mp3";
    } else if (musicName == "Pegasus fantasy (Saint Seiya)") {
        musicFileName = "Pegasus_Fantasy.mp3";
    }else if (musicName == "Pegasus forever (Saint Seiya : the Hades chapter Inferno)") {
        musicFileName = "Pegasus_Forever.mp3";
    } else if (musicName == "Sign (Naruto Shippuden)") {
        musicFileName = "Sign.mp3";
    }else if (musicName == "Hyperdrive (Yu-Gi-Oh 5D's)") {
        musicFileName = "Hyperdrive.mp3";
    } else if (musicName == "Struggle of sadness (YuYu akusho)") {
        musicFileName = "Struggle_of_sadness.mp3";
    } else if (musicName == "Bioman (Bernard Minet)") {
        musicFileName = "Bioman.mp3";
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

void Param::adjustVolume(int volume)
{
    // Définissez le volume du lecteur multimédia en utilisant la valeur du curseur de volume
    player->setVolume(volume);
}
