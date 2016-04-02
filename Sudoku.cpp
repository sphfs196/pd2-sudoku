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
			cout<<sudokuBoard[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Sudoku::readIn()
{
	int i,j;
//	int sudokuBoard2[9][9];
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
	/*int i,j;
	if(!findUnassigned(sudokuBoard2,i,j))
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<sudokuBoard2[i][j];
			}
		}
	}

	for(int num=1;num<=9;num++)
	{
		if(safe(sudokuBoard2))
	}*/

	int num=1,i,j,checkSame=0;

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudokuBoard2[i][j]==0)
			{
				while(1)
				{
					sudokuBoard[i][j]=num;

					for(int col=0;col<9;col++)
					{
						if(sudokuBoard2[i][col]==num)
						{
							checkSame++;
						}
					}					//檢查row有沒有重複
					
					for(int row=0;row<9;row++)
					{
						if(sudokuBoard2[row][j]==num)
						{
							checkSame++;
						}
					}					 //檢查col有沒有重複

					for(int row=0;row<9;row++)
					{
						for(int col=0;col<9;col++)
						{
							if(sudokuBoard2[row+(i-i%3)][col+(j-j%3)]==num)
							{
								checkSame++;
							}
						}
					}					 //檢查box有沒有重複

					if(checkSame!=0)
					{
						if(num<9)
						{
							num++;
							continue;
						}
						else if(num==9)
						{
							sudokuBoard2[i][j]=0;
							if(j>1)//回到上一格重填
							{
								if(sudokuBoard2[i][j-1]!=9)
								{
									sudokuBoard2[i][j-1]++;
									j=j-1;
									continue;
								}
								if(sudokuBoard2[i][j-1]==9)
								{
									sudokuBoard2[i][j-1]=0;
									sudokuBoard2[i][j-2]++;
									j=j-2;
									continue;
								}
							}
							if(j==1)
							{
								j=8;
								if(sudokuBoard2[i-1][j]!=9)
								{
									sudokuBoard2[i-1][j]++;
									i=i-1;
									continue;
								}
								if(sugokuBoard2[i-1][j]==9)
								{
									sudokuBoard2[i-1][j]=0;
									sudokuBoard2[i-1][j-1]++;
									i=i-1;
									j=j-1;
									continue;
								}
							}
						}
					}

					else if(checkSame==0)
					{
						num=1;
						break;
					}
				}//while
			}
		}
	}	
}

void Sudoku::changeNum(int a,int b)
{
	int i,j;
//	int sudokuBoard2[9][9];
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
	int i,j;
	int buffer[9]={0};
//	int sudokuBoard2[9][9];
	
	
	
	if((a==1&&b==0)||(a==0&&b==1))
	{
		for(i=0;i<3;i++)
		{
			j=0;
			for(j=0;j<9;j++)
			{
				buffer[j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i+3][j];
				sudokuBoard2[i+3][j]=buffer[j];
//				cout<<buffer[j]<<" ";
			}
//			cout<<endl;
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
	int i,j;
	int buffer[9];
//	int sudokuBoard2[9][9];
	if((a==1&&b==0)||(a==0&&b==1))
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[i]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i][j+3];
				sudokuBoard2[i][j+3]=buffer[i];
			}
		}
	}

	
	if((a==1&&b==2)||(a==2&&b==1))
	{
		for(j=3;j<6;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[i]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i][j+3];
				sudokuBoard2[i][j+3]=buffer[i];
			}
		}
	}

	if((a==0&&b==2)||(a==2&&b==0))
	{
		for(j=0;j<3;j++)
		{
			for(i=0;i<9;i++)
			{
				buffer[i]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i][j+6];
				sudokuBoard2[i][j+6]=buffer[i];
			}
		}
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudokuBoard2[i][j];
		}
		cout<<endl;
	}

}

void Sudoku::rotate(int n)
{
	int buff[9][9];
	int i,j;
//	int sudokuBoard2[9][9];

	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			buff[i][j]=sudokuBoard2[i][j];
		}
	}
	
	if((n%4)==1||n==1)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudokuBoard2[i][j]=buff[8-j][8-i];
			}
		}
	}


	if((n%4)==2||n==2)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudokuBoard2[i][j]=buff[8-i][8-j];
			}
		}


	/*	for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudokuBoard2[i][j]=buff[8-j][8-i];
			}
		}*/
	}

	if((n%4)==3||n==3)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudokuBoard2[i][j]=buff[j][8-i];
			}
		}
	}

	if((n%4)==0)
	{
/*		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<sudokuBoard2[i][j];
			}
			cout<<endl;
		}*/

	}
}

void Sudoku::flip(int n)
{
	int buff[9][9];
	
	if(n==0)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<9;j++)
			{
				buff[i][j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[8-i][j];
				sudokuBoard2[8-i][j]=buff[i][j];
			}
		}
	}

	if(n!=0)
	{
		for(j=0;j<4;j++)
		{
			for(i=0;i<9;i++)
			{
				buff[i][j]=sudokuBoard2[i][j];
				sudokuBoard2[i][j]=sudokuBoard2[i][8-j];
				sudokuBoard2[i][8-j]=buff[i][j];
			}
		}
	}


		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<sudokuBoard2[i][j];
			}
			cout<<endl;
		}
}

void Sudoku::transform()
{
	readIn();
	
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);

	printOut(false)
}

void Sudoku::printOut(bool isAns)
{
	int i;
	if(!isAns)
	{
		for(i=0;i<81;i++)
		{
			for(j=0;j<81;j++)
			{
				cout<<sudokuBoard[i][j];
			}	
		}
	}

	else
	{
		for(i=0;i<81;i++)
		{
			for(j=0;j<81;j++)
			{
				cout<<sudokuBoard2[i][j];
			}
		}
	}
}
