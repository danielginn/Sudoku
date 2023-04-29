#include "pch.h"
#include "sudoku.h"

int** testarr = new int* [9];

void initializeTestArr()
{
	int firstNum = 0;
	for (int m = 0; m < 9; m++) {
		testarr[m] = new int[9];
		for (int n = 0; n < 9; n++) {
			testarr[m][n] = ((firstNum + n) % 9) + 1;
		}
		firstNum++;
	}
}

TEST(TestSudoku, TestSecondConstructor) {
	initializeTestArr();
	Sudoku puzzle = Sudoku(testarr);
	string output = puzzle.print();
	EXPECT_EQ(output, "1 2 3 4 5 6 7 8 9 ");
}
