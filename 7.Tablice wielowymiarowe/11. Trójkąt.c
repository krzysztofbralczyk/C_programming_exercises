#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[10][10];
  int biggest = 0, smallest = 0;
  double sum = 0;
  int flag = 1;
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
      if(flag){
        biggest = A[i][j];
        smallest = A[i][j];
        flag = 0;
      }
      if(A[i][j] > biggest){
        biggest = A[i][j];
      }
      if(A[i][j] < smallest){
        smallest = A[i][j];
      }
      sum += A[i][j];
    }
  }

  int b_counter = 0;
  int s_counter = 0;
  double smallest_difference;
  flag = 1;
  int b_coords[2];
  int s_coords[2];
  int c_coords[2];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){

      if(A[i][j] == biggest){
        b_counter++;
        if(b_counter>1){
          printf("error");
          return 2;
        }
        b_coords[0] = i;
        b_coords[1] = j;
      }
      if(A[i][j] == smallest){
        s_counter++;
        if(s_counter>1){
          printf("error");
          return 2;
        }
        s_coords[0] = i;
        s_coords[1] = j;
      }
      if(flag){
        smallest_difference = fabs(A[i][j]-sum/100);
        flag = 0;
      }
      if(fabs(A[i][j]-sum/100)<smallest_difference){
        smallest_difference = fabs(A[i][j]-sum/100);
      }
    }
  }

  int d_counter = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(fabs(A[i][j]-sum/100) == smallest_difference){
        d_counter++;
        if(d_counter>1){
          printf("error");
          return 2;
        }
        c_coords[0] = i;
        c_coords[1] = j;
      }
    }
  }
  double side1 = sqrt(pow(abs(s_coords[0]-b_coords[0]),2) + pow(abs(s_coords[1]-b_coords[1]),2));
  double side2 = sqrt(pow(abs(b_coords[0]-c_coords[0]),2) + pow(abs(b_coords[1]-c_coords[1]),2));
  double side3 = sqrt(pow(abs(c_coords[0]-s_coords[0]),2) + pow(abs(c_coords[1]-s_coords[1]),2));
  printf("%.2lf %.2lf %.2lf",side1,side3,side2);

  return 0;
}