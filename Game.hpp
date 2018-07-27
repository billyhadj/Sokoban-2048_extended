#ifndef Game_hpp
#define Game_hpp

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>


#include "Case.hpp"

using namespace std ;

class Game {
protected :
  vector<vector<Case>> board ;
  int length, width ;
  string name ;
public :
  Game(const int,const int, const string ) ;
  // Game open_Game(string name);
  void disp() ;
  // void save();
  Case & get_case(int,int);
  
  int get_play();
  // look_*() return 0, 1 or 2, dependind on the allowed move
  virtual int look_up(Case&)=0;
  virtual int look_down(Case&)=0;
  virtual int look_right(Case&)=0; 
  virtual int look_left(Case&)=0; 
  virtual Case move_up(int,Case&)=0;
  virtual Case move_down(int,Case&)=0;
  virtual Case move_right(int,Case&)=0;
  virtual Case move_left(int,Case&)=0 ;
  
} ; 

#endif
