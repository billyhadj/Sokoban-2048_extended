#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include "Case.hpp"

using namespace std ;
//defition of Case constructor : 
Case :: Case(int a, int b, int val){
  x = a ;
  y = b ;
  value = val ;
}

// defintion of Case copy constructor :
Case :: Case(const Case & C){
  x = C.x ;
  y = C.y ;
  value = C.value ;
}

// defintion of Case display :
void Case :: disp_C() {
  cout <<endl<< "Current Case coordinates : ("<<x<<","<<y<<")"<<endl;
  cout <<"Current Case value : "<<value<<endl ;
}

// definition of Case accessor :
int& Case :: operator [] (const int i){
  if (i==0){
    return x ;
  }
  if (i==1){
    return y ;
  }
  if (i==2){
    return value ;
  }
}


  
