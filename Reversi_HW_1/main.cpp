#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
//array's dimension
const int ROW_MAX = 20;

//functions prototypes
int truth_control(char play_table[][ROW_MAX], int row, int column, int row_attack_no, int column_attack_no);
int filled_control(char play_table[][ROW_MAX], int row, int column, int false_counter);
void finish_function(char play_table[][ROW_MAX], int row, int column);
void modify_table(char play_table[][ROW_MAX], int row, int column, int user_coordinate_x, int user_coordinate_y, int value);
void print_table(char play_table[][ROW_MAX], int row, int column);
void computer_attack(char play_table[][ROW_MAX], int row, int column, int *computer_attack_x, int *computer_attack_y);

int main() {

  char play_table[20][20]; // max 20-20 lik  ama degeri asagıda degisir
  int column = 0;
  int row = 0;
  char entered_value;
  do {
    //Inseption of game 
    cout << "Hello,Would you want to play Reversi Game  ?\n";
    cout << "If you want to play , you would enter 'E' \n";
    cout << "If you don't want to play ,you would enter 'H' ";

    cin>> entered_value;
    if (entered_value == 'E' || entered_value == 'e') {
      int table_value;
      do {
        cout << "You enter table value for playing game(you should choose even number)";
        cin>>table_value;
        if (table_value % 2 == 0 && table_value >= 4 && table_value <= ROW_MAX) {
          column = row = table_value;
          int i;
          int j;
          int a = 1;
          // fill table
          for (i = 0; i < row; ++i)
            for (j = 0; j < column; ++j)
              play_table[i][j] = '.';

          play_table[row / 2 - 1][column / 2 - 1] = 'X';
          play_table[(row / 2)][column / 2 - 1] = 'O';
          play_table[row / 2 - 1][(column / 2)] = 'O';
          play_table[(row / 2)][(column / 2)] = 'X';

          print_table(play_table, row, column);


          int last_control;
          int row_attack_no = 0;
          int column_attack_no = 0;
          int false_counter = 0;
          do {
            int row_at=0;
            char column_at;
            cout << "You should do attack\n";
            cout << "You should your attack as row and column number from keyboard";
            cout<<"\nEnter row number > ";
            cin>>row_at;
            cout<<"Enter column like a-b-c(lower case) >";
            cin>>column_at;


            int control;
            row_attack_no = row_at-1;
            column_attack_no = static_cast<int> (column_at) - 97;

            cout << row_attack_no << "-" << column_attack_no << endl;
            int computer_attack_x = 0;
            int computer_attack_y = 0;
            //If user does 5 wrong attack ,this program will finish
            control = truth_control(play_table, row, column, row_attack_no, column_attack_no);
            //giving value == 1 , calls function and game goes on                                                                        
            if (control == 1) {
              int value = 1;
              modify_table(play_table, row, column, row_attack_no, column_attack_no, value);
              print_table(play_table, row, column);

              //Value is 0 because modify_table 's values will edit and change 
              value = 0;
              computer_attack(play_table, row, column, &computer_attack_x, &computer_attack_y);
              modify_table(play_table, row, column, computer_attack_x, computer_attack_y, value);
              print_table(play_table, row, column);
              //for computer attack's control
              cout << computer_attack_x << " " << computer_attack_y << endl;
              false_counter = 0;
            } else {

              cout << "You did wrong attack ,try again";
              false_counter++;
            }

            last_control = filled_control(play_table, row, column, false_counter);
          } while (last_control < 1);
          finish_function(play_table, row, column);
        }
      } while (table_value > 3);
      cout << "You entered wrong number value ,please you try to enter values bigger than four";
    }
  } while (entered_value == 'E' || entered_value == 'e');

  return 0;

}
// This function controls array .If array fills or they do wrong attack more than 5, return value will be 0 and program will finish 

int filled_control(char play_table[][ROW_MAX], int row, int column, int false_counter) {
  int counter = 0;
  int all_value = 0;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      if (play_table[i][j] == 'X' || play_table[i][j] == 'O')
        ++counter;

  all_value = row*column;
  if (all_value == counter || false_counter == 5)
    return 1;
  else
    return 0;
}
//When game finished,it says that who won and print the screen

void finish_function(char play_table[][ROW_MAX], int row, int column) {
  int x_counter = 0;
  int o_counter = 0;
  //It looks which character more than the other
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      if (play_table[i][j] == 'X')
        x_counter++;
      else if (play_table[i][j] == 'O')
        o_counter++;
    }
  }
  cout << x_counter << " - " << o_counter << endl;

  if (x_counter > o_counter)
    cout << "Computer won";
  else
    cout << "Player won";
}
//the function looks it's right,left,up,down,right up,left up,left down ,right down and counts 'o'characters.
//If which counter more than the other, it attacks there.

void computer_attack(char play_table[][ROW_MAX], int row, int column, int *computer_attack_x, int *computer_attack_y) {

  int max = 0;

  int i;
  int j;
  int k;
  int max1 = 0;
  for (i = 0; i < row; ++i) {
    for (j = 0; j < column; ++j) {
      max = 0;
      if (play_table[i][j] == '.') {

        //right control//
        int counter1 = 0;
        for (k = j + 1; k < column; k++) {
          if (play_table[i][k] != '.')
            if (play_table[i][k] == 'O') {
              counter1++;
              if (play_table[i][k + 1] == 'X') {
                max = max + counter1;
              }
            }
        }
        //left control//
        int counter2 = 0;
        for (k = j - 1; k > 0; --k) {
          if (play_table[i][k] != '.')
            if (play_table[i][j] == 'O') {
              counter2++;
              if (play_table[i][j - 1] == 'X') {
                max = max + counter2;
              }
            }
        }
        //down control//
        int counter3 = 0;
        for (k = i + 1; k < row; ++k) {
          if (play_table[k][j] != '.')
            if (play_table[k][j] == 'O') {
              counter3++;
              if (play_table[k + 1][j] == 'X') {
                max = max + counter3;
              }
            }
        }
        //up kontrol//
        int counter4 = 0;
        for (k = i - 1; k > 0; --k) {
          if (play_table[k][j] != '.')
            if (play_table[k][j] == 'O') {
              counter4++;
              if (play_table[k - 1][j] == 'X') {
                max = max + counter4;
              }
            }
        }

        //right-up cross//
        int counter5 = 0;
        int temple_variable1;
        int temple_variable2;
        temple_variable1 = i;
        temple_variable2 = j;
        while (temple_variable1 > 0 && temple_variable2 < column) {

          if (play_table[temple_variable1 - 1][temple_variable2 + 1] == 'O') {
            counter5++;
            if (play_table[temple_variable1 - 2][temple_variable2 + 2] == 'X') {
              max = max + counter5;
            }

          }
          temple_variable1--;
          temple_variable2++;

        }
        //right-down cross//
        int counter6 = 0;
        int temple_variable3;
        int temple_variable4;
        temple_variable3 = i;
        temple_variable4 = j;
        while (temple_variable3 < row && temple_variable4 < column) {

          if (play_table[temple_variable3 + 1][temple_variable4 + 1] == 'O') {
            counter6++;
            if (play_table[temple_variable3 + 2][temple_variable4 + 2] == 'X') {
              max = max + counter6;
            }

          }
          temple_variable3++;
          temple_variable4++;
        }
        //left-down cross//

        int counter7 = 0;
        int temple_variable5;
        int temple_variable6;
        temple_variable5 = i;
        temple_variable6 = j;
        while (temple_variable5 < row && temple_variable6 >= 0) {

          if (play_table[temple_variable5 + 1][temple_variable6 - 1] == 'O') {
            counter7++;
            if (play_table[temple_variable5 + 2][temple_variable6 - 2] == 'X') {
              max = max + counter7;
            }
          }

          temple_variable5++;
          temple_variable6--;
        }

        //left-up cross//
        int counter8 = 0;
        int temple_variable7;
        int temple_variable8;
        temple_variable7 = i;
        temple_variable8 = j;
        while (temple_variable7 >= 0 && temple_variable8 >= 0) {

          if (play_table[temple_variable7 - 1][temple_variable8 - 1] == 'O') {
            counter8++;
            if (play_table[temple_variable7 - 2][temple_variable8 - 2] == 'X') {
              max = max + counter8;
            }
          }

          temple_variable7--;
          temple_variable8--;
        }
        //			if(i==3 && j==1)
        //			cerr<<sayac1<<sayac2<<sayac3<<sayac4<<sayac5<<sayac6<<sayac7<<sayac8<<endl;

      }

      /*	if(i==5 && j==2)
        {

          cerr<<max1;
        }

       */
      //cerr<<"İ:"<<i<<"J:"<<j<<"Max:"<<max<<endl;
      if (max >= max1) {
        max1 = max;
        *computer_attack_x = i;
        *computer_attack_y = j;
      }
      /*
            if(max1==4)
            {
              cerr<<i<<"a"<<j<<endl;
            }
       */
      max = 0;
    }
  }

}
//It controls user's entering value 
//It controls right,left,up,down,right up ,right down ,left down ,left up 

int truth_control(char play_table[][ROW_MAX], int row, int column, int row_attack_no, int column_attack_no) {
  int temple_x;
  int temple_y;
  int i = 0, j = 0;
  temple_x = row_attack_no;
  temple_y = column_attack_no;
  int value = 0;
  //left control //
  if (play_table[temple_x][temple_y - 1] == 'X') {
    for (j = temple_y - 1; j > 0; --j) {
      if (play_table[temple_x][j] == 'X') {
        if (play_table[temple_x][j - 1] == 'O')
          value = 1;
      }
    }
  }
  //right control//
  if (play_table[temple_x][temple_y + 1] == 'X') {
    for (j = temple_y + 1; j < column; ++j) {
      if (play_table[temple_x][j] == 'X') {
        if (play_table[temple_x][j + 1] == 'O') {
          value = 1;
        }
      }
    }
  }
  //up control//
  if (play_table[temple_x - 1][temple_y] == 'X') {
    for (j = temple_x - 1; j > 0; --j) {
      if (play_table[j][temple_y] == 'X') {
        if (play_table[j - 1][temple_y] == 'O') {
          value = 1;
        }
      }
    }
  }
  //down control//
  if (play_table[temple_x + 1][temple_y] == 'X') {
    for (j = temple_x + 1; j < row; ++j) {
      if (play_table[j][temple_y] == 'X') {
        if (play_table[j + 1][temple_y] == 'O') {
          value = 1;
        }
      }
    }
  }
  //left up cross control//
  if (play_table[temple_x - 1][temple_y - 1] == 'X') {
    for (i = temple_x - 1; i > 0; --i) {
      for (j = temple_y - 1; j > 0; --j) {
        if (play_table[i][j] == 'X') {
          if (play_table[i - 1][j - 1] == 'O') {
            value = 1;
          }
        }
      }
    }
  }
  //right down cross control//
  if (play_table[temple_x + 1][temple_y + 1] == 'X') {
    for (i = temple_x + 1; i < row; ++i) {
      for (j = temple_y + 1; j < column; ++j) {
        if (play_table[i][j] == 'X') {
          if (play_table[i + 1][j + 1] == 'O') {
            value = 1;
          }
        }
      }
    }
  }
  //right up cross control//
  if (play_table[temple_x - 1][temple_y + 1] == 'X') {
    for (i = temple_x - 1; i > 0; --i) {
      for (j = temple_y + 1; j < column; ++j) {
        if (play_table[i][j] == 'X') {
          if (play_table[i - 1][j + 1] == 'O') {
            value = 1;
          }
        }
      }
    }
  }
  //left down cross control
  if (play_table[temple_x + 1][temple_y - 1] == 'X') {
    for (i = temple_x + 1; i < row; ++i) {
      for (j = temple_y - 1; j > 0; --j) {
        if (play_table[i][j] == 'X') {
          if (play_table[i + 1][j - 1] == 'O') {
            value = 1;
          }
        }
      }
    }
  }

  return value;
}
//It changes character according to giving value ( user or computer)

void modify_table(char play_table[][ROW_MAX], int row, int column, int user_coordinate_x, int user_coordinate_y, int value) {
  char new_symbol;
  char old_symbol;
  //value=1 -> user 
  if (value == 1) {
    new_symbol = 'O';
    old_symbol = 'X';
  }    //value=0 -> computer
  else if (value == 0) {
    new_symbol = 'X';
    old_symbol = 'O';

  }
  int i;
  int j;
  i = user_coordinate_x;
  j = user_coordinate_y;
  int counter = 0;
  int location = 0;
  //right control
  if (play_table[i][j + 1] == old_symbol) {
    for (j = user_coordinate_y + 1; j <= row; ++j) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i][j + 1] == new_symbol) {
          location = 1;
        }
      }
    }
  }
  //If it states true position
  if (location == 1) {
    for (int k = user_coordinate_y; k <= user_coordinate_y + counter; ++k) {
      play_table[i][k] = new_symbol;
    }
    location = 0;
  }
  counter = 0;
  //left control
  j = user_coordinate_y;
  if (play_table[i][j - 1] == old_symbol) {
    for (j = user_coordinate_y - 1; j >= 0; --j) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i][j - 1] == new_symbol) {
          location = 1;
        }
      }
    }
  }
  if (location == 1) {
    for (int k = user_coordinate_y - counter; k <= user_coordinate_y; ++k) {
      play_table[i][k] = new_symbol;
    }
    location = 0;
  }
  counter = 0;
  //down control
  j = user_coordinate_y;
  if (play_table[i + 1][j] == old_symbol) {
    for (i = user_coordinate_x + 1; i < row; ++i) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i + 1][j] == new_symbol) {
          location = 1;
        }
      }
    }
  }
  if (location == 1) {
    for (int k = user_coordinate_x; k <= user_coordinate_x + counter; ++k) {
      play_table[k][j] = new_symbol;
    }
    location = 0;
  }
  counter = 0;
  //up control
  i = user_coordinate_x;
  if (play_table[i - 1][j] == old_symbol) {
    for (i = user_coordinate_x - 1; i >= 0; --i) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i - 1][j] == new_symbol) {
          location = 1;
        }
      }
    }
  }
  if (location == 1) {
    for (int k = user_coordinate_x - counter; k <= user_coordinate_x; ++k) {
      play_table[k][j] = new_symbol;
    }
    location = 0;
  }
  counter = 0;
  //right up cross control
  i = user_coordinate_x;
  j = user_coordinate_y;
  if (play_table[i - 1][j + 1] == old_symbol) {
    i = user_coordinate_x - 1;
    j = user_coordinate_y + 1;
    while (i >= 0 && j < column) {
      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i - 1][j + 1] == new_symbol) {
          location = 1;
        }
      }
      --i;
      ++j;
    }

  }
  if (location == 1) {
    int k = user_coordinate_x;
    int l = user_coordinate_y;

    while (k >= user_coordinate_x - counter && l <= user_coordinate_y + counter) {

      play_table[k][l] = new_symbol;

      --k;
      ++l;
    }
    location = 0;
  }
  counter = 0;
  //right down control
  i = user_coordinate_x;
  j = user_coordinate_y;
  if (play_table[i + 1][j + 1] == old_symbol) {
    i = user_coordinate_x + 1;
    j = user_coordinate_y + 1;
    while (i < row && j < column) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i + 1][j + 1] == new_symbol) {
          location = 1;
        }
      }
      ++i;
      ++j;
    }
  }
  if (location == 1) {
    int k = user_coordinate_x;
    int l = user_coordinate_y;
    while (k <= user_coordinate_x + counter && l <= user_coordinate_y + counter) {

      play_table[k][l] = new_symbol;

      ++k;
      ++l;
    }
    location = 0;
  }
  counter = 0;
  //left up control
  i = user_coordinate_x;
  j = user_coordinate_y;
  if (play_table[i - 1][j - 1] == old_symbol) {
    i = user_coordinate_x - 1;
    j = user_coordinate_y - 1;
    while (i >= 0 && j >= 0) {
      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i - 1][j - 1] == new_symbol) {
          location = 1;
        }
      }
      --i;
      --j;
    }
  }
  if (location == 1) {
    int k = user_coordinate_x;
    int l = user_coordinate_y;
    while (k >= user_coordinate_x - counter && l >= user_coordinate_y - counter) {

      play_table[k][l] = new_symbol;
      --k;
      --l;
    }
    location = 0;
  }
  counter = 0;
  //left down control
  i = user_coordinate_x;
  j = user_coordinate_y;
  if (play_table[i + 1][j - 1] == old_symbol) {
    i = user_coordinate_x + 1;
    j = user_coordinate_y - 1;
    while (i < row && j < column) {

      if (play_table[i][j] == old_symbol) {
        counter++;
        if (play_table[i + 1][j - 1] == new_symbol) {
          location = 1;
        }
      }
      ++i;
      --j;
    }
  }
  if (location == 1) {
    int k = user_coordinate_x;
    int l = user_coordinate_y;
    while (k <= user_coordinate_x + counter && l >= user_coordinate_y - counter) {

      play_table[k][l] = new_symbol;

      ++k;
      --l;
    }
    location = 0;
  }
}
//It function prints array to screen

void print_table(char play_table[][ROW_MAX], int row, int column) {
  int b = 1;
  char letter = 'a';
  cout << " .";

  for (int i = 0; i < column; ++i) {
    cout << letter;
    letter++;
  }

  cout << endl;
  for (int i = 0; i < row; ++i) {
    if (b < 10) {
      cout << " ";
    }
    cout << b;
    for (int j = 0; j < column; ++j) {
      cout << play_table[i][j];
    }
    cout << endl;
    b++;
  }

}


