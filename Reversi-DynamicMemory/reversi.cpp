/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "cell.h"
#include "reversi.h"
using namespace std;
////////////////////////////////BIG THREE////////////////////////////////////


namespace Mercan131044034 {
  //Constructorlar
  int Reversi::counterLivingReversi = 0;

  Reversi::Reversi() {
    const int size = 4;
    width = size;
    height = size;
    gameCells = new Cell[getHeight() * getWidth()];
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        gameCells[i + j + (width * i)].setRow(i);
        gameCells[i + j + (width * i)].setColumn(j);
        gameCells[i + j + (width * i)].setSymbol('.');
      }
    }
    gameCells[((height / 2) - 1) * width + (width / 2 - 1)].setSymbol('O');
    gameCells[((height / 2) - 1) * width + (width / 2)].setSymbol('X');
    gameCells[(height / 2) * width + (width / 2 - 1)].setSymbol('X');
    gameCells[(height / 2) * width + (width / 2)].setSymbol('O');
    counterLivingReversi++;
  }

  Reversi::Reversi(int nrow, int ncolumn) : width(ncolumn), height(nrow) {
    gameCells = new Cell[width * height];
    for (int i = 0; i <= height; ++i) {
      for (int j = 0; j <= width; ++j) {
        gameCells[j + (width * i)].setRow(i);
        gameCells[j + (width * i)].setColumn(j);
        gameCells[j + (width * i)].setSymbol('.');
      }
    }
    gameCells[((height / 2) - 1) * width + (width / 2) - 1].setSymbol('O');
    gameCells[((height / 2) - 1) * width + (width / 2)].setSymbol('X');
    gameCells[(height / 2) * width + (width / 2 - 1)].setSymbol('X');
    gameCells[(height / 2) * width + (width / 2)].setSymbol('O');
    counterLivingReversi++;
  }
  //Copy Constructor

  Reversi::Reversi(const Reversi& copyReversi) : width(copyReversi.width), height(copyReversi.height) {
    gameCells = new Cell[copyReversi.width * copyReversi.height];
    for (int i = 0; i < copyReversi.width * copyReversi.height; ++i)
      //ustte nasıl object den gelen degerleri memberlara yerlestirdiysek burada da 
      //aynı sekilde arrayin elemanlarını kopyaladık
      gameCells[i] = copyReversi.gameCells[i];

    counterLivingReversi++;
  }
  //Assignment Operatorunun Overloadu

  Reversi & Reversi::operator=(const Reversi & assignReversi) {
    if (assignReversi.getHeight() * assignReversi.getWidth() != getHeight() * getWidth()) {
      delete [] gameCells;
      gameCells = new Cell [assignReversi.getHeight() * assignReversi.getWidth()];
    }
    //her birinin degeri esitlenir
    height = assignReversi.height;
    width = assignReversi.width;

    //en son olarak da index esitlemeleri yapılır
    for (int i = 0; i < assignReversi.getHeight() * assignReversi.getWidth(); ++i)
      gameCells[i] = assignReversi.gameCells[i];

  }

  int Reversi::getWidth()const {
    return width;
  }

  int Reversi::getHeight()const {
    return height;
  }

  void Reversi::setWidth(int widthBoard) {
    width = widthBoard;
  }

  void Reversi::setHeight(int heightBoard) {
    height = heightBoard;
  }

  ostream& operator<<(ostream & outputStream, const Reversi & print) {
    outputStream << " ";
    for (int i = 0; i < print.getWidth(); ++i) {
      for (int j = 0; j <= (i / 26); ++j) {
        outputStream << char(i % 26 + 97);
      }
    }
    outputStream << endl;
    int k = 1;
    outputStream << k - 1;
    for (int i = 0; i < print.width * (print.height); ++i) {
      outputStream << print.gameCells[i].getCharWhose();
      if (i == ((print.width) * k) - 1) {
        outputStream << endl;

        ++k;
        if (k <= print.height)
          outputStream << k - 1;
      }

    }
    return outputStream;
  }

  void Reversi::playGame() {
    int xCoordinate;
    int yCoordinate;
    int xWidth, yHeight;
    int col_int;
    string column1;
    cout << (*this);
    resizeGame();
    Cell computerCell;
    do {

      cout << *this;
      cout << "Please, entry coordinate before row ,after column";
      cin >> yCoordinate>>column1;

      col_int = (column1.length() - 1)*26 + int(column1[0] - 'a');

      playUser(col_int, yCoordinate);
      playComputer(computerCell); // will draw board and add new cell 
    } while (true != finishGame(col_int, yCoordinate, computerCell));


  }

  void Reversi::playUser(int xCoordinate, int yCoordinate) {
    int counter = 0;
    int value = 0;


    //According to taking value from truth_control function
    value = truth_control(yCoordinate, xCoordinate);
    if (value >= 1) {
      modify_table(xCoordinate, yCoordinate, 1);
      cout << (*this);
    } else {
      while (value <= 0) {
        string column1;

        int row1;
        cout << "Please,entry coordinate before row,after column";
        cin>>row1;
        cin>>column1;

        int col_int = (column1.length() - 1)*26 + int(column1[0] - 'a');

        value = truth_control(row1, col_int);
        if (value >= 1) {
          modify_table(col_int, row1, 1);
          cout << (*this);
        } else if (value < 1)
          counter++;
        else if (value < 1 && counter == 4) {
          cout << "You make fault more from 4";
          value = 1;
        }
      }
    }

  }

  void Reversi::playComputer(Cell &computerCell) {
    computer_attack(computerCell);
    int computerColumn = computerCell.getColumn();
    int computerRow = computerCell.getRow();
    modify_table(computerColumn, computerRow, 0);
    cout << (*this);
  }

  bool Reversi::finishGame(int xCoordinate, int yCoordinate, Cell & computerCell) {

    if (truth_control(yCoordinate, xCoordinate) == 0 && computer_attack(computerCell) == 0)
      return true;
    else
      return false;
  }

  int Reversi::truth_control(int row_attack_no, int column_attack_no) {
    int nrow;
    int ncolumn;
    int i = 0, j = 0;
    nrow = row_attack_no;
    ncolumn = column_attack_no;
    int value = 0;
    //left control //
    if (((nrow * getWidth()) + ncolumn - 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn - 1) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn - 1].getCharWhose() == 'X') {
        for (int j = ncolumn; j > 0; --j) {
          // koordinat gecerli ise
          if (((nrow * getWidth()) + j) >= 0 &&
                  ((nrow * getWidth()) + j) < getHeight() * getWidth())
            if (gameCells[(nrow * getWidth()) + j].getCharWhose() == 'X') {
              if (((nrow * getWidth()) + j - 1) >= 0 &&
                      ((nrow * getWidth()) + j - 1) < getHeight() * getWidth())
                if (gameCells[(nrow * getWidth()) + j - 1].getCharWhose() == 'O')
                  value = 1;
            }
        }
      }

    //rigth control//
    if (((nrow * getWidth()) + ncolumn + 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn + 1) < getHeight() * getWidth())

      if (gameCells[(nrow * getWidth()) + ncolumn + 1].getCharWhose() == 'X') {

        for (int j = ncolumn; j < getWidth(); ++j) {

          if (((nrow * getWidth()) + j) >= 0 &&
                  ((nrow * getWidth()) + j) < getHeight() * getWidth())
            if (gameCells[(nrow * getWidth()) + j].getCharWhose() == 'X') {

              if (((nrow * getWidth()) + ncolumn + 1) >= 0 &&
                      ((nrow * getWidth()) + ncolumn + 1) < getHeight() * getWidth())
                if (gameCells[(nrow * getWidth()) + j + 1].getCharWhose() == 'O')
                  value = 1;
            }
        }
      }

    //up control
    if (((nrow * getWidth()) + ncolumn - width) >= 0 &&
            ((nrow * getWidth()) + ncolumn) - width < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn - width].getCharWhose() == 'X') {
        for (int j = nrow; j > 0; --j) {
          if (((j * getWidth()) + ncolumn) >= 0 &&
                  ((j * getWidth()) + ncolumn) < getHeight() * getWidth())
            if (gameCells[(j * getWidth()) + ncolumn].getCharWhose() == 'X') {
              if ((((j - 1) * getWidth()) + ncolumn) >= 0 &&
                      (((j - 1) * getWidth()) + ncolumn) < getHeight() * getWidth())
                if (gameCells[((j - 1) * getWidth()) + ncolumn].getCharWhose() == 'O')
                  value = 1;
            }
        }
      }
    //down control
    if ((((nrow + 1) * getWidth()) + ncolumn) >= 0 &&
            (((nrow + 1) * getWidth()) + ncolumn) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn + getWidth()].getCharWhose() == 'X') {
        for (int j = nrow; j < getHeight(); ++j) {
          if (((j * getWidth()) + ncolumn) >= 0 &&
                  ((j * getWidth()) + ncolumn) < getHeight() * getWidth())
            if (gameCells[((j) * getWidth()) + ncolumn].getCharWhose() == 'X') {
              if ((((j + 1) * getWidth()) + ncolumn) >= 0 &&
                      (((j + 1) * getWidth()) + ncolumn - 1) < getHeight() * getWidth())
                if (gameCells[((j + 1) * getWidth()) + ncolumn].getCharWhose() == 'O')
                  value = 1;
            }
        }
      }

    //left up cross control//
    if (((nrow * getWidth()) + ncolumn - width - 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn - width - 1) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn - width - 1].getCharWhose() == 'X') {
        for (i = nrow; i > 0; --i) {
          for (j = ncolumn; j > 0; --j) {
            if (((i * getWidth()) + j - width - 1) >= 0 &&
                    ((i * getWidth()) + + j - width - 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j - width - 1].getCharWhose() == 'X') {
                if (((i * getWidth()) + j - width - width - 2) >= 0 &&
                        ((i * getWidth()) + j - width - width - 2) < getHeight() * getWidth())
                  if (gameCells[((i) * getWidth()) + j - width - width - 2].getCharWhose() == 'O') {
                    value = 1;
                  }
              }
          }
        }
      }
    // left down
    if (((nrow * getWidth()) + ncolumn + width - 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn + width - 1) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn + width - 1].getCharWhose() == 'X') {
        for (i = nrow; i < getHeight(); ++i) {
          for (j = ncolumn; j > 0; --j) {
            if (((i * getWidth()) + j + width - 1) >= 0 &&
                    (((i * getWidth()) + j + width - 1) < getHeight() * getWidth()))
              if (gameCells[(i * getWidth()) + j + width - 1].getCharWhose() == 'X') {
                if ((((i) * getWidth()) + j + width + width - 2) >= 0 &&
                        ((((i) * getWidth()) + j + width + width - 2) < getHeight() * getWidth()))
                  if (gameCells[((i) * getWidth()) + j + width + width - 2].getCharWhose() == 'O') {
                    value = 1;
                  }
              }
          }
        }
      }
    // right down
    if (((nrow * getWidth()) + ncolumn + width + 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn + width + 1) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn + width + 1].getCharWhose() == 'X') {
        for (i = nrow; i < getHeight(); ++i) {
          for (j = ncolumn; j < getWidth(); ++j) {
            if (((i * getWidth()) + j + width + 1) >= 0 &&
                    ((i * getWidth()) + j + width + 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j + width + 1].getCharWhose() == 'X') {
                if ((((i) * getWidth()) + j + width + width + 2) >= 0 &&
                        (((i) * getWidth()) + j + width + width + 2) < getHeight() * getWidth())
                  if (gameCells[((i) * getWidth()) + j + width + width + 2].getCharWhose() == 'O') {
                    value = 1;
                  }
              }
          }
        }
      }

    // right up
    if (((nrow * getWidth()) + ncolumn - width + 1) >= 0 &&
            ((nrow * getWidth()) + ncolumn - width + 1) < getHeight() * getWidth())
      if (gameCells[(nrow * getWidth()) + ncolumn - width + 1].getCharWhose() == 'X') {
        for (i = nrow; i > 0; --i) {
          for (j = ncolumn; j < getWidth(); ++j) {
            if (((i * getWidth()) + j - width + 1) >= 0 &&
                    ((i * getWidth()) + j - width + 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j - width + 1].getCharWhose() == 'X') {
                if ((((i) * getWidth()) + j - width - width + 2) >= 0 &&
                        (((i) * getWidth()) + j - width - width + 2) < getHeight() * getWidth())

                  if (gameCells[((i) * getWidth()) + j - width - width + 2].getCharWhose() == 'O') {
                    value = 1;
                  }
              }
          }
        }
      }
    return value;
  }

  void Reversi::modify_table(int user_coordinate_x, int user_coordinate_y, int value) {
    char new_symbol;
    char old_symbol;
    //value=1 -> user 
    if (value == 1) {
      new_symbol = 'O';
      old_symbol = 'X';
    }//value=0 -> computer
    else if (value == 0) {
      new_symbol = 'X';
      old_symbol = 'O';

    }

    int ncolumn = user_coordinate_x;
    int nrow = user_coordinate_y;
    int counter = 0;
    bool location = false;

    //right control//
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn + 1].getCharWhose() == old_symbol) {
      for (int j = ncolumn; j < getWidth(); ++j) {
        if (gameCells[(nrow * getWidth()) + j].getCharWhose() == old_symbol) {
          counter++;
          if (gameCells[(nrow * getWidth()) + j + 1].getCharWhose() == new_symbol) {
            value = counter;
            location = true;
          }
        }
      }
    }

    // konum buldu o zaman eski konumdan oraya gidene kadar arttir k yi ve renk degis
    // k nin artis orani bazen +1 bazen alt satira inecek kadar bazen alt capraza gelecek kadardir
    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k <= (nrow * getWidth()) + ncolumn + value; ++k) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }

    //left control
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn - 1].getCharWhose() == old_symbol) {
      for (int j = ncolumn; j > 0; --j) {
        if (gameCells[(nrow * getWidth()) + j].getCharWhose() == old_symbol) {
          counter++;
          if (gameCells[(nrow * getWidth()) + j - 1].getCharWhose() == new_symbol) {
            value = counter;
            location = true;
          }
        }
      }
    }

    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k >= (nrow * getWidth()) + ncolumn - value; --k) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }


    //down control
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn + width].getCharWhose() == old_symbol) {
      for (int j = nrow; j < getHeight(); ++j) {
        if (gameCells[(j * getWidth()) + ncolumn].getCharWhose() == old_symbol) {
          counter++;
          if (gameCells[((j + 1) * getWidth()) + ncolumn].getCharWhose() == new_symbol) {
            value = counter;
            location = true;
          }
        }
      }
    }
    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k <= (nrow * getWidth()) + ncolumn + getWidth() * value; k += getWidth()) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }


    //up control
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn - width].getCharWhose() == old_symbol) {
      for (int j = nrow; j > 0; --j) {
        if (gameCells[(j * getWidth()) + ncolumn].getCharWhose() == old_symbol) {
          counter++;
          if (gameCells[((j - 1) * getWidth()) + ncolumn].getCharWhose() == new_symbol) {
            value = counter;
            location = true;
          }
        }
      }
    }

    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k >= (nrow * getWidth()) + ncolumn - getWidth() * value; k -= getWidth()) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }
    counter = 0;
    value = 0;

    // right up
    if (gameCells[(nrow * getWidth()) + ncolumn - width + 1].getCharWhose() == old_symbol) {
      for (int i = nrow; i > 0; --i) {
        for (int j = ncolumn; j < getWidth(); ++j) {
          if (gameCells[(i * getWidth()) + j - width + 1].getCharWhose() == old_symbol) {
            counter++;
            if (gameCells[((i) * getWidth()) + j - width - width + 2].getCharWhose() == new_symbol) {
              value = counter;
              location = true;
            }
          }
        }
      }
    }
    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k >= (nrow * getWidth()) + ncolumn - getWidth() * value + value; k = k - getWidth() + 1) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }

    //left up cross control//
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn - width - 1].getCharWhose() == old_symbol) {
      for (int i = nrow; i > 0; --i) {
        for (int j = ncolumn; j > 0; --j) {
          if (gameCells[(i * getWidth()) + j - width - 1].getCharWhose() == old_symbol) {
            counter++;
            if (gameCells[((i) * getWidth()) + j - width - width - 2].getCharWhose() == new_symbol) {
              location = true;
              value = counter;
            }
          }
        }
      }
    }
    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k >= (nrow * getWidth()) + ncolumn - getWidth() * value - value; k = k - getWidth() - 1) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }



    // right down
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn + width + 1].getCharWhose() == old_symbol) {
      for (int i = nrow; i < getHeight(); ++i) {
        for (int j = ncolumn; j < getWidth(); ++j) {
          if (gameCells[(i * getWidth()) + j + width + 1].getCharWhose() == old_symbol) {
            counter++;
            if (gameCells[((i) * getWidth()) + j + width + width + 2].getCharWhose() == new_symbol) {
              location = true;
              value = counter;
            }
          }
        }
      }
    }
    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k <= (nrow * getWidth()) + ncolumn + getWidth() * value + value; k = k + getWidth() + 1) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }


    // left down
    counter = 0;
    value = 0;
    if (gameCells[(nrow * getWidth()) + ncolumn + width - 1].getCharWhose() == old_symbol) {
      for (int i = nrow; i < getHeight(); ++i) {
        for (int j = ncolumn; j > 0; --j) {
          if (gameCells[(i * getWidth()) + j + width - 1].getCharWhose() == old_symbol) {
            counter++;
            if (gameCells[((i) * getWidth()) + j + width + width - 2].getCharWhose() == new_symbol) {
              location = true;
              value = counter;
            }
          }
        }
      }
    }

    if (location == true) {
      for (int k = ((nrow * getWidth()) + ncolumn); k <= (nrow * getWidth()) + ncolumn + getWidth() * value - value; k = k + getWidth() - 1) {
        gameCells[k].setSymbol(new_symbol);
      }
      location = false;
    }

  }

  int Reversi::computer_attack(Cell &computer) {

    int max = 0;
    int value = 0;
    int i;
    int j;
    int k;
    int max1 = 0;
    int found = 0;
    for (int t = 0; t < getWidth() * getHeight(); ++t) {
      int ncolumn = t % getWidth();
      int nrow = t / getHeight();
      max = 0;

      int counter1 = 0;

      //left control //
      if (((nrow * getWidth()) + ncolumn - 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn - 1) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn - 1].getCharWhose() == 'O') {
          for (int j = ncolumn; j > 0; --j) {

            // koordinat gecerli ise
            if (((nrow * getWidth()) + j) >= 0 &&
                    ((nrow * getWidth()) + j) < getHeight() * getWidth())
              if (gameCells[(nrow * getWidth()) + j].getCharWhose() == 'O') {
                counter1++;
                if (((nrow * getWidth()) + j - 1) >= 0 &&
                        ((nrow * getWidth()) + j - 1) < getHeight() * getWidth())
                  if (gameCells[(nrow * getWidth()) + j - 1].getCharWhose() == 'X') {
                    max = max + counter1;
                  }
              }
          }
        }

      //right control//
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn + 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn + 1) < getHeight() * getWidth())

        if (gameCells[(nrow * getWidth()) + ncolumn + 1].getCharWhose() == 'O') {

          for (int j = ncolumn; j < getWidth(); ++j) {

            if (((nrow * getWidth()) + j) >= 0 &&
                    ((nrow * getWidth()) + j) < getHeight() * getWidth())
              if (gameCells[(nrow * getWidth()) + j].getCharWhose() == 'O') {
                counter1++;
                if (((nrow * getWidth()) + ncolumn + 1) >= 0 &&
                        ((nrow * getWidth()) + ncolumn + 1) < getHeight() * getWidth())
                  if (gameCells[(nrow * getWidth()) + j + 1].getCharWhose() == 'X')
                    max = max + counter1;
              }
          }
        }

      //up control
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn - width) >= 0 &&
              ((nrow * getWidth()) + ncolumn) - width < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn - width].getCharWhose() == 'O') {
          for (int j = nrow; j > 0; --j) {
            if (((j * getWidth()) + ncolumn) >= 0 &&
                    ((j * getWidth()) + ncolumn) < getHeight() * getWidth())
              if (gameCells[(j * getWidth()) + ncolumn].getCharWhose() == 'O') {
                counter1++;
                if ((((j - 1) * getWidth()) + ncolumn) >= 0 &&
                        (((j - 1) * getWidth()) + ncolumn) < getHeight() * getWidth())
                  if (gameCells[((j - 1) * getWidth()) + ncolumn].getCharWhose() == 'X')
                    max = max + counter1;
              }
          }
        }
      //down control
      counter1 = 0;
      if ((((nrow + 1) * getWidth()) + ncolumn) >= 0 &&
              (((nrow + 1) * getWidth()) + ncolumn) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn + getWidth()].getCharWhose() == 'O') {
          for (int j = nrow; j < getHeight(); ++j) {
            if (((j * getWidth()) + ncolumn) >= 0 &&
                    ((j * getWidth()) + ncolumn) < getHeight() * getWidth())
              if (gameCells[((j) * getWidth()) + ncolumn].getCharWhose() == 'O') {
                counter1++;
                if ((((j + 1) * getWidth()) + ncolumn) >= 0 &&
                        (((j + 1) * getWidth()) + ncolumn - 1) < getHeight() * getWidth())
                  if (gameCells[((j + 1) * getWidth()) + ncolumn].getCharWhose() == 'X')
                    max = max + counter1;
              }
          }
        }

      //left up cross control//
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn - width - 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn - width - 1) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn - width - 1].getCharWhose() == 'O') {
          int i = nrow;
          int j = ncolumn;
          while (i > 0 && j > 0) {
            if (((i * getWidth()) + j - width - 1) >= 0 &&
                    ((i * getWidth()) + + j - width - 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j - width - 1].getCharWhose() == 'O') {
                counter1++;
                if (((i * getWidth()) + j - width - width - 2) >= 0 &&
                        ((i * getWidth()) + j - width - width - 2) < getHeight() * getWidth())
                  if (gameCells[((i) * getWidth()) + j - width - width - 2].getCharWhose() == 'X') {
                    max = max + counter1;
                  }
              }
            --i;
            --j;
          }
        }
      // left down
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn + width - 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn + width - 1) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn + width - 1].getCharWhose() == 'O') {
          int i = nrow;
          int j = ncolumn;
          while (i < getHeight() && j > 0) {
            if (((i * getWidth()) + j + width - 1) >= 0 &&
                    (((i * getWidth()) + j + width - 1) < getHeight() * getWidth()))
              if (gameCells[(i * getWidth()) + j + width - 1].getCharWhose() == 'O') {
                counter1++;
                if ((((i) * getWidth()) + j + width + width - 2) >= 0 &&
                        ((((i) * getWidth()) + j + width + width - 2) < getHeight() * getWidth()))
                  if (gameCells[((i) * getWidth()) + j + width + width - 2].getCharWhose() == 'X') {
                    max = max + counter1;
                  }
              }
            ++i;
            --j;
          }
        }
      // right down
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn + width + 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn + width + 1) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn + width + 1].getCharWhose() == 'O') {
          int i = nrow;
          int j = ncolumn;
          while (i < getHeight() && j < getWidth()) {
            if (((i * getWidth()) + j + width + 1) >= 0 &&
                    ((i * getWidth()) + j + width + 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j + width + 1].getCharWhose() == 'O') {
                counter1++;
                if ((((i) * getWidth()) + j + width + width + 2) >= 0 &&
                        (((i) * getWidth()) + j + width + width + 2) < getHeight() * getWidth())
                  if (gameCells[((i) * getWidth()) + j + width + width + 2].getCharWhose() == 'X') {
                    max = max + counter1;
                  }
              }
            ++i;
            ++j;
          }

        }

      // right up
      counter1 = 0;
      if (((nrow * getWidth()) + ncolumn - width + 1) >= 0 &&
              ((nrow * getWidth()) + ncolumn - width + 1) < getHeight() * getWidth())
        if (gameCells[(nrow * getWidth()) + ncolumn - width + 1].getCharWhose() == 'O') {
          int i = nrow;
          int j = ncolumn;
          while (i >= 0 && j < getWidth()) {
            if (((i * getWidth()) + j - width + 1) >= 0 &&
                    ((i * getWidth()) + j - width + 1) < getHeight() * getWidth())
              if (gameCells[(i * getWidth()) + j - width + 1].getCharWhose() == 'O') {
                counter1++;
                if ((((i) * getWidth()) + j - width - width + 2) >= 0 &&
                        (((i) * getWidth()) + j - width - width + 2) < getHeight() * getWidth())

                  if (gameCells[((i) * getWidth()) + j - width - width + 2].getCharWhose() == 'X') {
                    max = max + counter1;
                  }
              }
            --i;
            ++j;
          }
        }
      if (max != 0)
        value = 1;
      if (max >= max1) {
        cout << "ZZ-" << t << "-" << max << "-ZZ" << endl;
        max1 = max;
        computer.setColumn(ncolumn);
        computer.setRow(nrow);
      }

    }
    return value;
  }

  void Reversi::resizeGame() {
    cout << "Would you want update to table and start again" << endl;
    cout << "If it Okey ,'O' ,is not No 'N' ";
    char character;
    cin>>character;
    if (character == 'O') {
      cout << "Please ,enter new size 'before row, after column'";
      int newSizeRow, newSizeColumn;
      cin >> newSizeRow>>newSizeColumn;
      int newSize = newSizeRow*newSizeColumn;
      setHeight(newSizeRow);
      setWidth(newSizeColumn);
      delete []gameCells;

      gameCells = new Cell[newSize];
      for (int i = 0; i < newSizeRow; ++i) {
        for (int j = 0; j < newSizeColumn; ++j) {
          gameCells[j + (newSizeColumn * i)].setRow(i);
          gameCells[j + (newSizeColumn * i)].setColumn(j);
          gameCells[j + (newSizeColumn * i)].setSymbol('.');
        }
      }
      gameCells[((newSizeRow / 2) - 1) * newSizeColumn + (newSizeColumn / 2) - 1].setSymbol('X');
      gameCells[((newSizeRow / 2) - 1) * newSizeColumn + (newSizeColumn / 2)].setSymbol('O');
      gameCells[(newSizeRow / 2) * newSizeColumn + (newSizeColumn / 2 - 1)].setSymbol('O');
      gameCells[(newSizeRow / 2) * newSizeColumn + (newSizeColumn / 2)].setSymbol('X');
    }
  }

  Reversi Reversi::operator++() {
    Cell newComputerAttack;
    playComputer(newComputerAttack);
  }

  Reversi::~Reversi() {
    //delete [] gameCells;
    --counterLivingReversi;
  }

  bool compareGame(const Reversi & firstGame, const Reversi &secondGame) {
    int counterFirst = 0;
    int counterSecond = 0;
    for (int i = 0; i < firstGame.getHeight() * firstGame.getWidth(); ++i) {
      if (firstGame.gameCells[i].getCharWhose() == 'O')
        ++counterFirst;

    }
    for (int i = 0; i < secondGame.getHeight() * secondGame.getWidth(); ++i) {
      if (secondGame.gameCells[i].getCharWhose() == 'O')
        ++counterSecond;

    }
    if (counterFirst > counterSecond)
      return true;
    else
      return false;

  }

  int Reversi::counterOfLivingCell() {
    return counterLivingReversi;
  }
}