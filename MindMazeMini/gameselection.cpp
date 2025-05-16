#include "gameselection.h"
#include "ui_gameselection.h"
#include "sudokulogic.h"
#include "tictactoe.h"
#include "EightPuzzle.h"
#include <QCoreApplication>

GameSelection::GameSelection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameSelection)
{
    ui->setupUi(this);

    QPixmap sudoku(":/images/sudoku.png");
    QPixmap tictactoe(":/images/tictactoe.png");
    QPixmap puzzle(":/images/puzzle.png");

    qDebug() << "Sudoku loaded?" << !sudoku.isNull();
    qDebug() << "TicTacToe loaded?" << !tictactoe.isNull();
    qDebug() << "Puzzle loaded?" << !puzzle.isNull();

    QSize imageSize(200, 200);  // adjust as needed

    if (!sudoku.isNull())
        ui->sudoku->setPixmap(sudoku.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    if (!tictactoe.isNull())
        ui->Tictactoe->setPixmap(tictactoe.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    if (!puzzle.isNull())
        ui->eightpuzzle->setPixmap(puzzle.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    connect(ui->easy_sudoku, &QPushButton::clicked, this, &GameSelection::launchSudokuEasy);
    connect(ui->hard_sudoku, &QPushButton::clicked, this, &GameSelection::launchSudokuHard);
    connect(ui->tictactoe_single, &QPushButton::clicked, this, &GameSelection::launchTicTacToeSingle);
    connect(ui->tictactoe, &QPushButton::clicked, this, &GameSelection::launchTicTacToeDouble);
    connect(ui->easy_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleEasy);
    connect(ui->medium_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleMedium);
    connect(ui->hard_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleHard);
    connect(ui->quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit);

    qDebug() << "GameSelection UI loaded successfully!";
}

GameSelection::~GameSelection()
{
    delete ui;
}

void GameSelection::launchSudokuEasy()
{
    SudokuLogic *game = new SudokuLogic("easy");
    connect(game, &SudokuLogic::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}

void GameSelection::launchSudokuHard()
{
    SudokuLogic *game = new SudokuLogic("hard");
    connect(game, &SudokuLogic::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}

void GameSelection::launchTicTacToeSingle() {
    tictactoe *game = new tictactoe(true); // AI mode
    connect(game, &tictactoe::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}
void GameSelection::launchTicTacToe() {
    tictactoe *game = new tictactoe();
    connect(game, &tictactoe::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}

void GameSelection::launchTicTacToeDouble() {
    tictactoe *game = new tictactoe(false); // 2-player mode
    connect(game, &tictactoe::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}


void GameSelection::launchPuzzleEasy() {
    EightPuzzle *puzzle = new EightPuzzle("easy");
    puzzle->show();
    this->hide();
}

void GameSelection::launchPuzzleMedium() {
    EightPuzzle *puzzle = new EightPuzzle("medium");
    puzzle->show();
    this->hide();
}

void GameSelection::launchPuzzleHard() {
    EightPuzzle *puzzle = new EightPuzzle("hard");
    puzzle->show();
    this->hide();
}


void GameSelection::on_GameSelection_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    // Nothing implemented yet
}
