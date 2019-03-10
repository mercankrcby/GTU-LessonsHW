//Name-Surname:Mercan Karacabey
//No:131044014

//////////REVERSI GAME//////////

//Aims:
//Using vectors 
//Reversi Game with two dimensional vector 
//Game keeps only living Cell
//Using static,const ,inline keywords
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "cell.h"
#include "reversi.h"
using namespace std;


////CONSTRUCTORS////
//First Constructor: It creates 2*2 vectors
Reversi::Reversi() {
  
  const int size=6; 
  vector<Cell> row1;
  row1.push_back(Cell(size/2-1,size/2 -1,'X'));
  row1.push_back(Cell(size/2-1,size/2,'O'));
  gameCell.push_back(row1);

  vector<Cell>row2;
  row2.push_back(Cell(size/2,size/2-1,'O'));
  row2.push_back(Cell(size/2,size/2,'X'));
  gameCell.push_back(row2);
 
}
//Second Constructor:
//This constructor takes two parameters and fills the data member 
Reversi::Reversi(int nRow, int nColumn) : width(nColumn), height(nRow) {
  vector<Cell> row1;
  row1.push_back(Cell(height / 2 - 1, width / 2 - 1, 'X'));
  row1.push_back(Cell(height / 2 - 1, width / 2, 'O'));
  gameCell.push_back(row1);

  vector<Cell> row2;
  row2.push_back(Cell(height / 2, width / 2 - 1, 'O'));
  row2.push_back(Cell(height / 2, width / 2, 'X'));
  gameCell.push_back(row2);
}
//// GETTERS & SETTERS ////
inline int Reversi::getWidth()const {
  return width;
}

inline int Reversi::getHeight()const {
  return height;
}

inline void Reversi::setWidth(int widthBoard) {
  width = widthBoard;
}

inline void Reversi::setHeight(int heightBoard) {
  height = heightBoard;
}
/////FUNCTIONS/////

//This function prints board on the screen 
void Reversi::printBoard()const {
  unsigned int h = 0, w = 0;

  cout << "  ";
  for (int i = 0; i < getWidth(); ++i){
      for(int j=0;j<=(i/26);++j){
          cout<< char(i%26+97);
      }
  }
  cout << endl;

  for (int i = 0; i < getHeight(); ++i) {
    cout << i << " ";
    for (int j = 0; j < getWidth(); ++j) {
      //cout<<"h:"<<h<<"w:"<<w<<endl;
      if (gameCell[h][w].getColumn() == j && gameCell[h][w].getRow() == i) {
        cout << gameCell[h][w].getCharWhose();
        if (w + 1 < gameCell[h].size())
          w++;
        else {
          h++;
          w = 0;
          if (h == gameCell.size())
            h = 0;
        }
      } else
        cout << '.';
    }
    cout << endl;
  }
}
//This function prints board in file
void Reversi::writeFile() {

  ofstream of;
  of.open("vector.txt");
  if (of.is_open()) {

    unsigned int h = 0, w = 0;
    
    for (int i = 0; i < getHeight(); ++i) {
      for (int j = 0; j < getWidth(); ++j) {
        if (gameCell[h][w].getColumn() == j && gameCell[h][w].getRow() == i) {
          of << gameCell[h][w].getCharWhose();
          if (w + 1 < gameCell[h].size())
            w++;
          else {
            h++;
            w = 0;
            if (h == gameCell.size())
              h = 0;
          }
        } else
          of << '.';
      }
      of << endl;
    }
  } else {
    cerr << "File open error";
    exit(1);
  }
}
//This function reads board from file
void Reversi::readFile(const char *fname) {

  char c;
  ifstream inF;
  int awidth;
  int aheight;
  int i = 0;
  int j = 0;
  inF.open(fname);

  vector<Cell> file;
  if (inF.is_open()) {
    while (inF.get(c)) {
      //cout << c;
      if (c == '\n') {
        if (file.size() > 0) {
          gameCell.push_back(file);
          file.clear(); // file ýn sonuna eklemeyi onler
        }
        ++i;
        aheight = i;
        awidth = j;
        j = 0;
      } else {
        if (c == 'X' || c == 'O') {
          Cell a(i, j, c);
          file.push_back(a);
        }
        ++j;
      }
    }
    setHeight(aheight + 1);
    setWidth(awidth - 1);
  } else {
    cout << "File didn't open";
  }
}

//This function controls true or not true ,entrying values from user or computer
int Reversi::truth_control(int nRow, int nColumn, char find) const {

  int i = 0, j = 0;
  bool oFound = false;
  bool inBoard = false;
  int value = 0;
  int sayac = 0;
  int tempRow = nRow;
  int tempColumn = nColumn;
  char me;
  if (find == 'X')
    me = 'O';
  else me = 'X';

  //right control

  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  //left control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  //down control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn) {
          inBoard = true;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  //up control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn) {
          inBoard = true;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  //left up cross control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  //left down cross control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);


  //right up cross control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value += sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  //right down cross control
  sayac = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  return value;
}
//According to character,it founds how many changes place and changes there.
void Reversi::modify_new(int nRow, int nColumn, char find) {

  int i = 0, j = 0;
  bool oFound = false;
  bool inBoard = false;
  int value = 0;
  int sayac = 0;
  int tempRow = nRow;
  int tempColumn = nColumn;
  char me;
  Cell temp;

  if (find == 'X')
    me = 'O';
  else me = 'X';
//according to taking values ,it controls all ways respectively and 
    //counts cell 'O' or 'X' (ıt depends on user or computer)
        //then , until counter change living cell
  //right control

  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() + 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

  //left control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);

  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() - 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }
  //down control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn) {
          inBoard = true;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setRow(temp.getRow() + 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

  //up control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn) {
          inBoard = true;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setRow(temp.getRow() - 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

  //left up cross control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() - 1);
    temp.setRow(temp.getRow() - 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

  //left down cross control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn - 1) {
          inBoard = true;
          --tempColumn;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() + 1);
    temp.setRow(temp.getRow() + 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }


  //right up cross control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow - 1) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          --tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() + 1);
    temp.setRow(temp.getRow() - 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

  //right down cross control
  sayac = 0;
  value = 0;
  tempRow = nRow;
  tempColumn = nColumn;
  do {
    inBoard = false;
    for (i = 0; i < gameCell.size(); ++i) {
      for (j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == (tempRow + 1) && gameCell[i][j].getColumn() == tempColumn + 1) {
          inBoard = true;
          ++tempColumn;
          ++tempRow;
          if (gameCell[i][j].getCharWhose() == find) {
            oFound = true;
            sayac++;
          } else if (oFound && gameCell[i][j].getCharWhose() == me) {
            value = sayac;
            oFound = false;
          }
        }
      }
    }
  } while (oFound && inBoard);
  temp.setColumn(nColumn);
  temp.setRow(nRow);
  temp.setSymbol(me);
  //cout << temp.getCharWhose();
  for (int k = 1; k <= value; ++k) {
    temp.setColumn(temp.getColumn() + 1);
    temp.setRow(temp.getRow() + 1);
    for (int i = 0; i < gameCell.size(); ++i) {
      for (int j = 0; j < gameCell[i].size(); ++j) {
        if (gameCell[i][j].getRow() == temp.getRow() && gameCell[i][j].getColumn() == temp.getColumn())
          gameCell[i][j].setSymbol(temp.getCharWhose());
      }
    }
  }

}
//In this function, computer does best attack 
bool Reversi::computer_attack(bool control) {
  int counter = 0;
  int counter_1 = 0;
  Cell cmp;
  int max = 0;
  int temp = 0;
  int newRow, newColumn;
  for (int i = 0; i < getHeight(); ++i) {
    for (int j = 0; j < getWidth(); ++j) {
      counter = truth_control(i, j, 'O');
      //cout << "C :" << counter << " i: " << i << " j:" << j << endl;
      if (counter >= max) {
        max = counter;
        newRow = i;
        newColumn = j;
        cout<<i<<j<<endl;
      }
    }
  }

  if (max == 0)
    return false;
//If takes value -control- is false
  if(!control){
     //it fills Cell's object
  cmp.setRow(newRow);
  cmp.setColumn(newColumn);
  cmp.setSymbol('X');
  modify_new(newRow,newColumn,'O');
  cout<<"Add: "<<cmp.getRow()<<cmp.getColumn()<<endl;
  addCell(cmp);
  }
  
  //cout << endl << "Row : " << cmp.getRow() << "Column :" << cmp.getColumn() << endl;

  return true;
}
//This function is considered valid as main function
//This function calls user and computer game respectively
//This function takes board size
void Reversi::playGame() 
{
  int xCoordinate;
  int yCoordinate;
  int xWidth, yHeight;
  string column1;
  cout << "Please ,enter board size (form: Y*X(row-column))";
  cin >> yHeight>> xWidth;
  setWidth(xWidth);
  setHeight(yHeight);
  do {
      printBoard();
    cout << "Please, entry coordinate before row ,after column";
    cin >> yCoordinate>>column1;
    
    int col_int = (column1.length()-1)*26+ int(column1[0] - 'a');
    
    playUser(col_int, yCoordinate);
    computer_attack(false); // will draw board and add new cell 
  } while (finishGame(xCoordinate,yCoordinate) != true);
 
}
//This function take from user -x coordinate and y coordinate -
//this function use functions which definite upper part 
//It uses these functions:
//---Truth_control--- function
//-----------modify_new------ function
//-----------addCell--------- function
//If User entry false value 5 times,it turns computer 
void Reversi::playUser(int xCoordinate, int yCoordinate ) {
    int counter=0;
    //According to taking value from truth_control function
     int value=truth_control(yCoordinate,xCoordinate,'X');
     if(value>=1)
     {
         modify_new(yCoordinate,xCoordinate,'X');
         addCell(Cell(yCoordinate,xCoordinate,'O'));
         printBoard();
     }
     else
     {
         while(value<=0){
             string column1;
             
             int row1;
             cout<<"Please,entry coordinate before row,after column";
             cin>>row1;
             cin>>column1;
             
             int col_int = (column1.length()-1)*26+ int(column1[0] - 'a');
             
             value=truth_control(row1,col_int,'X');
             if(value>=1)
             {
                 modify_new(row1,col_int,'X');
                 addCell(Cell(row1,col_int,'O'));
             }
             else if(value<1)
                 counter++;
             else if(value<1 && counter==4)
             {
                 cout<<"You make fault more from 4";
                 value=1;
             }
         }
     }
   
}
//This function finishes game
bool Reversi::finishGame(int xCoordinate,int yCoordinate) {
    bool finish=false;
    if(truth_control(yCoordinate,xCoordinate,'X')==0 && computer_attack(true)== false)
        return finish =true;
      else
        return finish;
}
//This function add elements suitable place
void Reversi::addCell(const Cell& cell) {

    int addElementColumn=0;
    int addElementRow=0;
    bool found1=false;
   
    for(int i=0;i<gameCell.size();++i)
    {
        for(int j=0;j<gameCell[i].size();++j)
        {
            if(cell.getRow()==gameCell[i][j].getRow())
            {
                cout<<"asd--";
               if(!found1)
               {
                    if(cell.getColumn()<gameCell[i][j].getColumn() && j==0)
                    {
                        found1=true;
                        addElementColumn=j;
                        addElementRow=i;
                        cout<<"Control1 :"<<i<<j<<endl;


                    }else if(cell.getColumn()>gameCell[i][j].getColumn())
                    {
                        addElementColumn=j+1;
                        addElementRow=i;
                        cout<<"Control2 :"<<addElementRow<<addElementColumn<<endl;
                        if(gameCell[i].size()-1==j)
                            found1=true;

                    }
                    else found1=true;
                }  
            }
            else if(found1!=true && cell.getRow()!=gameCell[i][j].getRow())
            {
                if(cell.getRow()<gameCell[i][j].getRow() && i==0)
                {
                    cout<<"asdasd";
                    addElementRow=0;
                    found1=true;
                    
                }
                else 
                    addElementRow=gameCell.size();
            }
    
        }
    }
    
    //cout<<"Control3 : "<<addElementRow<<endl;

    if(found1==true)
    {
        cout<<"Control4 :"<<addElementRow<<addElementColumn<<endl;
                   gameCell[addElementRow].insert(gameCell[addElementRow].begin()+addElementColumn,cell);
    }
    else
    {
        vector<Cell> myNewRow;
        myNewRow.push_back(cell);
        gameCell.insert(gameCell.begin()+addElementRow,myNewRow);
        
    }
}
//This function take two parameter -objects- and compare objects
bool compareGame(const Reversi& firstGame,const Reversi& secondGame ) {
    bool value=false;
    int counter1=0;
    int counter2=0;
    for(int i=0;i<firstGame.gameCell.size();++i)
    {  
      for(int j=0;j<firstGame.gameCell[i].size();++j)
      {    
           if(firstGame.gameCell[i][j].getCharWhose()=='O')
               counter1++;
      }
    }
    for(int i=0;i<secondGame.gameCell.size();++i)
    {
        for(int j=0;j<secondGame.gameCell[i].size();++j)
        {
            if(secondGame.gameCell[i][j].getCharWhose()=='O')
                   counter2++;
        }
    }
      if(counter1>counter2)
           value=true;
      
     return value;
}