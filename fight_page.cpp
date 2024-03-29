#include "fight_page.h"
#include "ui_fight_page.h"
#include <QPixmap>

Fight_page::Fight_page(const QString &backgroundImagePath, int characterIds[], int enemyCharacterIds[], QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fight_page)
{
    ui->setupUi(this);

    ui->background->setStyleSheet("QFrame#background { "
                                  "background-image: url(" + backgroundImagePath + "); "
                                                          "background-repeat: no-repeat; "
                                                          "background-position: center; "
                                                          "}");

    QPushButton* allyButtons[3] = {ui->perso_1_ally_2, ui->perso_2_ally_2, ui->perso_3_ally_2};

    for (int i = 0; i < 3; ++i) {
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
            imageName = "";
            break;
        }
        if (!imageName.isEmpty()) {
            QString imagePath = QString(":/static/Preview/%1").arg(imageName);
            allyButtons[i]->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
        }
    }

    QPushButton* ennemyButtons[3] = {ui->perso_1_ennemy_2, ui->perso_2_ennemy_2, ui->perso_3_ennemy_2};

    for (int i = 0; i < 3; ++i) {
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
            imageName = "";
            break;
        }
        if (!imageName.isEmpty()) {
            QString imagePath = QString(":/static/Preview/%1").arg(imageName);
            ennemyButtons[i]->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
        }
    }


    QString imageNameEnnemy;
    switch (enemyCharacterIds[0]) {
    case 1:
        imageNameEnnemy = "Ogami.png";
        break;
    case 2:
        imageNameEnnemy = "Dio_TheWorld.png";
        break;
    case 3:
        imageNameEnnemy = "Gabimaru.png";
        break;
    case 4:
        imageNameEnnemy = "Ryo_Kaori.png";
        break;
    case 5:
        imageNameEnnemy = "Yoh.png";
        break;
    case 6:
        imageNameEnnemy = "Raye.png";
        break;
    case 7:
        imageNameEnnemy = "Goku.png";
        break;
    case 8:
        imageNameEnnemy = "Kurama.png";
        break;
    case 9:
        imageNameEnnemy = "Milo.png";
        break;
    case 10:
        imageNameEnnemy = "Sasori.png";
        break;
    default:
        imageNameEnnemy = "";
        break;
    }
    if (!imageNameEnnemy.isEmpty()) {
        QString imagePath = QString(":/static/Char/%1").arg(imageNameEnnemy);
        ui->char_select_ennemy_2->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
    }

    QString imageNameAlly;
    switch (characterIds[0]) {
    case 1:
        imageNameAlly = "Ogami.png";
        break;
    case 2:
        imageNameAlly = "Dio_TheWorld.png";
        break;
    case 3:
        imageNameAlly = "Gabimaru.png";
        break;
    case 4:
        imageNameAlly = "Ryo_Kaori.png";
        break;
    case 5:
        imageNameAlly = "Yoh.png";
        break;
    case 6:
        imageNameAlly = "Raye.png";
        break;
    case 7:
        imageNameAlly = "Goku.png";
        break;
    case 8:
        imageNameAlly = "Kurama.png";
        break;
    case 9:
        imageNameAlly = "Milo.png";
        break;
    case 10:
        imageNameAlly = "Sasori.png";
        break;
    default:
        imageNameAlly = "";
        break;
    }
    if (!imageNameAlly.isEmpty()) {
        QString imagePath = QString(":/static/Char/%1").arg(imageNameAlly);
        ui->char_select_ally_2->setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center; background-origin: content;").arg(imagePath));
    }
}

Fight_page::~Fight_page()
{
    delete ui;
}


