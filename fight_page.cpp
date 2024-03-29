#include "fight_page.h"
#include "ui_fight_page.h"
#include <QPixmap>

Fight_page::Fight_page(const QString &backgroundImagePath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fight_page)
{
    ui->setupUi(this);

    // Définir le style CSS pour l'arrière-plan du QFrame
    ui->background->setStyleSheet("QFrame#background { "
                                  "background-image: url(" + backgroundImagePath + "); "
                                                          "background-repeat: no-repeat; "
                                                          "background-position: center; "
                                                          "}");
}

Fight_page::~Fight_page()
{
    delete ui;
}
