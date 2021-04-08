#include <stdio.h>

int read_vector(int vec[], int size, int stop_value) {
	if (size < 1) return -1;
	int num, counter = 0;

	do {
        printf("Podaj wymiar wiatraczka: ");
		if (!scanf("%d", &num)) { return -1; }
		if (num != stop_value) {
			vec[counter] = num;
			counter++;
		}
	} while (num != stop_value && counter < size);

	while ( getchar() != '\n' );

	return counter;
}

void draw_fan_left(int size){
    for(int i = 0; i < size;i++){
        for(int j = 0; j < i+1; j++) printf("X");
        for(int j = size-2-i; j >= 0; j--) printf(" "); //top
        for(int j = size-1-i; j >=0; j--) printf("X");
        printf("\n");
    }

    for(int i = 0; i < size;i++){
        for(int j = size-2-i; j >= 0; j--) printf(" "); //bottom
        for(int j = 0; j < i+1; j++) printf("X");
        for(int j = 0; j < i; j++) printf(" ");
        for(int j = size-1-i; j >=0; j--) printf("X");
        printf("\n");
    }
}

void draw_fan_right(int size){
    for(int i = 0; i < size;i++){
        for(int j = 0; j < i; j++) printf(" ");
        for(int j = size-1-i; j >=0; j--) printf("X");
        for(int j = size-2-i; j >= 0; j--) printf(" ");
        for(int j = 0; j < i+1; j++) printf("X");
        printf("\n");
    }

    for(int i = 0; i < size;i++){
        for(int j = size-1-i; j >=0; j--) printf("X");
        for(int j = 0; j < i; j++) printf(" ");
        for(int j = 0; j < i+1; j++) printf("X");
        printf("\n");
    }
}


int main(){
    int sizes[11];
    int size_of_sizes = read_vector(sizes,11,0);
    for(int i = 0; i < size_of_sizes; i++){
        if(sizes[i] < 0) draw_fan_right(-sizes[i]);
        if(sizes[i] > 0) draw_fan_left(sizes[i]);
    }
    
    return 0;
}