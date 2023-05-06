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
	calculateChecksum();
}

void Sudoku::calculateChecksum() {
	int checkSum = 0;
	int counter = 1;
	int boxWidth = Sudoku::SIZE / Sudoku::MAJ_HORZ_GRIDS;
	for (int i = 0; i < boxWidth * boxWidth; i++)
		checkSum += counter++;
	Sudoku::checkSum = checkSum;
}

bool Sudoku::checkBox(int mb, int nb) {
	int sum = 0;
	int boxWidth = Sudoku::SIZE / Sudoku::MAJ_HORZ_GRIDS;
	for (int m = mb * boxWidth; m < boxWidth*(mb + 1); m++) {
		for (int n = nb * boxWidth; n < boxWidth*(nb + 1); n++) {
			sum += arr[m][n];
		}
	}
	if (sum == Sudoku::checkSum)
		return true;
	else
		return false;
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
			if ((input.empty()) || (input.compare(" ")  == 0))
				input_arr[m][n] = -1;
			else
				input_arr[m][n] = stoi(input);
		}
		std::getline(cin, input);
		input_arr[m][Sudoku::SIZE-1] = stoi(input);
	}
	return input_arr;
}

string Sudoku::getRow(int m) {
	string output = "";
	for (int n = 0; n < Sudoku::SIZE; n++)
	{
		if (Sudoku::arr[m][n] != -1)
			output += to_string(Sudoku::arr[m][n]);
		else
			output += ".";
		output += " ";
	}
	return output;
}

string Sudoku::print() {
	string output = "";
	int charWidth = 2 * (Sudoku::SIZE + Sudoku::MAJ_VERT_GRIDS) + 1;
	

	// iterate down the rows
	for (int m = 0; m < Sudoku::SIZE; m++) {
		// check if we need to add a horizontal line
		if (m % Sudoku::MAJ_VERT_GRIDS == 0) {
			for (int i = 0; i < charWidth; i++) output += "-";
			output += "\n";
		}

		// add a line of numbers
		for (int n = 0; n < Sudoku::SIZE; n++)
		{
			// add verticle line
			if (n % Sudoku::MAJ_VERT_GRIDS == 0) output += "| ";

			if (Sudoku::arr[m][n] != -1)
				output += to_string(Sudoku::arr[m][n]);
			else
				output += ".";
			output += " ";
		}
		output += "|\n";
	}

	// add bottom line
	for (int i = 0; i < charWidth; i++) output += "-";
	output += "\n";
	return output;
}