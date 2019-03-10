#ifndef CELL_H
#define CELL_H

using std::ostream;
using std::istream;

class Cell{
public:
    Cell();
    Cell(int newRow,int newColumn,char who);
    char getCharWhose()const;
    int getRow()const;
    int getColumn()const;
    void setSymbol(char karakter);
    void setColumn(int newColumn);
    void setRow(int newRow);
    void input();
    friend bool operator ==(const Cell &firstCell,const Cell &secondCell);
    friend bool operator >(const Cell &firstCell,const Cell &secondCell);
    friend bool operator <(const Cell &firstCell,const Cell &secondCell);
    friend bool operator >=(const Cell &firstCell,const Cell &secondCell);
    friend bool operator <=(const Cell &firstCell,const Cell &secondCell);
    friend bool operator !=(const Cell &firstCell,const Cell &secondCell);
    Cell operator++();
    Cell operator++(int value);
    friend istream& operator >>(istream& inputStream,Cell &inpCell);
    friend ostream& operator <<(ostream& outputStream,const Cell &outpCell);
private:
    char symbol;
    int row;
    int column;
};

#endif // CELL_H
