#include "presets.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLabel>
#include "character_select.h"

Presets::Presets(QWidget *parent) : QWidget(parent), ui(new Ui::Presets) {
    ui->setupUi(this);

    QVector<QVector<int>> presets;
    presets.resize(6);
    for (int i = 0; i < 6; ++i) {
        presets[i] = readPresetFile(QString(":/data/preset%1.txt").arg(i + 1));
    }

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
                    imageName = "";
                    break;
                }
                if (!imageName.isEmpty()) {
                    QString imagePath = QString(":/static/Preview/%1").arg(imageName);
                    frame->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
                }
            }
        }
    }
    connect(ui->preset_1, &QPushButton::clicked, this, &Presets::loadPreset1);
    connect(ui->preset_2, &QPushButton::clicked, this, &Presets::loadPreset2);
    connect(ui->preset_3, &QPushButton::clicked, this, &Presets::loadPreset3);
    connect(ui->preset_4, &QPushButton::clicked, this, &Presets::loadPreset4);
    connect(ui->preset_5, &QPushButton::clicked, this, &Presets::loadPreset5);
    connect(ui->preset_6, &QPushButton::clicked, this, &Presets::loadPreset6);

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

    qDebug() << "Contenu du tableau preset pour le fichier" << filename << ":";
    for (int i = 0; i < preset.size(); ++i) {
        qDebug() << preset[i];
    }

    return preset;
}

void Presets::loadPreset1() {
    QVector<int> presetValues = readPresetFile(":/data/preset1.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::loadPreset2() {
    QVector<int> presetValues = readPresetFile(":/data/preset2.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::loadPreset3() {
    QVector<int> presetValues = readPresetFile(":/data/preset3.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::loadPreset4() {
    QVector<int> presetValues = readPresetFile(":/data/preset4.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::loadPreset5() {
    QVector<int> presetValues = readPresetFile(":/data/preset5.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::loadPreset6() {
    QVector<int> presetValues = readPresetFile(":/data/preset6.txt");
    openCharacterSelectWithPreset(presetValues);
}

void Presets::openCharacterSelectWithPreset(const QVector<int> &presetValues) {
    Character_select *characterSelect = new Character_select();
    characterSelect->setPresetValues(presetValues);
    characterSelect->show();
    this->close();
}

void Presets::goBack() {
    Character_select *character_selected = new Character_select();
    character_selected->show();
    this->close();
}


Presets::~Presets() {
    delete ui;
}
