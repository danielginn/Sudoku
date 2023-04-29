#pragma once
#include <iostream>

using namespace std;

class Sudoku {
private:
	// Member variables:
	int arr[9][9];

	// Internal functions:
	void inputInitialValues();
public:
	Sudoku();
	Sudoku(int** newarr);

	void set(int m, int n, int value) {
		arr[m][n] = value;
	}

	int get(int m, int n) {
		return arr[m][n];
	}

	string print();
};
