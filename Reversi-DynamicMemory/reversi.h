/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reversi.h
 * Author: mercankaracabey
 * No:131044034
 * Created on 02 Aralık 2015 Çarşamba, 22:27
 */

#ifndef REVERSI_H
#define REVERSI_H

namespace Mercan131044034{

class Reversi{
public:
    //Constructors
    Reversi();
    Reversi(int nRow,int nColumn);
    ////BIG THREE////
    //Copy Constructor
    Reversi(const Reversi &copyReversi);
    //Assignment Operators Overload
    Reversi & operator=(const Reversi & assignReversi);
    //Destructor
    ~Reversi();
    
    ////GETTERS & SETTERS////
    int getWidth()const ;
    int getHeight()const;
    void setWidth(int widthBoard);
    void setHeight(int heightBoard);
    
    //Kullanici maini diyebiliriz//
    //***Kullanicidan aldigi degerleri truth controle yollayarak oradan gelen///
    //degere gore -0/1- value degeri alarak 5 kez yanlis yapmasi ihtimalinde ///
    //hamle sirasi bilgisayara gecer ***///
    void playUser(int xCoordinate,int yCoordinate);
    
    
    //***Oyunun dondurulme mekanizmasi bu fonksiyon uzerindedir ///
    //bir nevi main fonksiyonu da diyebiliriz*** ///
    void playGame();//oyunun maini farzedilebilir
    
    
    //Bilgisayar maini diyebiliriz//
    //***Bilgisayar icin en iyi hamleyi bularak yollanan Cell hucresinin icine
    //yazar daha sonra da ekrana basar*** //
    void playComputer(Cell &computerCell);
    
    
    //Tum oyunlardaki 'Canli' -X- -O- hucre sayisini bularak return eder
    static int counterOfLivingCell();
    
    
    //***Oynanmis Reversi oyunlarini karsilastirir birinci oyun icin kullanici
    // ondeyse TRUE dondurur, diger durumlar icin false dondurur ***///
    friend bool compareGame(const Reversi & firstGame,const Reversi &secondGame);
    
    
    //*** Kullanicidan alinan degerlerin uygun olup olmadigini bakarak
    //0 ya da 1 return eder ***//
    int truth_control(int row_attack_no,int column_attack_no);
    
    
    
    //***Bilgisayar icin en iyi hamleyi bulur ve Cell hucresinin icine yazar///
    int computer_attack(Cell &computer);
    
    
    
    //*** computer_attack ve truth controlden gelen degerlere bagli olarak
    //oyunu bitirir ***//
    bool finishGame(int xCoordinate,int yCoordinate,Cell& computerCell) ;
    
    
    
    //mevcut tabloyu ekrana basar ***//
    friend std::ostream& operator<<(std::ostream& os,const Reversi& game);
    
    
    
    //***Aldigi value degerine bagli olarak kullanicidan mi bilgisayardan mi hamle
    //aldigina bakarak tabloyu gunceller ***//
    void modify_table(int user_coordinate_x,int user_coordinate_y,int value);
    
    
    
    //***Kullaniciya mevcut tablodan mı devam edilmesi gerektigini ya da
    //istedigi tabloyu sorarak o olculere gore tablonun boyutunu ayarlar***//
    void resizeGame();
    
    
    
    //***Ust uste iki kez bilgisayar hamlesi yapilmasini saglar***//
    Reversi operator++();
    
private:
    int width;
    int height;
    Cell * gameCells;
    static int counterLivingReversi;
};


}

#endif /* REVERSI_H */

