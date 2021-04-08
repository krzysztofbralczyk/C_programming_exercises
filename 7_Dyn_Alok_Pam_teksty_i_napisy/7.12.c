#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ONE_FOR_NULL_POINTER 1
#define ONE_FOR_TERMINATOR 1
int no_words(const char*);
char** split_words(const char*);
int count_words(const char*);
int get_word_length(const char*);
int sort_words(char**);
void destroy(char**);

int main() {

    char* text = (char*)malloc(1000 * sizeof(char));
    if (text == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Text please: ");
    scanf("%999[^\n]", text);  //co oznacza że nie bedzie żadnych wyrazów? zero wprowadzonych znaków?pojedyncze znaki? jeden wielki ciag znakow?
    if (no_words(text)) {
        printf("Nothing to show");
        free(text);
        return 0;
    }
    char** words = split_words((const char*)text);
    int sorted_returned = sort_words(words);
    if(sorted_returned == 1){
        printf("Failed to allocate memory");
        destroy(words);
        free(text);
        return 8;
    }
    
    for (int i = 0; *(words + i) != NULL; i++) {
        printf("%s\n", *(words + i));
    }

    destroy(words);
    free(text);
    return 0;
}

int no_words(const char* text) {
    while (*text) {
        if (isalpha(*text)) return 0;
        text++;
    }
    return 1;
}
int count_words(const char* text) {
    int counter = 0;
    while (*text) {
        if (isalpha(*text)) {
            counter++;
            while (isalpha(*text))text++;
        }
        else text++;
    }
    return counter;
}
int get_word_length(const char* text) {
    int counter = 0;
    while (isalpha(*text)) { counter++; text++; }
    return counter;
}
char** split_words(const char* text) {
    if (text == NULL) return NULL;
    int number_of_words = count_words(text);
    if(number_of_words == 0) return NULL;
    char** rows = (char**)malloc((number_of_words + ONE_FOR_NULL_POINTER) * sizeof(char*));
    if (rows == NULL) return NULL;
    for (int i = 0; i < number_of_words; i++) {
        while (!isalpha(*text)) text++;
        int word_length = get_word_length(text);
        *(rows + i) = (char*)malloc((word_length + ONE_FOR_TERMINATOR) * sizeof(char));
        if (*(rows + i) == NULL) {
            for (int j = 0; j < i; j++) free(*(rows + j));
            free(rows); 
            return NULL;
        }
        for (int j = 0; j < word_length; j++) {
            *(*(rows + i) + j) = *text;
            text++;
        }
        *(*(rows + i) + word_length) = '\0';
    }
    *(rows + number_of_words) = NULL;
    return rows;
}
int sort_words(char** words) {
    if (words == NULL) return 1;
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 1; *(words + i) != NULL; i++) {
            if (**(words + i) >= 'A' && **(words + i) <= 'Z' && **(words + i-1) >= 'a' && **(words + i-1) <= 'z') {
                sorted = 0;
                char* temp = *(words + i);
                *(words + i) = *(words + i - 1);
                *(words + i - 1) = temp;
            }
            else if (strcmp(*(words+i),*(words+i-1)) < 0) {
                sorted = 0;
                char* temp = *(words + i);
                *(words + i) = *(words + i - 1);
                *(words + i - 1) = temp;
            }
        }
    }
    return 0;
}
void destroy(char **words){
    if(words == NULL) return;
    int counter = 0;
    while(*words != NULL){
        free(*words);
        counter++;
        words++;
    }
    free(words-counter);
}