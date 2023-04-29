#include "pch.h"
#include "sudoku.h"
#include <iostream>
#include <string>

using namespace std;

Sudoku::Sudoku() {
	int** input_arr = Sudoku::inputInitialValues();
	this->Sudoku::Sudoku(input_arr);
}

Sudoku::Sudoku(int** newarr) {
	for (int m = 0; m < Sudoku::SIZE; m++)
	{
		for (int n = 0; n < Sudoku::SIZE; n++)
		{
			Sudoku::arr[m][n] = newarr[m][n];
		}
	}
}

int** Sudoku::inputInitialValues() {
	cout << "Initial values of sudoku puzzle:" << endl;
	cout << "Please enter rows separated by commas: ";
	string input;
	int** input_arr = new int* [Sudoku::SIZE];
	for (int m = 0; m < Sudoku::SIZE; m++) {
		input_arr[m] = new int[Sudoku::SIZE];
		for (int n = 0; n < Sudoku::SIZE - 1; n++) {
			std::getline(cin, input, ',');
			input_arr[m][n] = stoi(input);
		}
		std::getline(cin, input);
		input_arr[m][Sudoku::SIZE-1] = stoi(input);
	}
	return input_arr;
}

string Sudoku::print() {
	string output = "";
	for (int i = 0; i < Sudoku::SIZE; i++)
	{
		output += to_string(Sudoku::arr[0][i]);
		output += " ";
	}
	return output;
}