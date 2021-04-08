#include <stdio.h>

int main(){
    int tab[] = {67305985, 134678021, 202050057};

    char *wskaznik_do_tablicy_intow_zrzutowanej_na_1_bajtowe_chary = (char*)tab;

    for(unsigned i = 0; i < sizeof(tab); i++){
        if(*(wskaznik_do_tablicy_intow_zrzutowanej_na_1_bajtowe_chary + i) > 3 && *(wskaznik_do_tablicy_intow_zrzutowanej_na_1_bajtowe_chary + i) < 8){
            printf("%p ",(void*)(wskaznik_do_tablicy_intow_zrzutowanej_na_1_bajtowe_chary + i));
        }
    }

    return 0;
}