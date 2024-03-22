#include "animebattle.h"
#include "ui_animebattle.h"

Animebattle::Animebattle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Animebattle)
{
    ui->setupUi(this);
}

Animebattle::~Animebattle()
{
    delete ui;
}
