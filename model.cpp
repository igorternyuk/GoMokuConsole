#include "model.h"
Board:: Board():BOARD_SIZE(10) {
    /*tmp = new int[100];
    gameBoard = new int*[10];
    for (int i = 0; i < 10; i++) {
      gameBoard[i] = &tmp[i * 10];
    }*/
    for (int i = 0; i < 10; i++) 
      for (int j = 0; j < 10; j++)
	gameBoard[i][j] = blank;
    }
/*Board:: ~Board() {
   delete [] gameBoard;
   delete [] tmp;   
 }*/
bool Board::makeMove(int x, int y, player number) {
  if (number == ONE)
  gameBoard[x][y] = X;
  if (number == TWO)
  gameBoard[x][y] = O;
}
int Board:: isWin() {
  int count_blank = 0;
  
  // Проверяем строки
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
    if (gameBoard[i][j] == X && gameBoard[i][j + 1] == X && gameBoard[i][j + 2] == X
        && gameBoard[i][j + 3] == X && gameBoard[i][j + 4] == X) return X_WIN;
  }
  
  // Проверяем столбцы
  
    for (int j = 0; j < 10; j++) {
    for (int i = 0; i < 10; i++)
    if (gameBoard[i][j] == X && gameBoard[i + 1][j] == X && gameBoard[i + 2][j] == X
        && gameBoard[i + 3][j] == X && gameBoard[i + 4][j] == X) return X_WIN;
  }
  
    // Проверяем строки
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
    if (gameBoard[i][j] == O && gameBoard[i][j + 1] == O && gameBoard[i][j + 2] == O
        && gameBoard[i][j + 3] == O && gameBoard[i][j + 4] == O) return O_WIN;
  }
  
  // Проверяем столбцы
  
    for (int j = 0; j < 10; j++) {
    for (int i = 0; i < 10; i++)
    if (gameBoard[i][j] == O && gameBoard[i + 1][j] == O && gameBoard[i + 2][j] == O
        && gameBoard[i + 3][j] == O && gameBoard[i + 4][j] == O) return O_WIN;
  }
  
  //Проверяем диагонали
  
   for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[k + i][i] == X && gameBoard[k + i + 1][i + 1] == X && gameBoard[k + i + 2][i + 2] == X
        && gameBoard[k + i + 3][i + 3] == X && gameBoard[k + i + 4][i + 4] == X) return X_WIN;
	c--;
  }
  
   for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i][k + i] == X && gameBoard[i + 1][k + i + 1] == X && gameBoard[i + 2][k + i + 2] == X
        && gameBoard[i + 3][k + i + 3] == X && gameBoard[i + 4][k + i + 4] == X) return X_WIN;
	c--;
  }
  
  
  for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i + k][9 - i] == X && gameBoard[i + k + 1][8 - i] == X && gameBoard[i + k + 2][7 - i] == X
        && gameBoard[i + k + 3][6 - i] == X && gameBoard[i + k + 4][5 - i] == X) return X_WIN;
	c--;
  }
  
  for (int k = 0, c = 6; k < 5; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i][8 - i - k] == X && gameBoard[i + 1 - k][7 - i] == X && gameBoard[i + 2][6 - i - k] == X
        && gameBoard[i + 3][5 - i - k] == X && gameBoard[i + 4][4 - i - k] == X) return X_WIN;
	c--;
  }
  
  for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[k + i][i] == O && gameBoard[k + i + 1][i + 1] == O && gameBoard[k + i + 2][i + 2] == O
        && gameBoard[k + i + 3][i + 3] == O && gameBoard[k + i + 4][i + 4] == O) return O_WIN;
	c--;
  }
  
   for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i][k + i] == O && gameBoard[i + 1][k + i + 1] == O && gameBoard[i + 2][k + i + 2] == O
        && gameBoard[i + 3][k + i + 3] == O && gameBoard[i + 4][k + i + 4] == O) return O_WIN;
	c--;
  }
  for (int k = 0, c = 6; k < 6; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i + k][9 - i] == O && gameBoard[i + k + 1][8 - i] == O && gameBoard[i + k + 2][7 - i] == O
        && gameBoard[i + k + 3][6 - i] == O && gameBoard[i + k + 4][5 - i] == O) return O_WIN;
	c--;
  }
  
  for (int k = 0, c = 6; k < 5; k++) {
    for (int i = 0; i < c; i++)
    if (gameBoard[i][8 - i - k] == O && gameBoard[i + 1 - k][7 - i] == O && gameBoard[i + 2][6 - i - k] == O
        && gameBoard[i + 3][5 - i - k] == O && gameBoard[i + 4][4 - i - k] == O) return O_WIN;
	c--;
  }

  
  //Проверка на ничью
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
    if (gameBoard[i][j] == blank) count_blank++;
}
  if (count_blank == 0) return DRAW;

  return NO_WIN;
}
