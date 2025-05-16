#include "mainwindow.h"
#include <QApplication>
#include "EightPuzzle-db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//     SudokuDB db("sudoku.db");

//     int easy[9][9] = {
//         {5,3,0, 0,7,0, 0,0,0},
//         {6,0,0, 1,9,5, 0,0,0},
//         {0,9,8, 0,0,0, 0,6,0},
//         {8,0,0, 0,6,0, 0,0,3},
//         {4,0,0, 8,0,3, 0,0,1},
//         {7,0,0, 0,2,0, 0,0,6},
//         {0,6,0, 0,0,0, 2,8,0},
//         {0,0,0, 4,1,9, 0,0,5},
//         {0,0,0, 0,8,0, 0,7,9}
//     };

//     std::string data = db.boardToString(easy);
//     db.savePuzzle("easy", data);  // Save it with the name "easy"

//     int hard[9][9] = {
//         {0,0,0, 0,0,0, 0,1,2},
//         {0,0,0, 0,3,5, 0,0,0},
//         {0,0,0, 7,0,0, 0,0,0},
//         {0,0,0, 6,0,0, 0,0,3},
//         {0,0,0, 0,9,0, 0,0,0},
//         {8,0,0, 0,0,4, 0,0,0},
//         {0,0,0, 0,0,9, 0,0,0},
//         {0,0,0, 4,1,0, 0,0,0},
//         {2,7,0, 0,0,0, 0,0,0}
//     };

//     std::string hardData = db.boardToString(hard);
//     db.savePuzzle("hard", hardData);  // Save as "hard"


//     return a.exec();

    // EightPuzzleDB db;

    // std::vector<int> easy = {
    //     1, 2, 3,
    //     4, 5, 6,
    //     7, 8, 0
    // };

    // std::vector<int> medium = {
    //     1, 2, 3,
    //     4, 0, 6,
    //     7, 5, 8
    // };

    // std::vector<int> hard = {
    //     8, 6, 7,
    //     2, 5, 4,
    //     3, 0, 1
    // };

    // db.savePuzzle("easy", { easy });
    // db.savePuzzle("medium", { medium });
    // db.savePuzzle("hard", { hard });

    return a.exec();
}
