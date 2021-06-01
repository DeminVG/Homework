#include <stdio.h>

#define ROW 3
#define COL 3

void printArray2(int *array, const int row, const int col) {
    
    for (int i = 0; i < row*col; i++) {
        printf("%3d", array[i]);
        if((i+1)%row == 0) printf("\n");
        }
        printf("\n");
}

void bubbleSort2(int *arr, const int row, const int col) {
    int i, j, tmp, flag;
 
    do {
        flag = 0;
        for (int i = 1; i < row * col; i++) {
            if (arr[i] < arr[i-1]) {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                flag = 1;
            }
        }
    } while(flag);
}
 
void main() {
    
    int arr[ROW][COL] = 
        {{1, 9, 2}, 
         {5, 6, 7}, 
         {4, 3, 8}};
    printf("The original two-dimensional array:\n");
    printArray2(&arr[0][0], ROW, COL);

    bubbleSort2(&arr[0][0], ROW, COL);  
    printf("Two-dimensional array after bubble sorting:\n");
    printArray2(&arr[0][0], ROW, COL);
}