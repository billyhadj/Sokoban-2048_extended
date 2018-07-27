#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include<cmath>
using namespace std;

#include "Game.hpp"
#include "Case.hpp"


class G_Sokoban : public Game {
protected :
  int cpt ;  
public :
  G_Sokoban(const int,const int,const string);
  virtual int look_up(Case&);
  virtual int look_down(Case&);
  virtual int look_right(Case&) ;
  virtual int look_left(Case&);
  virtual Case move_up(int,Case&);
  virtual Case move_down(int,Case&);
  virtual Case move_right(int,Case&);
  virtual Case move_left(int,Case&) ;
  bool win_test();
  void target_done();
  void start();
  void robot_play(int);
} ; 


