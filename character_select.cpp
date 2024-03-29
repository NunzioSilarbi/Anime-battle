#include "character_select.h"
#include "ui_character_select.h"
#include "param.h"
#include "animebattle.h"
#include "presets.h"
#include "fight_page.h"
#include <algorithm>
#include <set> // Inclure la bibliothèque pour std::set
#include <ctime> // Inclure la bibliothèque pour la fonction time

Character_select::Character_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Character_select)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &Character_select::goBack);
    connect(ui->presets_button, &QPushButton::clicked, this, &Character_select::goPresetsWindow);
    connect(ui->fight_button, &QPushButton::clicked, this, &Character_select::goFight);

    std::fill(std::begin(characterIds), std::end(characterIds), 0);
    std::fill(std::begin(enemyCharacterIds), std::end(enemyCharacterIds), 0);

    connect(ui->perso_1, &QPushButton::clicked, this, [this]() { updateCharacterIds(1); });
    connect(ui->perso_2, &QPushButton::clicked, this, [this]() { updateCharacterIds(2); });
    connect(ui->perso_3, &QPushButton::clicked, this, [this]() { updateCharacterIds(3); });
    connect(ui->perso_4, &QPushButton::clicked, this, [this]() { updateCharacterIds(4); });
    connect(ui->perso_5, &QPushButton::clicked, this, [this]() { updateCharacterIds(5); });
    connect(ui->perso_6, &QPushButton::clicked, this, [this]() { updateCharacterIds(6); });
    connect(ui->perso_7, &QPushButton::clicked, this, [this]() { updateCharacterIds(7); });
    connect(ui->perso_8, &QPushButton::clicked, this, [this]() { updateCharacterIds(8); });
    connect(ui->perso_9, &QPushButton::clicked, this, [this]() { updateCharacterIds(9); });
    connect(ui->perso_10, &QPushButton::clicked, this, [this]() { updateCharacterIds(10); });
}

void Character_select::goBack()
{
    Animebattle *animeBattle = new Animebattle();
    animeBattle->show();
    this->close();
}

void Character_select::goPresetsWindow()
{
    Presets *presets = new Presets();
    presets->show();
    this->close();
}

void Character_select::goFight()
{
    QString backgroundImagePath = ":/static/BG/Kame_house.jpg"; // Chemin de l'image de fond
    Fight_page *fight_page = new Fight_page(backgroundImagePath);
    fight_page->show();
    this->close();
}


void Character_select::updateCharacterIds(int characterId)
{
    // Vérifiez d'abord si characterId existe déjà dans le tableau
    bool idExists = std::find(std::begin(characterIds), std::end(characterIds), characterId) != std::end(characterIds);

    if (!idExists) { // Si characterId n'existe pas déjà dans le tableau
        // Recherchez le premier emplacement vide dans le tableau characterIds
        int index = -1;
        for (int i = 0; i < 3; ++i) {
            if (characterIds[i] == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) { // Si un emplacement vide est trouvé
            characterIds[index] = characterId; // Met à jour l'emplacement avec l'ID du personnage
        }

        // Si le tableau characterIds est désormais plein, générez des valeurs aléatoires pour enemyCharacterIds
        if (index == 2) {
            // Générer des valeurs aléatoires uniques entre 1 et 10 pour enemyCharacterIds
            std::set<int> usedIds(characterIds, characterIds + 3); // Utilisez std::set pour stocker les IDs déjà utilisés
            srand(time(nullptr)); // Initialiser le générateur de nombres aléatoires
            for (int i = 0; i < 3; ++i) {
                int randomId;
                do {
                    randomId = rand() % 10 + 1; // Générer un nombre aléatoire entre 1 et 10
                } while (usedIds.count(randomId) > 0); // Vérifier si le nombre aléatoire a déjà été utilisé
                enemyCharacterIds[i] = randomId;
                usedIds.insert(randomId); // Ajouter le nombre aléatoire à l'ensemble des nombres déjà utilisés
            }
        }
    }

    // Mettez à jour les images des frames
    updateFrameImages();
}

void Character_select::updateFrameImages()
{

    // Afficher le contenu du tableau characterIds
    qDebug() << "Contenu du tableau characterIds :";
    for (int i = 0; i < 3; ++i) {
        qDebug() << "characterIds[" << i << "] =" << characterIds[i];
    }

    // Afficher le contenu du tableau enemyCharacterIds
    qDebug() << "Contenu du tableau enemyCharacterIds :";
    for (int i = 0; i < 3; ++i) {
        qDebug() << "enemyCharacterIds[" << i << "] =" << enemyCharacterIds[i];
    }
    // Mettre à jour les images des frames en fonction des valeurs du tableau characterIds
    for (int i = 0; i < 3; ++i) {
        QString frameName = QString("ally_char_%1").arg(i + 1);
        QFrame *frame = findChild<QFrame *>(frameName);
        if (frame) {
            QString imageName;
            switch (characterIds[i]) {
            case 1:
                imageName = "Ogami_preview.png";
                break;
            case 2:
                imageName = "Dio_preview.png";
                break;
            case 3:
                imageName = "Gabimaru_preview.png";
                break;
            case 4:
                imageName = "Ryo_Kaori_preview.png";
                break;
            case 5:
                imageName = "Yoh_preview.png";
                break;
            case 6:
                imageName = "Raye_preview.png";
                break;
            case 7:
                imageName = "Goku_preview.png";
                break;
            case 8:
                imageName = "Kurama_preview.png";
                break;
            case 9:
                imageName = "Milo_Preview.png";
                break;
            case 10:
                imageName = "Sasori_preview.png";
                break;
            default:
                // Si l'ID n'est pas valide, vous pouvez définir une image par défaut ou ne rien faire
                imageName = ""; // Pas d'image par défaut dans ce cas
                break;
            }
            if (!imageName.isEmpty()) {
                QString imagePath = QString(":/static/Preview/%1").arg(imageName);
                frame->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
            }
        }
    }

    // Mettre à jour les images des frames en fonction des valeurs du tableau enemyCharacterIds
    for (int i = 0; i < 3; ++i) {
        QString frameName = QString("ennemy_char_%1").arg(i + 1);
        QFrame *frame = findChild<QFrame *>(frameName);
        if (frame) {
            QString imageName;
            switch (enemyCharacterIds[i]) {
            case 1:
                imageName = "Ogami_preview.png";
                break;
            case 2:
                imageName = "Dio_preview.png";
                break;
            case 3:
                imageName = "Gabimaru_preview.png";
                break;
            case 4:
                imageName = "Ryo_Kaori_preview.png";
                break;
            case 5:
                imageName = "Yoh_preview.png";
                break;
            case 6:
                imageName = "Raye_preview.png";
                break;
            case 7:
                imageName = "Goku_preview.png";
                break;
            case 8:
                imageName = "Kurama_preview.png";
                break;
            case 9:
                imageName = "Milo_Preview.png";
                break;
            case 10:
                imageName = "Sasori_preview.png";
                break;
            default:
                // Si l'ID n'est pas valide, vous pouvez définir une image par défaut ou ne rien faire
                imageName = ""; // Pas d'image par défaut dans ce cas
                break;
            }
            if (!imageName.isEmpty()) {
                QString imagePath = QString(":/static/Preview/%1").arg(imageName);
                frame->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
            }
        }
    }
}

void Character_select::setPresetValues(const QVector<int> &presetValues) {
    // Assurez-vous que la taille de presetValues est au moins égale à 3
    if (presetValues.size() < 3) {
        qDebug() << "Erreur : La taille du vecteur de valeurs de préréglage est inférieure à 3";
        return; // Quittez la fonction si la taille est incorrecte
    }

    // Mettez à jour les valeurs des personnages dans characterIds
    for (int i = 0; i < 3; ++i) {
        characterIds[i] = presetValues[i];
    }

    std::set<int> usedIds(characterIds, characterIds + 3); // Utilisez std::set pour stocker les IDs déjà utilisés
    srand(time(nullptr)); // Initialiser le générateur de nombres aléatoires
    for (int i = 0; i < 3; ++i) {
        int randomId;
        do {
            randomId = rand() % 10 + 1; // Générer un nombre aléatoire entre 1 et 10
        } while (usedIds.count(randomId) > 0); // Vérifier si le nombre aléatoire a déjà été utilisé
        enemyCharacterIds[i] = randomId;
        usedIds.insert(randomId); // Ajouter le nombre aléatoire à l'ensemble des nombres déjà utilisés
    }
    updateFrameImages();
}




Character_select::~Character_select()
{
    delete ui;
}
