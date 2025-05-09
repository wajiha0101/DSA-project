#include "gameselection.h"
#include "ui_gameselection.h"
#include "sudokulogic.h"
#include "tictactoe.h"
#include "EightPuzzle.h"

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
    connect(ui->tictactoe, &QPushButton::clicked, this, &GameSelection::launchTicTacToe);
    connect(ui->easy_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleEasy);
    connect(ui->medium_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleMedium);
    connect(ui->hard_puzzle, &QPushButton::clicked, this, &GameSelection::launchPuzzleHard);

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

void GameSelection::launchTicTacToe()
{
    tictactoe *game = new tictactoe;
    connect(game, &tictactoe::goBackToMenu, this, &GameSelection::show);
    game->show();
    this->hide();
}

void GameSelection::launchPuzzleEasy()
{
    qDebug() << "Puzzle Easy clicked";
    EightPuzzle *puzzle = new EightPuzzle();
    puzzle->show();
    this->hide();
}

void GameSelection::launchPuzzleMedium()
{
    qDebug() << "Puzzle Medium clicked";
    EightPuzzle *puzzle = new EightPuzzle();
    puzzle->show();
    this->hide();
}

void GameSelection::launchPuzzleHard()
{
    qDebug() << "Puzzle Hard clicked";
    EightPuzzle *puzzle = new EightPuzzle();
    puzzle->show();
    this->hide();
}

void GameSelection::on_GameSelection_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    // Nothing implemented yet
}
