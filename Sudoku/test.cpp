#include "pch.h"
#include "sudoku.h"

int const SIZE = 4;
int** testarr = new int* [SIZE];

void initializeTestArr()
{
	int firstNum = 0;
	for (int m = 0; m < SIZE; m++) {
		testarr[m] = new int[SIZE];
		for (int n = 0; n < SIZE; n++) {
			testarr[m][n] = ((firstNum + n) % SIZE) + 1;
		}
		firstNum++;
	}
}

TEST(TestSudoku, TestSecondConstructor) {
	initializeTestArr();
	Sudoku puzzle = Sudoku(testarr);
	string output = puzzle.print();
	EXPECT_EQ(output, "1 2 3 4 ");
}

TEST(TestSudoku, TestInputs) {
	Sudoku puzzle = Sudoku();
	string output = puzzle.print();
	EXPECT_EQ(output, "1 2 3 4 ");
}