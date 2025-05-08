#include "gameselection.h"
#include "ui_gameselection.h"
#include "sudokugame.h"
#include "sudokulogic.h"
#include "tictactoe.h"
#include "eightpuzzlewidget.h"



#include <QDebug>


GameSelection::GameSelection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameSelection)
{
    ui->setupUi(this);

    QPixmap sudoku(":/images/sudoku.png");
    QPixmap tictactoe(":/images/tictactoe.png");
    QPixmap puzzle(":/images/puzzle.png");

    // Debug lines
    qDebug() << "Sudoku loaded?" << !sudoku.isNull();
    qDebug() << "TicTacToe loaded?" << !tictactoe.isNull();
    qDebug() << "Puzzle loaded?" << !puzzle.isNull();

    // Scale them to fit inside a reasonable size (e.g. 200x200)
    QSize imageSize(200, 200);  // Adjust as needed for your layout

    if (!sudoku.isNull())
        ui->sudoku->setPixmap(sudoku.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    if (!tictactoe.isNull())
        ui->Tictactoe->setPixmap(tictactoe.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    if (!puzzle.isNull())
        ui->eightpuzzle->setPixmap(puzzle.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //connect with my vs
    connect(ui->easy_sudoku, &QPushButton::clicked, this, &GameSelection::launchSudokuEasy);
    connect(ui->hard_sudoku, &QPushButton::clicked, this, &GameSelection::launchSudokuHard);

    connect(ui->tictactoe, &QPushButton::clicked, this, &GameSelection::launchTicTacToe);

    connect(ui->easy_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleEasy);
    connect(ui->medium_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleMedium);
    connect(ui->hard_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleHard);

    qDebug() << "GameSelection UI loaded successfully!";
}


void GameSelection::launchSudokuEasy() {
    SudokuLogic *game = new SudokuLogic("easy");
    connect(game, &SudokuLogic::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}

void GameSelection::launchSudokuHard() {
    SudokuLogic *game = new SudokuLogic("hard");
    connect(game, &SudokuLogic::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();

}

void GameSelection::launchTicTacToe() {
    // After creating TicTacToe instance
    tictactoe *game = new tictactoe;
    connect(game, &tictactoe::goBackToMenu, this, &GameSelection::show);  // Show menu again
    game->show();
    this->hide(); // Hide GameSelection until user clicks "Back"

}


void GameSelection::launchPuzzleEasy() {
    qDebug() << "Puzzle Easy clicked";
    EightPuzzleWidget *puzzle = new EightPuzzleWidget();
    puzzle->show();
    this->hide();
}


void GameSelection::launchPuzzleMedium() {
    qDebug() << "Puzzle Medium clicked";
    EightPuzzleWidget *puzzle = new EightPuzzleWidget();
    puzzle->show();
    this->hide();
}

void GameSelection::launchPuzzleHard() {
    qDebug() << "Puzzle Hard clicked";
    EightPuzzleWidget *puzzle = new EightPuzzleWidget();
    puzzle->show();
    this->hide();
}


enum class Difficulty { Easy, Medium, Hard };


GameSelection::~GameSelection()
{
    delete ui;
}

void GameSelection::on_GameSelection_customContextMenuRequested(const QPoint &pos)
{

}

