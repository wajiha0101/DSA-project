#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class tictactoe;
}

class tictactoe : public QWidget
{
    Q_OBJECT

public:
    explicit tictactoe(bool singlePlayer = false, QWidget *parent = nullptr);
    ~tictactoe();

private:
    Ui::tictactoe *ui;
    char board[3][3];         // Game board
    char currentPlayer;       // 'X' or 'O'
    bool gameOver;            // Status flag

    void handleCellClick(int row, int col);     // Handles button click
    void updateUICell(int row, int col, char player);  // Update UI cell with player move
    bool checkWin(char player);                 // Check if player has won
    bool isDraw();
    void resetBoard();
private:
    bool isSinglePlayer = false; // added
    void makeAIMove();           // added
    bool tryMove(char player);
private slots:
    void onBackClicked();
signals:
    void goBackToMenu();

};

#endif // TICTACTOE_H
