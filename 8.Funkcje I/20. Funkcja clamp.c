#include <stdio.h>
#include "expected_prototypes.h"

int clamp(int x, int lo, int hi){
    if(hi>lo){
        if(x>=hi) return hi;
        if(x<=lo) return lo;
        return x;
    }else{
        if(x>=lo) return lo;
        if(x<=hi) return hi;
        return x;
    }

}


int main(){

  int x,lo,hi;
  printf(" do ograniczenia!:\n");
    if(!scanf("%d",&x)){
        printf("\nincorrect input");
        return 1;
    }
    printf(" pierwsza granica!:\n");
    if(!scanf("%d",&lo)){
        printf("\nincorrect input");
        return 1;
    }
    printf(" druga granica!:\n");
    if(!scanf("%d",&hi)){
        printf("\nincorrect input");
        return 1;
    }
    printf("%d",clamp(x,lo,hi));
  



  return 0;
}

