#include <stdio.h>

int is_destination_reachable(int sx, int sy, int dx, int dy){
    if(sx == dx && sy == dy) return 1;
    if(sx > dx || sy > dy) return 0;
    else return is_destination_reachable(sx+sy,sy,dx,dy) || is_destination_reachable(sx,sx+sy,dx,dy);
}

int main(){
    
    printf("Podaj wspolrzedne poczatkowe: ");
    int sx,sy;
    if(scanf("%d %d",&sx,&sy) != 2){
        printf("Incorrect input");
        return 1;
    }

    printf("Podaj wspolrzedne koncowe: ");
    int dx,dy;
    if(scanf("%d %d",&dx,&dy) != 2){
        printf("Incorrect input");
        return 1;
    }

    int result = is_destination_reachable(sx,sy,dx,dy);
    if(result == 1) printf("YES");
    else printf("NO");
    return 0;
}