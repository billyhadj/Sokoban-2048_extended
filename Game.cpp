#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
#include "Game.hpp"
#include "Case.hpp"

using namespace std ;
// Defintion of Game constructor
Game :: Game(const int l, const int w, const string n):length(l),width(w),name(n){
  board.clear();
  vector <Case> temp;
  for (int i = 1 ; i<length+1 ; i++){
    for(int j = 1; j<width+1; j++){
      Case C_tmp(i,j,0);
      temp.push_back(C_tmp);
    }
	board.push_back(temp); 
	temp.clear();
  }
}

// Definition of Game displaying method
void Game :: disp() {
  cout <<"\n Displaying board : "<<name<<endl<<endl;
  cout<<" ";
  for (int i = 1 ; i<length+1 ; i++){
    cout<<"--";
  }
  cout <<endl ; 
  for (int j = 0 ; j<width; j++){
    cout <<"|";
    for(int i = 0; i<length; i++){
      cout<< board[i][j][2]<<" ";
    }
    cout<<"|"<<endl;
  }
 cout<<" ";
 for (int i = 1 ; i<length+1 ; i++){
   cout<<"--";
 }
 cout <<endl<<endl ;
}
//Defintion of Game saving method 
/*id Game :: save(){
 */


//Accessor 

Case & Game :: get_case(int a, int b){
  return  board[a][b];
}


// Definition of Get_play method

int Game :: get_play(){
  char tmp ;
  system("stty raw");
  tmp = getchar();
  system("stty cooked");
  if(tmp == 'q'){//gauche
    return 1 ;
  }
  if(tmp == 'z'){//haut
    return 2 ;
  }
  if(tmp == 'd'){//droite
    return 3 ;
  }
  if(tmp == 's'){//bas
    return 4;
  }
  if(tmp == 'x'){//quitter ! 
    return 5;
  }
}






