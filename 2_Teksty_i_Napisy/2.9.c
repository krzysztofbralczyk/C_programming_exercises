#include <stdio.h>
int connect(const char* t1, const char* t2, const char* t3, char* t4, int size);
char* my_strcpy(char* dest, const char* src);
int my_strlen(const char* str);
char* my_strcat(char* dest, const char* src);

int main(){
    printf("Podaj tekst: ");
    char strin1[1001];   
    scanf("%1000[^\n]",strin1);
    while(getchar()!='\n');

    printf("Podaj tekst: ");
    char strin2[1001];   
    scanf("%1000[^\n]",strin2);
    while(getchar()!='\n'); 

    printf("Podaj tekst: ");
    char strin3[1001];   
    scanf("%1000[^\n]",strin3);
    while(getchar()!='\n');

    char strin4[3004];
    connect(strin1,strin2,strin3,strin4,3001);
    printf("%s",strin4);

    return 0;
}

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size){
    if(t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL) return 1;
    if(my_strlen(t1) + my_strlen(t2) + my_strlen(t3) > size-3 ) return 1;
    my_strcpy(t4,t1);
    my_strcat(t4," ");
    my_strcat(t4,t2);
    my_strcat(t4," ");
    my_strcat(t4,t3);
    return 0;
}

int my_strlen(const char* str){
    int length = 0;
    while(*(str+length)) length++;
    return length;
}

char* my_strcat(char* dest, const char* src){
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    for(int i = 0; i <= src_len; i++){ // <= to include terminator
        *(dest + dest_len + i) = *(src + i);
    }
    return dest;
}

char* my_strcpy(char* dest, const char* src){
    int length = my_strlen(src);
    // int dest_length = my_strlen(dest);
    for(int i = 0; i <= length; i++){ // <= to include terminator
        *(dest+i) = *(src+i);
    }
    return dest;
}