#include<iostream>
#include <iomanip>
#include"Suduko.h"

using namespace std;

int main()
{
    printboard();
	cout << "Is it safe to put 3 at (0, 2)? " << (isSafe(0, 2, 3) ? "Yes" : "No") << endl;
	cout << "Is it safe to put 1 at (0, 2)? " << (isSafe(0, 2, 1) ? "Yes" : "No") << endl;

	return 0;
}