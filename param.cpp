// param.cpp

#include "param.h"
#include "ui_param.h"
#include "animebattle.h" // Incluez le fichier d'en-tête d'Animebattle si nécessaire

Param::Param(QWidget *parent, QMediaPlayer *player) : QWidget(parent), ui(new Ui::Param), player(player)
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

    ui->comboBox_background->addItem("Kame House (Dragon ball Z)");
    ui->comboBox_background->addItem("Raimon (Inazuma eleven)");
    ui->comboBox_background->addItem("Vallée de la fin (Naruto)");

    ui->comboBox_background->setCurrentIndex(0);
    changeBackground("Kame House (Dragon ball Z)");


    // Connectez le signal activated du QComboBox à la fonction onMusicChanged
    connect(ui->comboBox_music, QOverload<int>::of(&QComboBox::activated), this, &Param::onMusicChanged);


    // Connectez le signal clicked du bouton "Go Back" à la fonction goBack
    connect(ui->button_param_back, &QPushButton::clicked, this, &Param::goBack);

    // Connectez le signal valueChanged du curseur de volume à la fonction adjustVolume
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &Param::adjustVolume);

    connect(ui->comboBox_background, QOverload<const QString &>::of(&QComboBox::activated), this, &Param::changeBackground);

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

    // Jouer la nouvelle musique
    player->setMedia(QUrl("qrc:/static/Music/" + musicFileName));

    // Connecter le signal endOfMedia à la fonction pour relancer la musique une fois terminée
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

void Param::changeBackground(const QString &imageName)
{
    QString imagePath;

    if (imageName == "Kame House (Dragon ball Z)") {
        imagePath = ":/static/BG/Kame_house.jpg";
    } else if (imageName == "Raimon (Inazuma eleven)") {
        imagePath = ":/static/BG/Raimon.png";
    } else if (imageName == "Vallée de la fin (Naruto)") {
        imagePath = ":/static/BG/Vallee_de_la_fin.png";
    }

    QPixmap image(imagePath);
    ui->label_image->setPixmap(image.scaled(ui->label_image->size(), Qt::KeepAspectRatio));
}


