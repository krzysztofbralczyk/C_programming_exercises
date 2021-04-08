#include <stdio.h>
#include <stdlib.h>

int main() {
    char* text = NULL;
    char current_char = 'a';
    int size = 1;
    char* prev_text;

    text = (char*)realloc(text, size);
    if (text == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Prosze tekst :( ");
    scanf("%c", &current_char);
    if (current_char == '\n') {free(text); return 0;};
    *(text + size - 1) = current_char;


    while (1) {
        scanf("%c", &current_char);
        if (current_char == '\n') break;
        size++;
        prev_text = text;
        text = (char*)realloc(text,size);
        if (text == NULL) {
            size--;
            break;
        }
        *(text + size - 1) = current_char;
    }
    if(text != NULL){
        for (int i = 0; i < size; i++) printf("%c", *(text + i));
        free(text);
    } 
    else{
        for (int i = 0; i < size-1  ; i++) printf("%c", *(prev_text + i));
        free(prev_text);
    }
    
    return 0;
}