#ifndef CELL_H
#define CELL_H
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
private:
    char symbol;
    int row;
    int column;
};

#endif // CELL_H
