#include "character_select.h"
#include "ui_character_select.h"
#include "param.h"
#include "animebattle.h"

Character_select::Character_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Character_select)
{
    ui->setupUi(this);
}

Character_select::~Character_select()
{
    delete ui;
}
