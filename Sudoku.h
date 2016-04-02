#include<iostream>

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
//	private:
	int i,j,sudokuBoard[9][9],sudokuBoard2[9][9],buffer[9];

};	
