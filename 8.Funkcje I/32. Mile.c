#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

double km2nm (double distance){
    if(distance < 0) return -1;
    return distance/1.851852;
}
double km2lm (double distance){
    if(distance < 0) return -1;
    return distance/1.609344;
}


int main(){

    printf("Podaj odleglosc w kilometrach:  ");
    double distance;
    if(!scanf("%lf",&distance)){
        printf("Incorrect input");
        return 1;
    }
    double nautical_miles = km2nm(distance);
    if(nautical_miles == -1){
        printf("Incorrect input data");
        return 2;
    }
    double land_miles = km2lm(distance);
    if(land_miles == -1){
        printf("Incorrect input data");
        return 2;
    }
    printf("%.3lf mile morskie\n",nautical_miles);
    printf("%.3lf mile ladowe",land_miles);
    return 0;
}
