#include"Sudoku.h"
void Sudoku::giveQuestion()
{
	int i,j;
	int sudokuBoard[9][9]={
							{0,0,4,0,0,0,0,7,0},
							{5,0,0,0,0,6,0,0,0},
							{0,0,0,5,0,0,0,0,3},
							{0,3,0,0,0,0,7,0,0},
							{0,0,0,0,6,0,0,0,0},
							{0,0,1,0,0,0,0,2,0},
							{2,0,0,0,0,7,0,0,0},
							{0,0,0,2,0,0,0,0,5},
							{0,6,0,0,0,0,2,0,0}
  						};
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudokuBoard[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Sudoku::readIn()
{
	int sudokuBoard2[9][9];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>sudokuBoard2[i][j];
		}
	}
}

void Sudoku::solve()
{

}

void Sudoku::changeNum(int a,int b)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudokuBoard2[i][j]==a)
			{
				sudokuBoard2[i][j]=b;
			}
			else if(sudokuBoard2[i][j]==b)
			{
				sudokuBoard2[i][j]=a;
			}
		}
	}
}

void Sudoku::changeRow(int a,int b)
{
	int buffer[9];
	if((a==1&&b==0)||(a==0&&b==1))
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<9;j++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+3][j];
				sudokuBoard2[i+3][j]=buffer[j];
			}
		}
	}

	
	if((a==1&&b==2)||(a==2&&b==1))
	{
		for(i=3;i<6;i++)
		{
			for(j=0;j<9;j++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+3][j];
				sudokuBoard2[i+3][j]=buffer[j];
			}
		}
	}

	if((a==0&&b==2)||(a==2&&b==0))
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<9;j++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+6][j];
				sudokuBoard2[i+6][j]=buffer[j];
			}
		}
	}
}

void Sudoku::changeCol(int a,int b)
{
	int buffer[9];
	if((a==1&&b==0)||(a==0&&b==1))
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+3][j];
				sudokuBoard2[i+3][j]=buffer[j];
			}
		}
	}

	
	if((a==1&&b==2)||(a==2&&b==1))
	{
		for(j=3;j<6;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+3][j];
				sudokuBoard2[i+3][j]=buffer[j];
			}
		}
	}

	if((a==0&&b==2)||(a==2&&b==0))
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+6][j];
				sudokuBoard2[i+6][j]=buffer[j];
			}
		}
	}
}

void Sudoku::rotate(int n)
{

}

void Sudoku::flip(int n)
{

}

void Sudoku::transform()
{

}

