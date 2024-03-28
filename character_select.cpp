#include "character_select.h"
#include "ui_character_select.h"
#include "param.h"
#include "animebattle.h"

Character_select::Character_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Character_select)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &Character_select::goBack);
}

void Character_select::goBack()
{
    Animebattle *animeBattle = new Animebattle();
    animeBattle->show();
    this->close();
}

Character_select::~Character_select()
{
    delete ui;
}
