#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Sudoku
{
	public:
	void giveQuestion();
	void readIn();
	void solve();
	void changeNum(int a,int b);
	void changeRow(int a,int b);
	void changeCol(int a,int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	void printOut(bool isAnt);
	bool check0(int sudokuBoard2[9][9],int &row,int &col);
	bool checkRow(int sudokuBoard2[9][9],int row,int num);
	bool checkCol(int sudokuBoard2[9][9],int col,int num);
	bool checkBox(int sudokuBoard2[9][9],int startRow,int startCol,int num);
	bool safe(int sudokuBoard2[9][9],int row,int col,int num);
	bool solveS(int sudokuBoard2[9][9]);
	bool judge(int sudokuBoard2[9][9]);

	//	private:
	int i,j,sudokuBoard[9][9],sudokuBoard2[9][9],buffer[9],num;
	int judgeB[9][9];
};	
