//#include "model.h"
#include "boardView.h"
int main() {
  Board b;
  BoardView v(&b);
  v.startGame();
  return 0;
}