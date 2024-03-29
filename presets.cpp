#include "presets.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLabel>
#include "character_select.h" // Inclure le fichier d'en-tête de Character_select

Presets::Presets(QWidget *parent) : QWidget(parent), ui(new Ui::Presets) {
    ui->setupUi(this);

    // Lire les fichiers txt et stocker les valeurs dans des tableaux
    QVector<QVector<int>> presets;
    presets.resize(6);
    for (int i = 0; i < 6; ++i) {
        presets[i] = readPresetFile(QString(":/data/preset%1.txt").arg(i + 1));
    }

    // Parcourir les tableaux et afficher les images correspondantes dans les QFrames
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            QFrame *frame = findChild<QFrame *>(QString("preset%1_%2").arg(i + 1).arg(j + 1));
            if (frame) {
                int characterId = presets[i][j];
                QString imageName;
                switch (characterId) {
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
    connect(ui->back_button, &QPushButton::clicked, this, &Presets::goBack);
}

QVector<int> Presets::readPresetFile(const QString &filename) {
    QVector<int> preset;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file: " << file.errorString();
        return preset;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        int value = line.toInt(&ok);
        if (ok) {
            preset.append(value);
        } else {
            qDebug() << "Error converting line to integer: " << line;
        }
    }

    file.close();

    // Imprimer le contenu du tableau dans la console
    qDebug() << "Contenu du tableau preset pour le fichier" << filename << ":";
    for (int i = 0; i < preset.size(); ++i) {
        qDebug() << preset[i];
    }

    return preset;
}


void Presets::goBack() {
    Character_select *character_selected = new Character_select();
    character_selected->show();
    this->close();
}


Presets::~Presets() {
    delete ui;
}
