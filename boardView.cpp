#include "boardView.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

BoardView:: BoardView(Board *b) {
  board = b;
}
void BoardView:: show() {
  cout << "  ";
  for(int j = 0; j < 10; j++) 
  cout << "  " << j << " ";
  cout << endl;
  cout << "  -----------------------------------------" << endl;
  //cout << "***********************************************" << endl;
  for(int i = 0; i < 10; i++){
    cout << i << " ";
     for(int j = 0; j < 10; j++) 
	cout << "| " << (char)board->getCeil(i, j) << " ";  
    cout << "| " << i << endl;
    cout << "  -----------------------------------------" << endl;
    //cout << "***********************************************" << endl;
  }
  cout << "  ";
  for(int j = 0; j < 10; j++) 
  cout << "  " << j << " ";
  cout << endl;
}
void BoardView:: doInput(int number) {
  int input1, input2;
  do {
    do {
      if (number == ONE)
      cout << "\nИгрок номер " << number << ", введите номер ряда для крестиков:\n";
      else cout << "\nИгрок номер " << number << ", введите номер ряда для ноликов:\n";
      cin >> input1;
     }while(!inRange(input1));
    do {
      if (number == ONE)
      cout << "\nИгрок номер " << number << ", введите номер столбца для крестиков:\n";
      else cout << "\nИгрок номер " << number << ", введите номер столбца для ноликов:\n";
      cin >> input2;
    }while(!inRange(input2));
  }while(board->isTaken(input1, input2));
  if (number == ONE)
  board->makeMove(input1, input2, ONE);
  else board->makeMove(input1, input2, TWO);
  
}
void BoardView::startGame() {
  string player1, player2;
  cout << "Добро пожаловать в крестики нолики!" << endl;
  cout << "Игрок один введите свое имя:\n ";
  cin >> player1;
  cout << "Игрок два введите свое имя:\n ";
  cin >> player2;
  while(board->isWin() == NO_WIN) {
    doInput(ONE);
    if (board->isWin() == X_WIN) break;
    show();
    doInput(TWO);
    show();
  }
  show();
  switch (board->isWin()) {
    case X_WIN:cout << "Игрок, " << player1 <<" вы победили!:\n";
		break;
    case O_WIN:cout << "Игрок, " << player2 <<" вы победили!:\n";
		break;
    case DRAW:cout << "Ничья!:\n ";
	      break;
  }
}
bool BoardView:: inRange(int test) {
  return test > -1 && test < 10;
}