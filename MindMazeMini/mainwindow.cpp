#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameselection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
connect(ui->PLAYButton, &QPushButton::clicked, this, &MainWindow::openGameSelection);

    ui->PLAYButton->setFlat(false);
    ui->PLAYButton->setStyleSheet(
        "QPushButton {"
        " background-color: #6A0DAD;"       // Light purple
        " color: white;"                    // White text
        " font-weight: bold;"
        " padding: 6px;"
        " border-radius: 6px;"
        " border: 2px solid #9B30FF;"       // Light orchid border
        " }"
        "QPushButton:hover {"
        " background-color: #7B1FA2;"       // Hover violet
        " }"
        );

}

void MainWindow::openGameSelection()
{
    GameSelection *gameSelection = new GameSelection();
    gameSelection->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
