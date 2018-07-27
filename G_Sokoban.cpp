

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include <unistd.h>
using namespace std ;

#include "Case.hpp"
#include "Game.hpp"
#include "G_Sokoban.hpp"

G_Sokoban :: G_Sokoban(const int i, const int j, const string n):Game(i,j,n)
{
  int a ; 
  for (int a = 0; a< i ; a++){
    for (int b = 0 ; b < j ; b++){
      if(a==0 || b ==0 || a == length-1| b==width-1){
	board[a][b][2]= 3;
      }
      else {
	board[a][b][2]=(rand()%2)*3;
	board[a][b][2]*=rand()%2; // Attenuation of 3 (multiply by uniform law on 0 and1 
      }
    }
  }
  board[i/2+1][j/3][2]= 2 ;
  board[i/2][j/3][2]= 2 ;
  
  board[j/4+1][j-2][2] = 4;
  board[j/3+2][j-1][2] = 4;
  cpt = 2 ;
}

// 0 : empty area, 1:  caracter,2: box, 3 : obstacle/wall/side
int G_Sokoban :: look_left(Case & C){  //Case(x,y)
  if(C[0]>1){ // The current Case is not on the border
    if(board[C[0]-2][C[1]][2]==0){ //look at the disponibility of two Case further
      if(board[C[0]-1][C[1]][2]==0){// look at the dispoibility of the adjacent Case
	return 0 ; // empty
      }
      if(board[C[0]-1][C[1]][2]==2){
	return 1 ; // the box (it can move thanks to the first if)
      }
      if(board[C[0]-1][C[1]][2]==3){
	return 2 ; // unavailable Case, no allowed move
      }
    }
    if(board[C[0]-2][C[1]][2]==3 || board[C[0]-2][C[1]][2]==2  ){
      if(board[C[0]-1][C[1]][2]==0){ // Case which implies a caracter move only(without box)
	return 0; // Case available
      }
      else{
	return 2 ;//
      }
    }
    if(board[C[0]-2][C[1]][2]==4){
      if(board[C[0]-1][C[1]][2]==0){
	return 0 ;
      }
      if(board[C[0]-1][C[1]][2]==3){
	return 2;
      }
      if(board[C[0]-1][C[1]][2]==2){
	return 3 ;
      }
    }
  }
  if(C[0]==1){
    if(board[C[0]-1][C[1]][2]==0){
      return 0 ;
    }
    else {
      return 2 ;
    }
  }
  if(C[0]==0){
    return 2 ;
  }
}
//--------------------Right
int G_Sokoban :: look_right(Case & C){  //Case(x,y)
  if(C[0]<length-2){ // The current Case is not on the border
    if(board[C[0]+2][C[1]][2]==0){ //look at the disponibility of two Case further
      if(board[C[0]+1][C[1]][2]==0){// look at the dispoibility of the adjacent Case
	return 0 ; // empty
      }
      if(board[C[0]+1][C[1]][2]==2){
	return 1 ; // the box (it can move thanks to the first if)
      }
      if(board[C[0]+1][C[1]][2]==3){
	return 2 ; // unavailable Case, no allowed move
      }
    }
    if(board[C[0]+2][C[1]][2]==3 || board[C[0]-2][C[1]][2]==2  ){
      if(board[C[0]+1][C[1]][2]==0){ // Case which implies a caracter move only(without box)
	return 0; // Case available
      }
      else{
	return 2 ;//
      }
    }
    if(board[C[0]+2][C[1]][2]==4){
      if(board[C[0]+1][C[1]][2]==0){
	return 0 ;
      }
      if(board[C[0]+1][C[1]][2]==3){
	return 2;
      }
      if(board[C[0]+1][C[1]][2]==2){
	return 3 ;
      }
    }
  }
  if(C[0]==length-2){
    if(board[C[0]+1][C[1]][2]==0){
      return 0 ;
    }
    else {
      return 2 ;
    }
  }
  if(C[0]==length-1){
    return 2 ;
  }
}

//-----------down
int G_Sokoban :: look_down(Case & C){  //Case(x,y)
  if(C[1]<width-2){ // The current Case is not on the border
    if(board[C[0]][C[1]+2][2]==0){ //look at the disponibility of two Case further
      if(board[C[0]][C[1]+1][2]==0){// look at the dispoibility of the adjacent Case
	return 0 ; // empty
      }
      if(board[C[0]][C[1]+1][2]==2){
	return 1 ; // the box (it can move thanks to the first if)
      }
      if(board[C[0]][C[1]+1][2]==3){
	return 2 ; // unavailable Case, no allowed move
      }
    }
    if(board[C[0]][C[1]+2][2]==3 || board[C[0]-2][C[1]][2]==2  ){
      if(board[C[0]][C[1]+1][2]==0){ // Case which implies a caracter move only(without box)
	return 0; // Case available
      }
      else{
	return 2 ;//
      }
    }
    if(board[C[0]][C[1]+2][2]==4){
      if(board[C[0]][C[1]+1][2]==0){
	return 0 ;
      }
      if(board[C[0]][C[1]+1][2]==3){
	return 2;
      }
      if(board[C[0]][C[1]+1][2]==2){
	return 3 ;
      }
    }
  }
  if(C[1]==length-2){
    if(board[C[0]][C[1]+1][2]==0){
      return 0 ;
    }
    else {
      return 2 ;
    }
  }
  if(C[1]==length-1){
    return 2 ;
  }
}

//----------up

int G_Sokoban :: look_up(Case & C){  //Case(x,y)
  if(C[1]>1){ // The current Case is not on the border
    if(board[C[0]][C[1]-2][2]==0){ //look at the disponibility of two Case further
      if(board[C[0]][C[1]-1][2]==0){// look at the dispoibility of the adjacent Case
	return 0 ; // empty
      }
      if(board[C[0]][C[1]-1][2]==2){
	return 1 ; // the box (it can move thanks to the first if)
      }
      if(board[C[0]][C[1]-1][2]==3){
	return 2 ; // unavailable Case, no allowed move
      }
    }
    if(board[C[0]][C[1]-2][2]==3 || board[C[0]-2][C[1]][2]==2  ){
      if(board[C[0]][C[1]-1][2]==0){ // Case which implies a caracter move only(without box)
	return 0; // Case available
      }
      else{
	return 2 ;//
      }
    }
    if(board[C[0]][C[1]-2][2]==4){
      if(board[C[0]][C[1]-1][2]==0){
	return 0 ;
      }
      if(board[C[0]][C[1]-1][2]==3){
	return 2;
      }
      if(board[C[0]][C[1]-1][2]==2){
	return 3 ;
      }
    }
  }
  if(C[1]==1){
    if(board[C[0]][C[1]-1][2]==0){
      return 0 ;
    }
    else {
      return 2 ;
    }
  }
  if(C[1]==0){
    return 2 ;
  }
}






Case G_Sokoban :: move_left(int p, Case & C){
  Case R(C) ; 
  switch (p){
  case 0 :
    board[C[0]-1][C[1]][2]=1 ;
    board[C[0]][C[1]][2]=0 ;
    R[0]-- ;
    return R ;
  case 1 :
    board[C[0]-2][C[1]][2]=2;
    board[C[0]-1][C[1]][2]=1;
    board[C[0]][C[1]][2]=0;
    R[0]-- ;
    return R ; 
  case 2:
    return R;
  case 3 :
    board[C[0]-2][C[1]][2]=3;
    board[C[0]-1][C[1]][2]=1;
    board[C[0]][C[1]][2]=0;
    R[0]--;
    cpt--;
    return R ;
  }
}

Case G_Sokoban :: move_right(int p, Case & C){
  Case R(C) ; 
  switch (p){
  case 0 :
    board[C[0]+1][C[1]][2]=1 ;
    board[C[0]][C[1]][2]=0 ;
    R[0]++ ;
    return R ; 
  case 1 :
    board[C[0]+2][C[1]][2]=2;
    board[C[0]+1][C[1]][2]=1;
    board[C[0]][C[1]][2]=0;
    R[0]++ ;
    return R ; 
  case 2:
    return R;
  case 3 :
    board[C[0]+2][C[1]][2]=3;
    board[C[0]+1][C[1]][2]=1;
    board[C[0]][C[1]][2]=0;
    R[0]++;
    cpt-- ;
    return R ;
  }
}

Case G_Sokoban :: move_down(int p, Case & C){
  Case R(C) ; 
  switch (p){
  case 0 :
    board[C[0]][C[1]+1][2]=1 ;
    board[C[0]][C[1]][2]=0 ;
    R[1]++ ;
    return R ; 
  case 1 :
    board[C[0]][C[1]+2][2]=2;
    board[C[0]][C[1]+1][2]=1;
    board[C[0]][C[1]][2]=0;
    R[1]++ ;
    return R ; 
  case 2:
    return R;
  case 3 :
    board[C[0]][C[1]+2][2]=3;
    board[C[0]][C[1]+1][2]=1;
    board[C[0]][C[1]][2]=0;
    R[1]++ ;
    cpt-- ;
    return R ; 
  }
}

Case G_Sokoban :: move_up(int p, Case & C){
  Case R(C) ; 
  switch (p){
  case 0 :
    board[C[0]][C[1]-1][2]=1 ;
    board[C[0]][C[1]][2]=0 ;
    R[1]-- ;
    return R ; 
  case 1 :
    board[C[0]][C[1]-2][2]=2;
    board[C[0]][C[1]-1][2]=1;
    board[C[0]][C[1]][2]=0;
    R[1]-- ;
    return R ;
  case 2:
    return R;
  case 3 :
    board[C[0]][C[1]-2][2]=3;
    board[C[0]][C[1]-1][2]=1;
    board[C[0]][C[1]][2]=0;
    R[1]-- ;
    cpt--;
    return R ;
    
  }

}


bool G_Sokoban :: win_test(){
  return cpt!=0;
}

void  G_Sokoban :: target_done(){
  cpt--;
}

void G_Sokoban :: start(){
  int a;
  Case Pers(1,1,1);
  while(win_test()){
    disp();
    cout<<endl<<endl<< "Z : up | Q : left | D : right | S : down | X : Exit Game  "<<endl;
    a = get_play();
    if(a==1){
      Pers = move_left(look_left(Pers),Pers);
    }
    if(a==2){
      Pers = move_up(look_up(Pers),Pers);
    }
    if(a==3){
      Pers = move_right(look_right(Pers),Pers);
    }
    if(a==4){
      Pers = move_down(look_down(Pers),Pers);
    }
    if(a==5){
      cout <<endl<<"Game over !"<<endl;
      break;
    }
  }
  if(!win_test()){
    cout <<endl<<"Congratulations, You win !"<<endl;
  }
}

void G_Sokoban :: robot_play(int max){
  Case Pers(1,1,1);
  int choice ;
  while(cpt!=0 && max>0){
    max--;
    srand(time(NULL));
    choice = rand()%4;
    switch (choice){
    case 0 :
      Pers = move_left(look_left(Pers),Pers);
      break;
    case 1 :
      Pers = move_down(look_down(Pers),Pers);
      break ;
    case 2 :
      Pers = move_up(look_up(Pers),Pers);
      break;
    case 3 :
      Pers = move_right(look_right(Pers),Pers);
      break;
   
    }
    disp();
    sleep(1);
  }
  
  
}
      
      
