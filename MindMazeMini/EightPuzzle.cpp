#include "EightPuzzle.h"
#include "ui_EightPuzzle.h"
#include "gameselection.h"
#include <QDebug>
#include <QMessageBox>
#include <vector>

EightPuzzle::EightPuzzle(const std::string &difficulty, QWidget *parent)
    : QWidget(parent), ui(new Ui::EightPuzzle)
{
    ui->setupUi(this);
    qDebug() << "EightPuzzle created with difficulty:" << QString::fromStdString(difficulty);

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
    connect(ui->ai_solve, &QPushButton::clicked, this, &EightPuzzle::solveWithAI);

    loadPuzzleFromDB(difficulty);
    updateUI();

    QString status = "Difficulty: " + QString::fromStdString(difficulty);
    ui->status->setText(status);

    currentDifficulty = difficulty;
    ui->ai_output->setVisible(false);

}



EightPuzzle::~EightPuzzle()
{
    delete ui;
}

void EightPuzzle::loadPuzzleFromDB(const std::string &difficulty)
{
    puzzleState.clear();

    if (difficulty == "easy") {
        puzzleState = { 1, 2, 3, 4, 0, 6, 7, 5, 8 };
    }
    else if (difficulty == "medium") {
        puzzleState = { 1, 2, 3, 0, 4, 6, 7, 5, 8 };
    }
    else if (difficulty == "hard") {
        puzzleState = { 8, 6, 7, 2, 5, 4, 3, 0, 1 };
    }
    else {
        puzzleState = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    }

    if (puzzleState.size() != 9) {
        QMessageBox::warning(this, "Error", "Puzzle data incomplete.");
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
    loadPuzzleFromDB(currentDifficulty);
    updateUI();
    ui->status->setText("Puzzle reset.");
    ui->ai_output->clear();
    ui->ai_output->setVisible(false);
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

void EightPuzzle::solveWithAI()
{
    // Convert QVector to 2D board
    std::vector<std::vector<int>> board(3, std::vector<int>(3));
    for (int i = 0; i < 9; ++i) {
        board[i / 3][i % 3] = puzzleState[i];
    }

    // Basic hardcoded logic to simulate AI (replace with actual solver later)
    QString moves;
    if (board == std::vector<std::vector<int>>{{1,2,3},{4,5,6},{7,8,0}}) {
        moves = "Already Solved!";
    } else if (board == std::vector<std::vector<int>>{{1,2,3},{4,0,6},{7,5,8}}) {
        moves = "D R";
    } else if (board == std::vector<std::vector<int>>{{8,6,7},{2,5,4},{3,0,1}}) {
        moves = "L U R R D";  // Fake path, replace later
    } else {
        moves = "No solution known for this configuration.";
    }

    // Display on label
    ui->ai_output->setText("AI Moves: " + moves);
    ui->ai_output->setVisible(true);
}

