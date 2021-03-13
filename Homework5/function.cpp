#include <iostream>

namespace My_Arrey_Function {

void Print_Arrey(int arr[], int size) {
    
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
        std::cout << "\n";
}

void Shift_Arrey_left(int arr[], int drift, int size) {
    int buffer;
    for(int i = 0; i < drift; i++) {
        buffer = arr[0];
        for( int j = 0; j < size; j++) {
            arr[j] = arr[j + 1];
        }
        arr[size-1] = buffer;
    }
}

void Shift_Arrey_right(int arr[], int drift, int size) {
    int buffer;
    for(int i = 0; i < drift; i++) {
        buffer = arr[size-1];
        for( int j = size; j >= 1; j--) {
            arr[j] = arr[j -1];
        }
        arr[0] = buffer;
    }
}

void Shift_Arrey(int arr[], int drift, int size) {
    if (drift > 0) {
        Shift_Arrey_right(arr, drift, size);
    } else if (drift < 0) {
        Shift_Arrey_left(arr, - drift, size);
    }
}

int Sum_Arrey(int arr[], int first_element_sum, int end_element_sum) {
    int sum = 0;
    for(int i = first_element_sum; i <= end_element_sum; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

bool Compare_Arrey(int arr[], int size) {
    bool res;
    std::cout << "size arrey = " << size << "\n" ;
    Print_Arrey(arr, 8);
    int Sum_l = 0, Sum_r = 0;
    for(int i = 0; i < size; i++) {
        std::cout << "i = " << i ;
        Sum_l = Sum_Arrey(arr, 0, i);
        std::cout << " sum_left= " << Sum_l;
        Sum_r = Sum_Arrey(arr, i + 1, size - 1);
        std::cout << " sum_rait=" << Sum_r << "\n";
        if (Sum_l == Sum_r){
            res = true;
            break;
        } else {
            res = false;
        }
    }
    return res;
}

void Fills_the_Array(int arr[], int size) {
    
    for(int i = 0; i < size; i++) {
        arr[i] = i*3+1;
    }
}

void Replase_Arrey_0_to_1(int arr[], int size) {
    
    for(int i = 0; i < size; i++) {
        arr[i] = ((arr[i]) ^ 1);
    }
}

}