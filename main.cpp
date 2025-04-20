#include<iostream>
#include "sqlite3.h"
#include <iomanip>
#include"Suduko.h"
//
//using namespace std;
//
//int main() {
//    string inputFile, outputFile;
//
//    cout << "Enter input file name (e.g., sudoku_input.txt): ";
//    cin >> inputFile;
//
//    if (!loadfromfile(inputFile)) {
//        cout << "Exiting program...\n";
//        return 1;
//    }
//
//    cout << "\nInitial Sudoku Board:\n";
//    printboard();
//
//    if (solvesudoku()) {
//        cout << "\nSolved Sudoku Board:\n";
//        printboard();
//
//        cout << "\nEnter output file name to save solution (e.g., sudoku_output.txt): ";
//        cin >> outputFile;
//
//        if (saveToFile(outputFile))
//            cout << "Solved Sudoku saved to " << outputFile << endl;
//        else
//            cout << "Failed to save the board.\n";
//
//    }
//    else {
//        cout << "No solution exists for this board.\n";
//    }
//
//    return 0;
//}
//




sqlite3* DB;

void createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS Students(ID INT, Name TEXT);";
    char* messageError;
    int exit = sqlite3_exec(DB, sql, NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cout << "? Error creating table: " << messageError << std::endl;
        sqlite3_free(messageError);
    }
    else {
        std::cout << "? Table created successfully!" << std::endl;
    }
}

void insertData() {
    const char* sql = "INSERT INTO Students VALUES(1, 'Alice');";
    char* messageError;
    int exit = sqlite3_exec(DB, sql, NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cout << "? Error inserting data: " << messageError << std::endl;
        sqlite3_free(messageError);
    }
    else {
        std::cout << "? Data inserted successfully!" << std::endl;
    }
}

void readData() {
    const char* sql = "SELECT * FROM Students;";
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (exit != SQLITE_OK) {
        std::cout << "? Error reading data." << std::endl;
        return;
    }

    std::cout << "?? Student Records:" << std::endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        std::cout << "ID: " << id << " | Name: " << name << std::endl;
    }

    sqlite3_finalize(stmt);
}

int main() {
    int exit = sqlite3_open("students.db", &DB);

    if (exit != SQLITE_OK) {
        std::cout << "? Can't open database." << std::endl;
        return -1;
    }
    else {
        std::cout << "?? Opened database successfully!" << std::endl;
    }

    createTable();
    insertData();
    readData();

    sqlite3_close(DB);
    return 0;
}
