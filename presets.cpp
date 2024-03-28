#include "presets.h"
#include "ui_presets.h"
#include "character_select.h"

Presets::Presets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Presets)
{
    ui->setupUi(this);

    connect(ui->back_button, &QPushButton::clicked, this, &Presets::goBack);
}

void Presets::goBack()
{
    Character_select *character_selected = new Character_select();
    character_selected->show();
    this->close();
}


Presets::~Presets()
{
    delete ui;
}
