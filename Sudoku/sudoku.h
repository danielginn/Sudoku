#pragma once
#include <iostream>

using namespace std;

class Sudoku {
private:
	// Member variables:
	int arr[9][9];
	int checkSum;

	// Internal functions:
	int** inputInitialValues();
	void calculateChecksum();
	
public:
	int const SIZE = 4;
	int const MAJ_VERT_GRIDS = 2;
	int const MAJ_HORZ_GRIDS = 2;
	Sudoku();
	Sudoku(int** newarr);
	bool checkBox(int mb, int nb);
	void set(int m, int n, int value) {
		arr[m][n] = value;
	}

	int get(int m, int n) {
		return arr[m][n];
	}

	string getRow(int m);

	string print();
};
