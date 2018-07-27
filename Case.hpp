#ifndef Case_hpp
#define Case_hpp

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>


using namespace std  ;


class Case{
private :
  int x,y ;
  int value ;
public :
  Case(int a , int b, int val = 0);
  Case(const Case &);
  void disp_C();
  int & operator[](int);
} ;







#endif
