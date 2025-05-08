#include "EightPuzzle.h"
#include "ui_EightPuzzle.h"
#include "gameselection.h"
#include "EightPuzzle-db.h"

#include <QDebug>
#include <QMessageBox>

EightPuzzle::EightPuzzle(QWidget *parent)
    : QWidget(parent), ui(new Ui::EightPuzzle), db()
{
    ui->setupUi(this);

    // Connect all 9 buttons
    buttons = {
        ui->tile_00, ui->tile_01, ui->tile_02,
        ui->tile_10, ui->tile_11, ui->tile_12,
        ui->tile_20, ui->tile_21, ui->tile_22
    };

    for (int i = 0; i < 9; ++i) {
        connect(buttons[i], &QPushButton::clicked, this, [=]() {
            handleTileClicked(i);
        });
    }

    connect(ui->reset, &QPushButton::clicked, this, &EightPuzzle::resetPuzzle);
    connect(ui->back, &QPushButton::clicked, this, &EightPuzzle::onBackClicked);

    // Initial state
    loadPuzzleFromDB("easy");
    updateUI();
}

EightPuzzle::~EightPuzzle()
{
    delete ui;
}

void EightPuzzle::loadPuzzleFromDB(const std::string &difficulty)
{
    auto temp = db.loadPuzzle(difficulty);
    puzzleState = QVector<int>(temp.begin(), temp.end());

    if (puzzleState.size() != 9) {
        QMessageBox::warning(this, "Error", "Failed to load puzzle from DB.");
    }
}

void EightPuzzle::updateUI()
{
    for (int i = 0; i < 9; ++i) {
        if (i < buttons.size()) {
            if (puzzleState[i] == 0)
                buttons[i]->setText("");
            else
                buttons[i]->setText(QString::number(puzzleState[i]));
        }
    }
}

void EightPuzzle::resetPuzzle()
{
    loadPuzzleFromDB("easy");
    updateUI();
    ui->status->setText("Puzzle reset.");
}

void EightPuzzle::onBackClicked()
{
    this->close();
    GameSelection *menu = new GameSelection();
    menu->show();
}

void EightPuzzle::handleTileClicked(int index)
{
    int zeroIndex = puzzleState.indexOf(0);

    int row = index / 3;
    int col = index % 3;
    int zeroRow = zeroIndex / 3;
    int zeroCol = zeroIndex % 3;

    if ((abs(row - zeroRow) == 1 && col == zeroCol) ||
        (abs(col - zeroCol) == 1 && row == zeroRow)) {
        std::swap(puzzleState[index], puzzleState[zeroIndex]);
        updateUI();
    }
}
