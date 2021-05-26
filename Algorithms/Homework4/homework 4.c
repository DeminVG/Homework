#include<stdio.h>

void transfer10to2 (int num) {
    if(num > 0) {
        transfer10to2(num/2);
        printf("%d", num%2);
    }
    else {
        return(0);
    }
}

int exponential(int a, int b){
    if (b>0){
        return (a*exponential(a, b-1));
    }
    else{
        return (1);
    }
}

int exponential_mod(int a, int b){
    int res=1;
    if (b>0){
        if (b%2==0){
            res = exponential_mod(a*a, b/2);
        }
        else{
            res = a * exponential_mod(a, b-1);
        }
    }
    return (res);
}

int main() {
    int a, b;
    
    //lesson1
    printf("Введите число в десятичной системе: ");
    scanf("%d", &a);
    printf("%d в двоичной системе будет: ", a);
    transfer10to2(a);
    
    //lesson2
    printf("\nВведите число: ");
    scanf("%d", &a);
    printf("Введите степень: ");
    scanf("%d", &b);
    printf("%d в степени %d = %d", a, b, exponential(a, b));
    printf("\n%d в степени %d = %d", a, b, exponential_mod(a, b));
    
    return 0;
}