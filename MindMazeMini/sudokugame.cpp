#include "sudokugame.h"
#include "ui_sudokugame.h"

sudokugame::sudokugame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sudokugame)
{
    ui->setupUi(this);
}

sudokugame::~sudokugame()
{
    delete ui;
}
