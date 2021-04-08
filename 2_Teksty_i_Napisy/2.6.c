#include <stdio.h>
char* my_strcpy(char* dest, const char* src);
int my_strlen(const char* str);
char* my_strcat(char* dest, const char* src);

int main(){
    printf("Podaj tekst 1: ");
	char strin1[2001];
	scanf("%1000[^\n]", strin1);
    while(getchar()!='\n');
    printf("Podaj tekst 2: ");
	char strin2[2001];
	scanf("%1000[^\n]", strin2);
    printf("%d %d\n",my_strlen(strin1),my_strlen(strin2));
    printf("%s\n",my_strcat(strin2,strin1));
    printf("%s",my_strcpy(strin2,strin1));

    return 0;
}

char* my_strcpy(char* dest, const char* src){
    int length = my_strlen(src);
    // int dest_length = my_strlen(dest);
    for(int i = 0; i <= length; i++){ // <= to include terminator
        *(dest+i) = *(src+i);
    }
    return dest;
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