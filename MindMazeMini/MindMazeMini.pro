QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    gameselection.cpp \
    sudokugame.cpp \
    backend/Sudoku.cpp \
    backend/Sudoku-db.cpp \
    sqlite3.c \
    sudokulogic.cpp


HEADERS += \
    gameselection.h \
    mainwindow.h \
    sudokugame.h \
    backend/Sudoku.h \
    backend/Sudoku-db.h \
    sqlite3.h \
    sudokulogic.h

FORMS += \
    gameselection.ui \
    mainwindow.ui \
    sudokugame.ui \
    sudokulogic.ui

INCLUDEPATH += $$PWD/backend
RESOURCES += resources.qrc

INCLUDEPATH += $$PWD/sqlite

