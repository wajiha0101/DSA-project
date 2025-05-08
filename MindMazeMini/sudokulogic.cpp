#include "sudokulogic.h"
#include "ui_sudokulogic.h"
#include "Sudoku-db.h"
#include "Sudoku.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

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
            QString cellName = QString("cell_%1%2").arg(row).arg(col);
            QLineEdit *cell = findChild<QLineEdit *>(cellName);
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

bool SudokuLogic::isBoardEmpty() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if (grid[i][j] != 0)
                return false;
    return true;
}

bool SudokuLogic::isInitialBoardValid() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int num = grid[row][col];
            if (num != 0) {
                grid[row][col] = 0;
                if (!isSafe(row, col, num)) {
                    grid[row][col] = num;
                    return false;
                }
                grid[row][col] = num;
            }
        }
    }
    return true;
}

void SudokuLogic::onSolveClicked()
{
    readGridFromUI();

    if (isBoardEmpty()) {
        QMessageBox::warning(this, "Empty", "Board is empty. Please input a puzzle.");
        return;
    }

    if (!isUserInputValid()) {
        highlightInvalidCells();
        QMessageBox::warning(this, "Invalid Input", "Some values are incorrect or violate Sudoku rules.\nThe system will attempt to solve anyway.");
        // ⚠️ No return here — we still proceed to solve
    }

    if (solvesudoku()) {
        updateGridUI();
        QMessageBox::information(this, "Solved", "Sudoku solved successfully.");
    } else {
        QMessageBox::warning(this, "Unsolvable", "This Sudoku puzzle cannot be solved.");
    }
}

void SudokuLogic::highlightInvalidCells() {
    // First, reset all borders
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QLineEdit *cell = findChild<QLineEdit*>(QString("cell_%1%2").arg(row).arg(col));
            if (cell) {
                cell->setStyleSheet("");  // Reset
            }
        }
    }

    // Now highlight conflicting cells
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int num = grid[row][col];
            if (num == 0) continue;

            grid[row][col] = 0;
            if (!isSafe(row, col, num)) {
                QLineEdit *cell = findChild<QLineEdit*>(QString("cell_%1%2").arg(row).arg(col));
                if (cell) {
                    cell->setStyleSheet("border: 2px solid red;");
                }
            }
            grid[row][col] = num;
        }
    }
}


bool SudokuLogic::isUserInputValid()
{
    int tempGrid[9][9];

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

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            int num = tempGrid[row][col];
            if (num == 0) continue;

            tempGrid[row][col] = 0;

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

            tempGrid[row][col] = num;
        }
    }

    return true;
}

void SudokuLogic::onBackClicked()
{
    emit goBackToMenu();
    this->close();
}
