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

int binary_search(const int arr[], int l, int r, int x){
    if (l > r) return -1; //base case 1
    if (arr[(r+l)/2] == x) return (r+l)/2; //base case 2
    else{
        if (arr[(r+l)/2] > x) return binary_search(arr, l,(r+l)/2-1, x);
        else return binary_search(arr, (r+l)/2+1, r, x);
    }
}

int is_sorted(const int arr[],int length,int idx){
    if (idx == length-1) return 1;
    if(arr[idx] > arr [idx+1]) return 0;
    else return is_sorted(arr,length,idx+1);
}



int main(){
    // int A[9] = {-381, -193, -155, -100, -86, 116, 129, 178, 281};
    // printf("%d",binary_search(A, 0, 8, 116));
    // printf("%d", is_sorted(A,9,0));

    int A[150] = {0};
	int counterA = read_vector(A, 150, 0);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}

	if (counterA < 1) {
		printf("Not enough data available");
		return 3;
	}

    printf("Liczbe w ktorej bede szukac prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(!is_sorted(A,counterA,0)){
        printf("Incorrect input data");
        return 2;
    }

    printf("%d",binary_search(A,0,counterA-1,num));

    return 0;
}