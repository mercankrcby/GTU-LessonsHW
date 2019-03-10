#include "cell.h"
#include <iostream>
using namespace std;

Cell::Cell(int newRow, int newColumn, char who) {
  setRow(newRow);
  setColumn(newColumn);
  setSymbol(who);
}

Cell::Cell() {
}

char Cell::getCharWhose() const {
  return symbol;
}

int Cell::getRow()const {
  return row;
}

int Cell::getColumn()const {
  return column;
}

void Cell::setColumn(int newColumn) {
  column = newColumn;
}

void Cell::setRow(int newRow) {
  row = newRow;
}

void Cell::setSymbol(char who) {
  symbol = who;
}
