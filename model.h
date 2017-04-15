enum  game_state {X_WIN = 0, O_WIN, DRAW, NO_WIN};
enum square_state {blank = ' ', X = 'X', O = 'O'};
enum  player {ONE = 1, TWO = 2};
class Board {
private:
  /*int **gameBoard;
  int *tmp;*/
  int gameBoard[10][10];
  int BOARD_SIZE;
public:
  Board();
 //~Board();
  bool makeMove(int x, int y, player number);
  int getSize() {
    return BOARD_SIZE;
  }
  int isWin();
  int getCeil(int x, int y) {
    return gameBoard[x][y];
  }
  bool isTaken(int x, int y) {
    return (gameBoard[x][y] != blank);
  }
  
};

