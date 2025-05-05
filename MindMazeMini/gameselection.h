#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QWidget>

namespace Ui {
class GameSelection;
}

class GameSelection : public QWidget
{
    Q_OBJECT

public:
    explicit GameSelection(QWidget *parent = nullptr);
    ~GameSelection();

private slots:
    void on_GameSelection_customContextMenuRequested(const QPoint &pos);

    void launchSudokuEasy();
    void launchSudokuHard();

    void launchTicTacToe();

    void launchPuzzleEasy();
    void launchPuzzleMedium();
    void launchPuzzleHard();


private:
    Ui::GameSelection *ui;
};

#endif // GAMESELECTION_H
