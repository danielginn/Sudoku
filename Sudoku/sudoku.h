#pragma once
#include <iostream>

using namespace std;

class Sudoku {
private:
	// Member variables:
	int arr[9][9];

	// Internal functions:
	int** inputInitialValues();
public:
	int const SIZE = 4;
	Sudoku();
	Sudoku(int** newarr);

	void set(int m, int n, int value) {
		arr[m][n] = value;
	}

	int get(int m, int n) {
		return arr[m][n];
	}

	string getRow(int m);

	string print();
};
