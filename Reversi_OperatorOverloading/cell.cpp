
#include<iostream>
#include "cell.h"
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
bool operator ==(const Cell &firstCell,const Cell &secondCell)
{
    return (firstCell.getRow()==secondCell.getRow() &&
                    firstCell.getColumn()==secondCell.getColumn());
}
bool operator >(const Cell &firstCell,const Cell &secondCell)
{
    bool value=true;
    if(firstCell.getRow()> secondCell.getRow())
        return value;
    else if(firstCell.getRow()== secondCell.getRow())
    {
        if(firstCell.getColumn()>secondCell.getColumn())
            return value;
    }
    else 
         value=false;
    
    return value;
}
bool operator <(const Cell &firstCell,const Cell &secondCell)
{
    bool value=true;
    if(firstCell.getRow()<secondCell.getRow())
        return value;
    else if(firstCell.getRow()== secondCell.getRow())
    {
        if(firstCell.getColumn()<secondCell.getColumn())
            return value;
    }
    else 
        value=false;
    
    return value;
}
bool operator >=(const Cell &firstCell,const Cell &secondCell)
{
    bool value=true;
    if(firstCell.getRow()>=secondCell.getRow())
        return value;
    else if(firstCell.getRow()==secondCell.getRow())
    {
        if(firstCell.getColumn()>=secondCell.getColumn())
            return value;
    }
    else 
        value=false;
    
    return value;
}
bool operator <=(const Cell &firstCell,const Cell &secondCell)
{
    bool value=true;
    if(firstCell.getRow()<=secondCell.getRow())
        return value;
    else if(firstCell.getRow()==secondCell.getRow())
    {
        if(firstCell.getColumn()<=secondCell.getColumn())
            return value;
    }
    else
        value=false;
    
    return value;
}
bool operator !=(const Cell &firstCell,const Cell &secondCell)
{
    return(firstCell.getRow()!=secondCell.getRow() && firstCell.getColumn()!=secondCell.getColumn());
}
Cell Cell::operator++()
{
    return Cell(++row,++column,symbol);

}
Cell Cell::operator++(int value)
{
    return Cell(row++,column++,symbol);
}

istream& operator>>(istream& inputStream,Cell &inpCell)
{
    int rowy,columnx;
    cout<<"Enter values for cell (row ,column)";
    inputStream>>rowy>>columnx;
    inpCell.setRow(rowy);
    inpCell.setColumn(columnx);
    return inputStream; 
}
ostream& operator<< (ostream& outputStream,const Cell &outpCell)
{
    outputStream<<outpCell.getRow()<<" "<<outpCell.getColumn();
    return outputStream;
}

