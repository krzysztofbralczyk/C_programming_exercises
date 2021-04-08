#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float distance(int x1, int y1, int x2, int y2){
  if(x1==x2 && y1==y2){return -1;}

  return sqrt(pow((float)x1-x2,2)+pow((float)y1-y2,2));
}

float perimeter(float a, float b, float c){
  if(a<=0 || b<=0 || c<=0){return -1;}
  if(a+b<=c || b+c<=a || c+a<=b){return -1;}
  return a+b+c;
}

float area(float a, float b, float c){
  if(a<=0 || b<=0 || c<=0){return -1;}
  return sqrt(perimeter(a,b,c)/2*(perimeter(a,b,c)/2-a)*(perimeter(a,b,c)/2-b)*(perimeter(a,b,c)/2-c));
}


int main(){

  printf("\nfirst: "); 
  int x1,y1,x2,y2,x3,y3;       
  if(scanf("(%d, %d)",&x1,&y1) != 2){
    printf("Incorrect input");
    return 1;
  }
  while ( getchar() != '\n' );

  printf("\nsecond: ");   
  if(scanf("(%d, %d)",&x2,&y2) != 2){
    printf("Incorrect input");
    return 1;
  }
  while ( getchar() != '\n' );

  printf("\nthird: ");        
  if(scanf("(%d, %d)",&x3,&y3) != 2){
    printf("Incorrect input");
    return 1;
  }
  while ( getchar() != '\n' );
  
  if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x3==x1 && y3==y1)){
    printf("Incorrect input");
    return 1;
  }

  printf("%.2f",area(distance(x1,y1,x2,y2),distance(x2,y2,x3,y3), distance(x3,y3,x1,y1)));

  
  return 0;
}
