#include <stdio.h>

int read_vector(int vec[], int size, int stop_value){
    if(size<1) return -1;
    int num, counter = 0;
    printf("Podaj wektor:\n");
    do{
        if(!scanf("%d",&num)){
        return -1;
        }
        if(num != stop_value){
            vec[counter] = num;
            counter++;
        }
    }while(num != stop_value && counter < size);
    while(getchar()!='\n');
    return counter;
}

int max(const int arr[], int size){
    if(size-1 < 0) return -1;
    if(size - 1 == 0) return arr[size - 1];
    else{
        int a = max(arr,size-1);
        return ((a>arr[size-1]) ? a : arr[size-1]);
    }
}

int main(){

    int A[150] = {0};
	int counterA = read_vector(A, 150, -1);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}

	if (counterA < 1) {
		printf("Not enough data available");
		return 2;
	}

    printf("%d",max(A,counterA));
    return 0;
}           

