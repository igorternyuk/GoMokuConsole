#include "model.h"
class BoardView {
private:
  Board *board;
  void show();
public:
  BoardView(Board *b);
  void startGame();
  void doInput(int number);
  bool inRange(int test);
};