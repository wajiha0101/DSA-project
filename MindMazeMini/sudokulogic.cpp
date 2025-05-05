#include "sudokulogic.h"
#include "ui_sudokulogic.h"
#include "Sudoku-db.h"
#include "Sudoku.h"
#include <QMessageBox>
#include <QString>

SudokuLogic::SudokuLogic(QString difficulty, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SudokuLogic)
{
    ui->setupUi(this);
    db = new SudokuDB("sudoku.db");

    // Load puzzle by difficulty
    loadPuzzle(difficulty.toStdString());

    connect(ui->solveButton, &QPushButton::clicked, this, &SudokuLogic::onSolveClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SudokuLogic::onBackClicked);
}

SudokuLogic::~SudokuLogic()
{
    delete ui;
    delete db;
}

void SudokuLogic::loadPuzzle(const std::string &puzzleName)
{
    QString boardString = QString::fromStdString(db->loadPuzzle(puzzleName));
    if (boardString.isEmpty()) {
        QMessageBox::warning(this, "Error", "Puzzle not found in DB");
        return;
    }

    db->stringToBoard(boardString.toStdString(), grid);
    updateGridUI();
}

void SudokuLogic::updateGridUI()
{
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
             QLineEdit *cell = findChild<QLineEdit*>(QString("cell_%1%2").arg(row).arg(col));
            if (cell) {
                if (grid[row][col] != 0)
                    cell->setText(QString::number(grid[row][col]));
                else
                    cell->clear();
            }
        }
    }
}

void SudokuLogic::readGridFromUI()
{
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QLineEdit *cell = findChild<QLineEdit*>(QString("cell_%1%2").arg(row).arg(col));
            if (cell) {
                QString text = cell->text();
                grid[row][col] = text.isEmpty() ? 0 : text.toInt();
                qDebug() << "Reading cell_" << row << col << " = " << grid[row][col];
            } else {
                qDebug() << "Could not find cell_" << row << col;
            }
        }
    }
}


void SudokuLogic::onSolveClicked()
{
    readGridFromUI();

    // Check if the board is completely empty
    bool isEmpty = true;
    for (int row = 0; row < 9 && isEmpty; ++row) {
        for (int col = 0; col < 9 && isEmpty; ++col) {
            if (grid[row][col] != 0)
                isEmpty = false;
        }
    }

    if (isEmpty) {
        QMessageBox::warning(this, "Empty Board", "Please fill in some numbers before solving.");
        return;
    }

    // Validate user input before attempting to solve
    if (!isUserInputValid()) {
        QMessageBox::warning(this, "Invalid Input", "Your input violates Sudoku rules.");
        return;
    }

    // Attempt to solve
    if (solvesudoku()) {
        updateGridUI();
        QMessageBox::information(this, "Solved", "Sudoku solved successfully.");
    } else {
        QMessageBox::warning(this, "Unsolvable", "No valid solution found.");
    }
}



bool SudokuLogic::isUserInputValid()
{
    // Temporary check grid
    int tempGrid[9][9];

    // Copy user input into tempGrid
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            QLineEdit *cell = findChild<QLineEdit*>(QString("cell_%1%2").arg(row).arg(col));
            if (!cell) return false;

            QString text = cell->text().trimmed();
            int val = text.isEmpty() ? 0 : text.toInt();

            if (val < 0 || val > 9) return false;
            tempGrid[row][col] = val;
        }
    }
    // Check each filled cell does not violate Sudoku rules
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            int num = tempGrid[row][col];
            if (num == 0) continue;

            tempGrid[row][col] = 0; // Temporarily clear to validate

            // Check row, col, and 3x3 subgrid
            for (int i = 0; i < 9; ++i)
            {
                if (tempGrid[row][i] == num || tempGrid[i][col] == num)
                    return false;
            }

            int startRow = row - row % 3;
            int startCol = col - col % 3;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (tempGrid[startRow + i][startCol + j] == num)
                        return false;
                }
            }

            tempGrid[row][col] = num; // Restore
        }
    }

    return true;
}

void SudokuLogic::onBackClicked()
{
    emit goBackToMenu();
    this->close();
}
