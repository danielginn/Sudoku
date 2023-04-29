#include "pch.h"
#include "sudoku.h"
#include <iostream>
#include <string>

using namespace std;

Sudoku::Sudoku() {
	cout << "Initial values of sudoku puzzle:" << endl;
	cout << "Please enter first row separated by commas: ";
	string input;
	int** input_arr = new int*[9];
	input_arr[0] = new int[9];
	for (int i = 0; i < 8; i++) {
		std::getline(cin, input, ',');
		input_arr[0][i] = stoi(input);
	}
	std::getline(cin, input);
	input_arr[0][8] = stoi(input);
	this->Sudoku::Sudoku(input_arr);
}

Sudoku::Sudoku(int** newarr) {
	for (int m = 0; m < 9; m++)
	{
		for (int n = 0; n < 9; n++)
		{
			Sudoku::arr[m][n] = newarr[m][n];
		}
	}
}

	

string Sudoku::print() {
	string output = "";
	for (int i = 0; i < 9; i++)
	{
		output += to_string(Sudoku::arr[0][i]);
		output += " ";
	}
	return output;
}