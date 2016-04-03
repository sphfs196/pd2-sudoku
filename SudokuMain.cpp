#include"Sudoku.h"
//#include<string>
//#include<fstream>

using namespace std;

main()
{
//		cout<<"w!!";
		Sudoku ss;
		ss.readIn();
		 //put transformated functions here 
	//	ss.rotate(6);
//		ss.flip(1);
//		ss.changeCol(2,0);
//		cout<<"w";
		ss.solve();
		return 0;
}

/*main()
{
		Sudoku ss;
		ss.giveQuestion();
		return 0;
}*/

/*main()
{
		Sudoku ss;
		ss.transform();
		return 0;
}*/
