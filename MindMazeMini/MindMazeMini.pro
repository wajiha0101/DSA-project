QT += core gui widgets sql
QT += sql

CONFIG += c++17

INCLUDEPATH += $$PWD/backend
INCLUDEPATH += $$PWD/sqlite

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    gameselection.cpp \
    sudokugame.cpp \
    sudokulogic.cpp \
    tictactoe.cpp \
    EightPuzzle.cpp \
    backend/Sudoku.cpp \
    backend/Sudoku-db.cpp \
    backend/EightPuzzle-db.cpp \
    sqlite3.c

HEADERS += \
    mainwindow.h \
    gameselection.h \
    sudokugame.h \
    sudokulogic.h \
    tictactoe.h \
    EightPuzzle.h \
    backend/Sudoku.h \
    backend/Sudoku-db.h \
    backend/EightPuzzle-db.h \
    sqlite3.h

FORMS += \
    mainwindow.ui \
    gameselection.ui \
    sudokugame.ui \
    sudokulogic.ui \
    tictactoe.ui \
    EightPuzzle.ui

RESOURCES += resources.qrc
