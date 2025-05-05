#include "mainwindow.h"
#include "Sudoku-db.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // SudokuDB db("sudoku.db");

    // int easy[9][9] = {
    //     {5,3,0, 0,7,0, 0,0,0},
    //     {6,0,0, 1,9,5, 0,0,0},
    //     {0,9,8, 0,0,0, 0,6,0},
    //     {8,0,0, 0,6,0, 0,0,3},
    //     {4,0,0, 8,0,3, 0,0,1},
    //     {7,0,0, 0,2,0, 0,0,6},
    //     {0,6,0, 0,0,0, 2,8,0},
    //     {0,0,0, 4,1,9, 0,0,5},
    //     {0,0,0, 0,8,0, 0,7,9}
    // };

    // std::string data = db.boardToString(easy);
    // db.savePuzzle("easy", data);  // Save it with the name "easy"

    // int hard[9][9] = {
    //     {0,0,0, 0,0,0, 0,1,2},
    //     {0,0,0, 0,3,5, 0,0,0},
    //     {0,0,0, 7,0,0, 0,0,0},
    //     {0,0,0, 6,0,0, 0,0,3},
    //     {0,0,0, 0,9,0, 0,0,0},
    //     {8,0,0, 0,0,4, 0,0,0},
    //     {0,0,0, 0,0,9, 0,0,0},
    //     {0,0,0, 4,1,0, 0,0,0},
    //     {2,7,0, 0,0,0, 0,0,0}
    // };

    // std::string hardData = db.boardToString(hard);
    // db.savePuzzle("hard", hardData);  // Save as "hard"


    return a.exec();
}
