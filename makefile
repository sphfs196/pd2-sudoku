SudokuMain:SudokuMain.o Sudoku.o
		g++ -o SudokuMain SudokuMain.o Sudoku.o
SudokuMain.o:SudokuMain.cpp Sudoku.h
		g++ -c SudokuMain.cpp
Sudoku.o:Sudoku.cpp Sudoku.h
		g++ -c Sudoku.cpp
clean:
		rm SudokuMain.o Sudoku.o
