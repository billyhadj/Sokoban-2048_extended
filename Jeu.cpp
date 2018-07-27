#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

#include "Case.hpp"
#include "G_2048.hpp"
#include "G_Sokoban.hpp"
#include "Game.hpp"

int main(){

  cout << "Le debut du programme est bien defini pour le moment"<<endl ;
  // --------------------------------------------------------TEST FOR GAME CLASS 
  /* Game G(6,6,"premier Jeu");
  G.disp();
  int a = G.get_play() ;
  cout <<"la fonction évalue votre entrée en : "<< a<< endl ;

  vector<vector<int>> A ;
  vector<int> tmp ;
  int length , width ;
  cout << endl << "entrez la longeur du tableau puis entree"<<endl ;
  cin >> length ;
  cout << endl<< "entrez la largeur du tableau puis entree"<<endl ;
  cin >> width ;
  A.clear();
  for(int i = 0; i<length ; i++){
    tmp.clear();
    for (int j = 0; j<width ; j++){
      tmp.push_back(j);
    }
    A.push_back(tmp);
  }
  cout <<endl;
  for (int i =0 ; i<length ; i++){
    for(int j = 0 ; j<width ; j++){
      cout << A[i][j]<<" ";
    }
    cout<< endl ; 
    }*/
  //----------------------------------------------------------------------TEST FOR CASE CLASS
  /* Case C(4,3);
  C.disp_C();
  Case B(6,9,18);
  B.disp_C();
  Case D(B);
  D.disp_C();
  cout <<endl<<" la valeur est :"<<D[2]<<endl ;
  D[2]=53 ;
  cout <<"la nouvelle valeur est :"<<D[2]<<endl ; 
  */
  //-------------------------------------------------------------------------TEST for the G_Sokoban class 
  /*G_Sokoban soko(10,10,"g");
  cout<<endl<<"test accesseur"<<endl;
  soko.disp();
  soko.get_case(3,2)[2]=2;
  Case D(3,1,1);
  D.disp_C();
  soko.get_case(D[0],D[1])[2]=1;
  int  a = soko.look_down(D);
  cout <<endl<<"the test answers : "<<a<<endl;
  soko.disp();
  cout <<endl<<"the value is "<<soko.get_case(0,0)[2]<<endl;
  cout <<endl<<"test of move methods-----------------------------------"<<endl;
  D = (soko.move_down(soko.look_down(D),D));
  D.disp_C();
  soko.disp();
  D = (soko.move_down(soko.look_down(D),D));
  D.disp_C();
  soko.disp();
  D = (soko.move_down(soko.look_down(D),D));
  D.disp_C();
  soko.disp();*/
  int a ; 
  cin >> a ;
  G_Sokoban soko(a,a,"big");
  soko.start();
  
  return 0;
};
