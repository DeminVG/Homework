#include <stdio.h>

int main(){
    int a;

    printf("%s", "Enter a number: ");
    scanf("%d", &a);

    if (a == 1 || a == 2){
        printf("%d prime number \n", a);
    } else{
        for(int i = 2; i < a; i++){
        //for(int i = (a - 1); i > 0; i--) {//(int i = 2; i < a; i++)
            if ((a % i) == 0) {
                printf("%d is not a prime number \n", a);
                break;
            }
            if (i == (a-1)) {
                printf("%d prime number \n", a);
                break;
            }            
        }
    }   
    printf("\n");
    return 0;
}