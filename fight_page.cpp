#include "fight_page.h"
#include "ui_fight_page.h"
#include "param.h"

Fight_page::Fight_page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Fight_page)
{
    ui->setupUi(this);
}

Fight_page::~Fight_page()
{
    delete ui;
}
