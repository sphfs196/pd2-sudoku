#include"Sudoku.h"
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>

#define UNASSIGNED 0
#define N 9


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
		//		cout<<i<<" ";
		for(j=0;j<9;j++)
		{
			cin>>sudokuBoard2[i][j];
			judgeB[i][j]=sudokuBoard2[i][j];
		}
		//		cout<<i;
	}
	/*	for(int a=0;a<9;a++)
		{
		for(int b=0;b<9;b++)
		{
		cout<<sudokuBoard2[a][b]<<" ";
		}
		cout<<endl;
		}*/
}

/*bool check0(int sudokuBoard2[N][N], int &row, int &col);
  bool safe(int sudokuBoard2[N][N], int row, int col, int num);


  bool Sudoku::solveS(int sudokuBoard2[N][N])
  {
  int row,col;
//	cout<<"w"<<" ";
if(check0(sudokuBoard2,row,col)==false)
{
return true;
}
//	else{return false;}

//	cout<<"w";
for(int num=1;num<=9;num++)
{
//		cout<<"R";
if(safe(sudokuBoard2,row,col,num)==true)
{
cout<<"w";
sudokuBoard2[row][col]=num;
cout<<"~";
if(solveS(sudokuBoard2)==true)
{
return true;
}

//sudokuBoard2[row][col]=u;//
}
}
return false;
}

bool Sudoku::check0(int sudokuBoard2[N][N],int &row,int &col)
{
for(int row=0;row<N;row++)
{
for(int col=0;col<N;col++)
{
if(sudokuBoard2[row][col]==u)
{	
//					cout<<"W";
return true;
}	
}
}
return false;	
}*/

/*bool Sudoku::checkRow(int sudokuBorad2[N][N],int row,int num)
  {
  for(int col=0;col<N;col++)
  {
  if(sudokuBoard2[row][col]==num)
  {
  return true;
  }
  }
  return false;					//檢查row有沒有重複
  }*/


/*bool Sudoku::checkRow(int sudokuBoard2[N][N],int row,int num)
  {
  for(int col=0;col<9;col++)
  if(sudokuBoard2[row][col]==num)
  return true;
  return false;
  }*/

/*bool Sudoku::checkRow(int sudokuBoard2[N][N], int row, int num)
  {
  cout<<"row";
  for (int col = 0; col < N; col++)
  if (sudokuBoard2[row][col] == num)
  return true;
  return false;
  }*/

/*bool Sudoku::checkCol(int sudokuBoard2[N][N],int col,int num)
  {
  for(int row=0;row<N;row++)
  {
  if(sudokuBoard2[row][col]==num)
  {
  return true;
  }	
  }	
  return false;
  }


  bool Sudoku::checkRow(int sudokuBoard2[N][N],int row,int num)
  {
  for(int col=0;col<N;col++)
  {
  if(sudokuBoard2[row][col]==num)
  {
  return true;
  }	
  }	
  return false;
  }

  bool Sudoku::checkBox(int sudokuBoard2[N][N],int rowBegin,int colBegin,int num)
  {
  for(int row=0;row<3;row++)
  {
  for(int col=0;col<3;col++)
  {
  if(sudokuBoard2[row+rowBegin][col+colBegin]==num)
  {
  return true;
  }
  }
  }
  return false;
  }*/

//bool Sudoku::safe(int sudokuBoard2[N][N],int row,int col,int num)
//{
//return true;
//return !checkRow(sudokuBoard2, row, num) /*&& !checkCol(sudokuBoard2, col, num) && !checkBox(sudokuBoard2, row - row%3 , col - col%3, num)*/;		   

//		return (checkRow(sudokuBoard2,row,num)==false)&&(checkCol(sudokuBoard2,col,num)==false)&&(checkBox(sudokuBoard2,row-(row%3),col-(col%3),num)==false);
//}

/*bool Sudoku::solveS(int sudokuBoard2[N][N])
  {
  int row,col;
//	cout<<"w"<<" ";
if(check0(sudokuBoard2,row,col)==false)
{
return true;
}
//	else{return false;}

//	cout<<"w";
for(int num=1;num<=9;num++)
{
//		cout<<"R";
if(safe(sudokuBoard2,row,col,num)==true)
{
cout<<"w";
sudokuBoard2[row][col]=num;
cout<<"~";
if(solveS(sudokuBoard2)==true)
{
return true;
}

sudokuBoard2[row][col]=u;
}
}
return false;
}*/

bool Sudoku::judgeQ1(int sudokuBoard2[N][N])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			for(int k=0;k<j;k++)
			{
				if(sudokuBoard2[i][j]!=0&&sudokuBoard2[i][k]!=0)
				{
					if(sudokuBoard2[i][j]==sudokuBoard2[i][k])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool Sudoku::judgeQ2(int sudokuBoard2[N][N])
{
	for(int j=0;j<9;j++)
	{
		for(int i=0;i<9;i++)
		{
			for(int k=0;k<i;k++)
			{
				if(sudokuBoard2[i][j]!=0&&sudokuBoard2[k][j]!=0)
				{
					if(sudokuBoard2[i][j]==sudokuBoard2[k][j])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}



bool Sudoku::judge(int judgeB[N][N])
{
	
/*  	for(int i=0;i<9;i++)
  	{
  		for(int j=0;j<9;j++)
  		{
  			judgeB[i][j]=s[i][j];
  		}
  	}*/
	int row, col;
	if (!checkU(judgeB, row, col))
		return true;
	for (int num = 9; num >= 1; num--)
	{
		if (safe(judgeB, row, col, num))
		{
			judgeB[row][col] = num;
			if (judge(judgeB))
				return true;
			judgeB[row][col] = UNASSIGNED;
		}
	}
	return false;
}

/*bool Sudoku::judge(int sudokuBoard2[N][N])
{
	int row,col;
  	for(int i=0;i<9;i++)
  	{
  		for(int j=0;j<9;j++)
  		{
  			judgeB[i][j]=sudokuBoard[i][j];
  		}
  	}
//	cout<<"w"<<" ";
	if(checkU(judgeB,row,col)==false)
	{
		return true;
	}

	for(int num=9;num>=1;num--)
	{
		if(safe(judgeB,row,col,num)==true)
		{
			judgeB[row][col]=num;
			if(solveS(judgeB)==true)
			{
			return true;
			}
			judgeB[row][col]=UNASSIGNED;
		}
	}		
	return false;
}*/

/*bool Sudoku::B(int sudokuBoard2[N][N])
  {
  return true;
  }*/

//bool Sudoku::checkU(int grid[N][N], int &row, int &col);
//bool Sudoku::safe(int grid[N][N], int row, int col, int num);

bool Sudoku::solveS(int s[N][N])
{
	int row, col;
	if (!checkU(s, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (safe(s, row, col, num))
		{
			s[row][col] = num;
			if (solveS(s))
				return true;
			s[row][col] = UNASSIGNED;
		}
	}
	return false;
}

bool Sudoku::checkU(int s[N][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if(s[row][col] == UNASSIGNED)
				return true;
	return false;
}

bool Sudoku::checkRow(int s[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (s[row][col] == num)
			return true;
	return false;
}

bool Sudoku::checkCol(int s[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (s[row][col] == num)
			return true;
	return false;
}

bool Sudoku::checkBox(int s[N][N], int rowBegin, int colBegin, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (s[row+rowBegin][col+colBegin] == num)
				return true;
	return false;
}


bool Sudoku::safe(int s[N][N], int row, int col, int num)
{
	return !checkRow(s, row, num) && !checkCol(s, col, num) &&
		!checkBox(s, row - row % 3 , col - col % 3, num);
}


void Sudoku::solve()
{
		if(judgeQ1(sudokuBoard2)==false||judgeQ2(sudokuBoard2)==false)
		{
			cout<<"0";
			exit(1);
		}
		/*else
		{
		cout<<"1";
		}*/

		
		int check=0;
		if(judge(judgeB)==true && solveS(sudokuBoard2)==true)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(judgeB[i][j]!=sudokuBoard2[i][j])
					{
						check++;
						break;
					}

				}
				if(check!=0)
				{
					break;
				}
			}	
			if(check==0)
			{
				cout<<"1"<<endl;
			}
			else if(check!=0)
			{
				cout<<"2";
				exit(1);
			}
		}
		if(solveS(sudokuBoard2)==false)
		{
			cout<<"0";
			exit(1);
		}
		

	/*	int sudokuBoard[9][9]={
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
	 */	

	if(solveS(sudokuBoard2)==true)
	{
//		cout<<"W"<<" ";
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cout<<sudokuBoard2[i][j]<<" ";
			}
			cout<<endl;
		}
	}


}


/*	int num=1,i,j,checkSame=0;

	for(i=0;i<9;i++)
	{
	for(j=0;j<9;j++)
	{
	if(sudokuBoard2[i][j]==0)
	{
	while(1)
	{
	sudokuBoard2[i][j]=num;
	checkSame=0;
	for(int col=0;col<9;col++)
	{
	if(col!=j)
	{
	if(sudokuBoard2[i][col]==num)
	{
	checkSame++;
//								cout<<checkSame<<" ";
}
}
}					//檢查row有沒有重複

//				cout<<checkSame<<" ";
for(int row=0;row<9;row++)
{
if(row!=i)
{
if(sudokuBoard2[row][j]==num)
{	
checkSame++;
//								cout<<checkSame<<" ";
}
}					 //檢查col有沒有重複
}

for(int row=0;row<9;row++)
{
for(int col=0;col<9;col++)
{
if(row+(i-i%3)!=i&&col+(j-j%3)!=j)
{
if(sudokuBoard2[row+(i-i%3)][col+(j-j%3)]==num)
{
checkSame++;
}
}
}
}					 //檢查box有沒有重複
//					cout<<checkSame<<" ";

if(checkSame!=0)
{
if(num<9)
{
num++;
//							continue;
}
else if(num==9)
{
sudokuBoard2[i][j]=0;
if(j>0)//回到上一格重填
{
if(sudokuBoard2[i][j-1]!=9)
{
num=sudokuBoard2[i][j-1]+1;
j=j-1;
//									continue;
}
if(sudokuBoard2[i][j-1]==9)
{
	sudokuBoard2[i][j-1]=0;
	num=sudokuBoard2[i][j-2]+1;
	j=j-2;
	//									continue;
}
}
if(j==0)
{
	j=8;
	if(sudokuBoard2[i-1][j]!=9)
	{
		num=sudokuBoard2[i-1][j]+1;
		i=i-1;
		//									continue;
	}
	if(sudokuBoard2[i-1][j]==9)
	{
		sudokuBoard2[i-1][j]=0;
		num=sudokuBoard2[i-1][j-1]+1;
		i=i-1;
		j=j-1;
		//									continue;
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
//			cout<<"QAQ";
}
cout<<"QAQ ";
}*/



/*		for(i=0;i<9;i++)
		{
		for(j=0;j<9;j++)
		{
		cout<<sudokuBoard2[i][j];
		}
		cout<<endl;
		}*/


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

/*	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudokuBoard2[i][j];
		}
		cout<<endl;
	}*/

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
		exit(1);
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


/*	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudokuBoard2[i][j];
		}
		cout<<endl;
	}*/
}



void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::transform()
{
	readIn();
	change();
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<sudokuBoard2[i][j]<<" ";
		}
		cout<<endl;
	}
}


