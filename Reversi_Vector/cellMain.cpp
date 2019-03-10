#include <iostream>
#include <vector>
#include <string>
#include "cell.h"
#include "reversi.h"


using namespace std;

int main() {
  Reversi game1(6,6);
  //this function taking parameter name of file
  //First game
  game1.readFile("a.txt");
  game1.printBoard();
  game1.writeFile();
  game1.playGame();
  
  //Second game
  Reversi game2;
  game2.printBoard();
  game2.playGame();
  
  
  //Compare Game
  bool value=compareGame(game1,game2);
  cout<<compareGame(game1,game2);
  //Third game
  Reversi game3(25,25);
  game3.printBoard();
  game3.playGame();
  
  //Fourth game
  Reversi game4(35,35);
  game4.printBoard();
  game4.playGame();
  
  //Fifth game
    Reversi game5;
    game5.printBoard();
    game5.playGame();
 
}
