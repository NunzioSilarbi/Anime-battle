#include "character_select.h"
#include "ui_character_select.h"
#include "param.h"
#include "animebattle.h"
#include "presets.h"

Character_select::Character_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Character_select)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &Character_select::goBack);
    connect(ui->presets_button, &QPushButton::clicked, this, &Character_select::goPresetsWindow);
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

Character_select::~Character_select()
{
    delete ui;
}
