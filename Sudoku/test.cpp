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

void initializeTestArrWithABlank()
{
	initializeTestArr();
	testarr[0][1] = -1;
}

TEST(TestSudoku, TestSecondConstructor) {
	initializeTestArr();
	Sudoku puzzle = Sudoku(testarr);
	string output = puzzle.getRow(0);
	EXPECT_EQ(output, "1 2 3 4 ");
}

//TEST(TestSudoku, TestInputs) {
//	Sudoku puzzle = Sudoku();
//	string output = puzzle.getRow(0);
//	EXPECT_EQ(output, "1 2 3 4 ");
//}

TEST(TestSudoku, TestPrint) {
	Sudoku puzzle = Sudoku();
	string output = puzzle.print();
	std::cout << output;
	EXPECT_EQ(1, 1);
}

TEST(TestSudoku, TestBlankInputs) {
	initializeTestArrWithABlank();
	Sudoku puzzle = Sudoku(testarr);
	string output = puzzle.getRow(0);
	EXPECT_EQ(output, "1 . 3 4 ");
}