/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cell.h
 * Author: mercankaracabey
 *
 * Created on 02 Aralık 2015 Çarşamba, 22:26
 */

#ifndef CELL_H
#define CELL_H

namespace Mercan131044034 {
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
    friend bool operator==(const Cell &firstCell,const Cell &secondCell);
private:
    char symbol;
    int row;
    int column;
};
}
#endif /* CELL_H */

