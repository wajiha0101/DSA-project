#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include "Sudoku-db.h"
#include "backend/Sudoku-db.h"

namespace Ui {
class SudokuLogic;
}

class SudokuLogic : public QWidget
{
    Q_OBJECT

public:
    explicit SudokuLogic(QString difficulty, QWidget *parent = nullptr);
    ~SudokuLogic();

private slots:
    void onSolveClicked();
    void onBackClicked();

private:
    Ui::SudokuLogic *ui;
    SudokuDB* db;
    int grid[9][9];  // Sudoku grid

    void loadPuzzle(const std::string &puzzleName);
    void updateGridUI();
    void readGridFromUI();
    bool isUserInputValid();
    bool isBoardEmpty();
    bool isInitialBoardValid();
    void highlightInvalidCells();
    bool isSafe(int grid[9][9], int row, int col, int num); // Added declaration

signals:
    void goBackToMenu();
};
