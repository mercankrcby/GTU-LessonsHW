/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mainreversi.cpp
 * Author: mercankaracabey
 *
 * Created on 03 Aralık 2015 Perşembe, 09:37
 */
#include <iostream>
#include <string>
#include "cell.h"
#include "reversi.h"
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  using namespace Mercan131044034;

    Reversi game1(8,6); 

    game1.playGame();

    Reversi game2(10,10);
    game2.playGame();
    bool whichOne;
    whichOne=compareGame(game1,game2);
    if(whichOne==true)
        cout<<"First game better than second ,for user";
    cout<<"Count of living cell"<<game1.counterOfLivingCell();
    
    game2=game1;
    cout<<"Move from game1 to game2";
    cout<<game2;
    
    Reversi game3(5,5);
    Reversi game4(game3);

    return 0;
}

