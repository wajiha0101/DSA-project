#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QString>
#include "EightPuzzle-db.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class EightPuzzle;
}
QT_END_NAMESPACE

class EightPuzzle : public QWidget {
    Q_OBJECT

public:
    explicit EightPuzzle(QWidget *parent = nullptr);
    ~EightPuzzle();

private slots:
    void handleTileClicked(int index);
    void resetPuzzle();
    void onBackClicked();

private:
    Ui::EightPuzzle *ui;
    QVector<QPushButton*> buttons;
    QVector<int> puzzleState;
    EightPuzzleDB db;

    void loadPuzzleFromDB(const std::string &difficulty);
    void updateUI();
    bool canSwap(int index1, int index2);
    void swapTiles(int index1, int index2);
};
