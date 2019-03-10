#include <iostream>
#include <vector>
#include <string>
#include "cell.h"
#include "reversi.h"


using namespace std;

int main() {

  Cell gameCell_1;
  cin>>gameCell_1;

  Cell gameCell_2;
  cin>>gameCell_2;

  if (gameCell_1 <= gameCell_2) {
    if (gameCell_1 < gameCell_2)
      cout << "First cell is smaller than the other " << endl;
    else if (gameCell_1 == gameCell_2)
      cout << "Cells are equal" << endl;
  } else if (gameCell_1 >= gameCell_2) {
    if (gameCell_1 > gameCell_2)
      cout << "First Cell is bigger than the other " << endl;
  }
  if (gameCell_1 != gameCell_2)
    cout << "Two cells aren't equal" << endl;

  cout << "////// Values of Cells//////" << endl;
  cout << gameCell_1 << endl;
  cout << gameCell_2 << endl;

  cout << "//pre//Increased Values : ";

  cout << ++gameCell_1 << endl;

  cout << "//post//Increased Values : ";
  cout << gameCell_2++ << endl;

  Reversi game1(6, 6);
  cout << "///////Value of Parameter////////" << endl;
  cout << "Before row and after column" << endl;
  cout << game1["d2"] << endl;
  cout << game1("a", 2) << endl;

  game1 += gameCell_1;
  //cout<<game1;
  //this function taking parameter name of file
  //First game
  game1.readFile("a.txt");
  cout << game1;
  game1.writeFile();
  game1.playGame();

  //Second game
  Reversi game2;
  //game2.printBoard();
  game2.playGame();


  //Compare Game
  bool value = compareGame(game1, game2);
  cout << value;
  //Third game
  Reversi game3(25, 25);
  //game3.printBoard();
  game3.playGame();

  //Fourth game
  Reversi game4(35, 35);
  //game4.printBoard();
  game4.playGame();

  //Fifth game
  Reversi game5;
  //game5.printBoard();
  game5.playGame();

}
