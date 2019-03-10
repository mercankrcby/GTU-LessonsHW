#ifndef REVERSI_H
#define REVERSI_H

class Reversi{
public:
    Reversi(); 
    Reversi(int nRow,int nColumn); 
    void readFile(const char *fname);
    void writeFile();
    int getWidth()const ; 
    int getHeight()const; 
    void setWidth(int widthBoard); 
    void setHeight(int heightBoard);
    void printBoard()const; 
    void playUser(int xCoordinate,int yCoordinate);
    void playGame();//oyunun maini farzedilebilir
    static int counterOfLivingCell();
    friend bool compareGame(const Reversi & firstGame,const Reversi &secondGame);
    
private:
    int truth_control(int row,int column,char find) const;
    bool computer_attack(bool control);
    int computerTruthControl(int yRow,int xColumn); 
    void modify_new(int nRow,int nColumn,char find);
    bool finishGame(int xCoordinate,int yCoordinate) ;
    void addCell(const Cell& cell);
    int width;
    int height;
    std::vector<std::vector<Cell> > gameCell;
};

#endif // REVERSI_H
