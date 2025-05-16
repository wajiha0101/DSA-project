#include "tictactoe.h"
#include "ui_tictactoe.h"
#include<QTimer>
tictactoe::tictactoe(bool singlePlayer, QWidget *parent)
    : QWidget(parent), ui(new Ui::tictactoe), isSinglePlayer(singlePlayer)
{
    ui->setupUi(this);

    currentPlayer = 'X';
    gameOver = false;
    connect(ui->resetButton, &QPushButton::clicked, this, &tictactoe::resetBoard);
    connect(ui->back, &QPushButton::clicked, this, &tictactoe::onBackClicked);

    // Initialize board and connect buttons
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = ' ';
            QString btnName = QString("cell_%1%2").arg(row).arg(col);
            QPushButton *button = findChild<QPushButton *>(btnName);
            if (button) {
                connect(button, &QPushButton::clicked, [=]() {
                    handleCellClick(row, col);
                });
            }
        }
    }
}

tictactoe::~tictactoe()
{
    delete ui;
}

void tictactoe::handleCellClick(int row, int col)
{
    if (gameOver || board[row][col] != ' ')
        return;

    board[row][col] = currentPlayer;
    updateUICell(row, col, currentPlayer);

    if (checkWin(currentPlayer)) {
        ui->status->setText(QString("%1 wins!").arg(currentPlayer));
        QMessageBox::information(this, "Game Over", ui->status->text());
        gameOver = true;
    } else if (isDraw()) {
        ui->status->setText("It's a draw!");
        QMessageBox::information(this, "Game Over", "It's a draw!");
        gameOver = true;
    } else {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        ui->status->setText(QString("Turn: %1").arg(currentPlayer));

        if (isSinglePlayer && currentPlayer == 'O') {
            QTimer::singleShot(400, this, &tictactoe::makeAIMove); // delay for realism
        }
    }
}

void tictactoe::resetBoard()
{
    currentPlayer = 'X';
    gameOver = false;
    ui->status->setText("Turn: X");

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = ' ';
            QString btnName = QString("cell_%1%2").arg(row).arg(col);
            QPushButton *button = findChild<QPushButton *>(btnName);
            if (button) {
                button->setText("");
                button->setStyleSheet("background-color: pink; font-size: 18px;");
                button->setEnabled(true);  // Optional: if you disabled after win
            }
        }
    }
}


void tictactoe::updateUICell(int row, int col, char player) {
    QString buttonName = QString("cell_%1%2").arg(row).arg(col);  // e.g., cell_00
    QPushButton *btn = findChild<QPushButton*>(buttonName);
    if (btn) {
        btn->setText(QString(player));  // Set 'X' or 'O'

        // Optional: Improve appearance
        if (player == 'X')
            btn->setStyleSheet("color: blue; font-size: 24px; font-weight: bold;");
        else if (player == 'O')
            btn->setStyleSheet("color: red; font-size: 24px; font-weight: bold;");
    }
}

// void tictactoe::updateUICell(int row, int col, char player)
// {
//     QString btnName = QString("cell_%1%2").arg(row).arg(col);
//     QPushButton *button = findChild<QPushButton *>(btnName);
//     if (button) {
//         button->setText(QString(player));
//         button->setEnabled(false);
//     }
// }

bool tictactoe::checkWin(char player)
{
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

void tictactoe::onBackClicked() {
    emit goBackToMenu();  // Notify main window to switch UI
    this->close();        // Close current game window
}


bool tictactoe::isDraw()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void tictactoe::makeAIMove() {
    // 1. Try to win
    if (tryMove('O')) return;

    // 2. Try to block X
    if (tryMove('X')) return;

    // 3. Else: pick first empty
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                updateUICell(row, col, 'O');
                currentPlayer = 'X';
                return;
            }
}

// Helper to simulate win/block
bool tictactoe::tryMove(char player) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                board[row][col] = player;
                if (checkWin(player)) {
                    board[row][col] = 'O'; // Place AI move here
                    updateUICell(row, col, 'O');
                    currentPlayer = 'X';
                    return true;
                }
                board[row][col] = ' '; // Undo simulation
            }
        }
    }
    return false;
}

