#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int create_leading_word_cross(const char* first, const char* second, char*** result);
int create_double_leading_word_cross(
    const char* first, const char* second, const char* third, const char* fourth,
    char*** result, char*** first_cross, char*** second_cross);
void destroy(char** words);

int main() {
    char** cross_1;
    char** cross_2;
    char** double_cross;
    char* word1;
    char* word2;
    char* word3;
    char* word4;
    word1 = (char*)malloc(11*sizeof(char));
    if(word1 == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    word2 = (char*)malloc(11*sizeof(char));
    if(word2 == NULL){
        free(word1);
        printf("Failed to allocate memory");
        return 8;
    }
    word3 = (char*)malloc(11*sizeof(char));
    if(word3 == NULL){
        free(word1);
        free(word2);
        printf("Failed to allocate memory");
        return 8;
    }
    word4 = (char*)malloc(11*sizeof(char));
    if(word4 == NULL){
        free(word1);
        free(word2);
        free(word3);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Cztery słowa, proszeeeee");
    scanf("%10s %10s %10s %10s",word1, word2, word3, word4);
    int returned = create_double_leading_word_cross(word1, word2, word3, word4, &double_cross, &cross_1, &cross_2);
    if(returned == 1){
        free(word1);
        free(word2);
        free(word3);
        free(word4);
        printf("Incorrect input");
        return 1;
    }
    if(returned == 2){
        free(word1);
        free(word2);
        free(word3);
        free(word4);
        printf("Unable to make two crosses");
        return 0;
    }
    if(returned == 3){
        free(word1);
        free(word2);
        free(word3);
        free(word4);
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; *(cross_1 + i) != NULL; i++) printf("%s\n", *(cross_1 + i));
    printf("\n");
    for (int i = 0; *(cross_2 + i) != NULL; i++) printf("%s\n", *(cross_2 + i));
    printf("\n");
    for (int i = 0; *(double_cross + i) != NULL; i++) printf("%s\n", *(double_cross + i));
    free(word1);
    free(word2);
    free(word3);
    free(word4);
    destroy(cross_1);
    destroy(cross_2);
    destroy(double_cross);
    return 0;
}

int correct(const char* word) {
    while (*word) {
        if (*word < 'A' || *word > 'Z') return 0;
        word++;
    }
    return 1;
}

int create_leading_word_cross(const char* first, const char* second, char*** result) {
    if (first == NULL || second == NULL || result == NULL) { if (result != NULL) *result = NULL; return -1; }
    if (!correct(first) || !correct(second)) { *result = NULL; return -1; }
    int crossing_point_x = -1; //liczone od zera
    int crossing_point_y = -1; //liczone od zera

    for (int i = 0; *(second + i); i++) {
        for (int j = 0; *(first + j); j++) {
            if (*(second + i) == *(first + j)) {
                crossing_point_x = i;
                crossing_point_y = j;
                break;
            }
        }
        if (crossing_point_x != -1) break;
    }
    if (crossing_point_x == -1) { *result = NULL; return -2; }
    *result = (char**)malloc((strlen(first) + 1) * sizeof(char*));
    if (*result == NULL) { *result = NULL; return -3; };
    *(*result + strlen(first)) = NULL;

    for (int i = 0; (unsigned)i < strlen(first); i++) {  //yes, inefficient, don't have time to write efficiently
        if (i == crossing_point_y) {
            *(*result + i) = (char*)malloc((strlen(second) + 1) * sizeof(char));
            if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; return -3; }
        }
        else {
            *(*result + i) = (char*)malloc((crossing_point_x + 1 + 1) * sizeof(char));
            if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; return -3; }
        }
    }

    for (int i = 0; (unsigned)i < strlen(first); i++) {
        if (i == crossing_point_y)strcpy(*(*result + i), second);
        else {
            for (int j = 0; j < crossing_point_x; j++) *((*(*result + i)) + j) = ' ';
            *((*(*result + i)) + crossing_point_x) = *(first + i);
            *((*(*result + i)) + crossing_point_x + 1) = '\0';
        }
    }

    return crossing_point_y;
}

void create_cross(const char* first, const char* second, char** result, int horizontal_offset, int terminate) {

    int crossing_point_x = -1; //liczone od zera
    int crossing_point_y = -1; //liczone od zera
    for (int i = 0; *(second + i); i++) {
        for (int j = 0; *(first + j); j++) {
            if (*(second + i) == *(first + j)) {
                crossing_point_x = i;
                crossing_point_y = j;
                break;
            }
        }
        if (crossing_point_x != -1) break;
    }

    for (int i = 0; (unsigned)i < strlen(first); i++) {
        if (i == crossing_point_y) {
            // for(int j = 0; j < strlen(second); j++){ *(*(result+i)+horizontal_offset+j) = *(second+j);}
            strncpy(*(result + i) + horizontal_offset, second, strlen(second));           // WTF, WHY SEGMENTATION FAULT
            if (terminate) *((*(result + i)) + horizontal_offset + strlen(second)) = '\0';
        }
        else {
            for (int j = 0; j < crossing_point_x; j++) *((*(result + i)) + j + horizontal_offset) = ' ';
            *((*(result + i)) + crossing_point_x + horizontal_offset) = *(first + i);
            if (terminate)*((*(result + i)) + crossing_point_x + 1 + horizontal_offset) = '\0';
        }
    }

}

int create_double_leading_word_cross(const char* first, const char* second, const char* third, const char* fourth, char*** result, char*** first_cross, char*** second_cross) {
    int one_for_null = 1, one_to_go_from_len_to_idx = 1;

    //error handling START
    if (first == NULL || second == NULL || third == NULL || fourth == NULL || result == NULL || first_cross == NULL || second_cross == NULL) {
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) result = NULL;
        return 1;
    }
    //error handling END


    //first cross START
    int first_cross_result = create_leading_word_cross(second, first, first_cross);
    if (first_cross_result == -1) {
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 1;
    }
    if (first_cross_result == -2) {
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 2;
    }
    if (first_cross_result == -3) {
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 3;
    }
    //first cross END


    //second cross START
    int second_cross_result = create_leading_word_cross(fourth, third, second_cross);
    if (second_cross_result == -1) {
        for(int i = 0; (unsigned)i < strlen(second); i++){
            free(*(*first_cross+i));
        }
        free(*first_cross);
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 1;
    }
    if (second_cross_result == -2) {
        for(int i = 0; (unsigned)i < strlen(second); i++){
            free(*(*first_cross+i));
        }
        free(*first_cross);
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 2;
    }
    if (second_cross_result == -3) {
        for(int i = 0; (unsigned)i < strlen(second); i++){
            free(*(*first_cross+i));
        }
        free(*first_cross);
        if (first_cross != NULL) first_cross = NULL;
        if (second_cross != NULL) second_cross = NULL;
        if (result != NULL) *result = NULL;
        return 3;
    }
    //second cross END


    //double crossssssssss START

        //find crossing points START
    int crossing_point_x1 = -1, crossing_point_y1 = -1, crossing_point_x2 = -1, crossing_point_y2 = -1;
    for (int i = 0; *(first + i); i++) {
        for (int j = 0; *(second + j); j++) {
            if (*(first + i) == *(second + j)) {
                crossing_point_x1 = i;
                crossing_point_y1 = j;
                break;
            }
        }
        if (crossing_point_x1 != -1) break;
    }
    for (int i = 0; *(third + i); i++) {
        for (int j = 0; *(fourth + j); j++) {
            if (*(third + i) == *(fourth + j)) {
                crossing_point_x2 = i;
                crossing_point_y2 = j;
                break;
            }
        }
        if (crossing_point_x2 != -1) break;
    }
    //find crossing points END


    //pointers table memory allocation START
    int top1 = crossing_point_y1;
    int top2 = crossing_point_y2;
    int bigger_crossing_point_y = (crossing_point_y1 > crossing_point_y2) ? crossing_point_y1 : crossing_point_y2;
    int smaller_crossing_point_y = (crossing_point_y1 < crossing_point_y2) ? crossing_point_y1 : crossing_point_y2;
    int bottom1 = strlen(second) - crossing_point_y1 - 1;
    int bottom2 = strlen(fourth) - crossing_point_y2 - 1;
    int longer_top = (top1 > top2) ? top1 : top2;
    int longer_bottom = (bottom1 > bottom2) ? bottom1 : bottom2;
    int shorter_bottom = (bottom1 < bottom2) ? bottom1 : bottom2;
    int full_vertical_length = longer_top + longer_bottom + 1;

    *result = (char**)malloc((full_vertical_length + one_for_null) * sizeof(char*));
    // printf("Allocated %lu bajts for pointer table\n", (full_vertical_length + one_for_null) * sizeof(char*)); //debugging 
    if (*result == NULL) {destroy(*first_cross); destroy(*second_cross); return 3;}
    *(*result + full_vertical_length + one_for_null - one_to_go_from_len_to_idx) = NULL;
    //pointers table memory allocation END


    //columns memory allocation START
    for (int i = 0; i < full_vertical_length; i++) {

        if (i < bigger_crossing_point_y) {
            if (crossing_point_y1 > crossing_point_y2) {
                if (i < (crossing_point_y1 - crossing_point_y2)) {
                    int short_column = crossing_point_x1 + 1 + 1;
                    *(*result + i) = (char*)malloc(short_column * sizeof(char));
                    if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                    // printf("Allocated %lu bajts for short column\n", (short_column) * sizeof(char*));
                    for (int k = 0; k < short_column; k++) *(*(*result + i) + k) = ' '; //here
                    *(*(*result + i) + short_column - 1) = '\0'; //here
                }
                else {
                    int medium_column = strlen(first) + 3 + strlen(third) - (strlen(third) - crossing_point_x2 - 1) + 1;
                    *(*result + i) = (char*)malloc(medium_column * sizeof(char));
                    if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                    // printf("Allocated %lu bajts for medium\n", (medium_column) * sizeof(char*));
                    for (int k = 0; k < medium_column; k++) *(*(*result + i) + k) = ' '; //here
                    *(*(*result + i) + medium_column - 1) = '\0'; //here
                }
            }
            else {
                int medium_column = strlen(first) + 3 + strlen(third) - (strlen(third) - crossing_point_x2 - 1) + 1;
                *(*result + i) = (char*)malloc(medium_column * sizeof(char));
                if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                // printf("Allocated %lu bajts for medium\n", (medium_column) * sizeof(char*));
                for (int k = 0; k < medium_column; k++) *(*(*result + i) + k) = ' '; //here
                *(*(*result + i) + medium_column - 1) = '\0'; //here
            }
        }
        else if (i == bigger_crossing_point_y) {
            int long_column = strlen(first) + 3 + strlen(third) + 1;
            *(*result + i) = (char*)malloc(long_column * sizeof(char));
            if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
            // printf("Allocated %lu bajts for long column\n", (long_column) * sizeof(char*));
            for (int k = 0; k < long_column; k++) *(*(*result + i) + k) = ' '; //here
            *(*(*result + i) + long_column - 1) = '\0'; //here
        }
        else {
            if (bottom1 > bottom2) {
                if (i < full_vertical_length - (longer_bottom - shorter_bottom)) {
                    int medium_column = strlen(first) + 3 + strlen(third) - (strlen(third) - crossing_point_x2 - 1) + 1;
                    *(*result + i) = (char*)malloc(medium_column * sizeof(char));
                    if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                    // printf("Allocated %lu bajts for medium column\n", (medium_column) * sizeof(char*));
                    for (int k = 0; k < medium_column; k++) *(*(*result + i) + k) = ' '; //here
                    *(*(*result + i) + medium_column - 1) = '\0'; //here
                }
                else {
                    int short_column = crossing_point_x1 + 1 + 1;
                    *(*result + i) = (char*)malloc(short_column * sizeof(char));
                    if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                    // printf("Allocated %lu bajts for short column\n", (short_column) * sizeof(char*));
                    for (int k = 0; k < short_column; k++) *(*(*result + i) + k) = ' '; //here
                    *(*(*result + i) + short_column - 1) = '\0'; //here
                }
            }
            else {
                int medium_column = strlen(first) + 3 + strlen(third) - (strlen(third) - crossing_point_x2 - 1) + 1;
                *(*result + i) = (char*)malloc(medium_column * sizeof(char));
                if (*(*result + i) == NULL) { for (int j = 0; j < i; j++) free(*(*result + j)); free(*result); *result = NULL; destroy(*first_cross); destroy(*second_cross); return 3; } //here
                // printf("Allocated %lu bajts for medium column\n", (medium_column) * sizeof(char*));
                for (int k = 0; k < medium_column; k++) *(*(*result + i) + k) = ' '; //here
                *(*(*result + i) + medium_column - 1) = '\0'; //here
            }
        }
    }
    //columns memory allocation END

    //creating double cross START
    if (top1 > top2) {
        create_cross(second, first, *result, 0, 0);
        create_cross(fourth, third, *result + bigger_crossing_point_y - smaller_crossing_point_y, strlen(first) + 3, 1);
    }
    else {
        create_cross(second, first, *result + bigger_crossing_point_y - smaller_crossing_point_y, 0, 0);
        create_cross(fourth, third, *result, strlen(first) + 3, 1);
    }


    //creating double cross END

//double crossssssssss END
    return 0;
}

void destroy(char** words) {
    if (words == NULL) return;
    int counter = 0;
    while (*words != NULL) {
        free(*words);
        words++;
        counter++;
    }

    free(words - counter);
}

