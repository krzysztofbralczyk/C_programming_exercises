#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#undef M_PI
#define M_PI 3.1415926535897931

int main()
{
  double sinus[201][2];
  for(int i = 0; i < 201; i++){
    sinus[i][0] = (double)i*M_PI/100;
    sinus[i][1] = sin((double)i*M_PI/100);
  }

 for(int i = 0; i < 201; i++){
    printf("%.4lf %.4lf\n",sinus[i][0],sinus[i][1]);
  }
  return 0;
}