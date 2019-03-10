#include "cell.h"
#include <iostream>
using namespace std;

namespace Mercan131044034{

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
bool operator ==(const Cell &firstCell,const Cell &secondCell)
{
    return (firstCell.getRow()==secondCell.getRow() &&
                    firstCell.getColumn()==secondCell.getColumn());
}

}