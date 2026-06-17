#include<stdio.h>

#define N 10

void printA(int a[], int n){
    if(n == 0) printf("%d", a[0]);
    else{
        printf("%d  ", a[n]);
        printA(a, n - 1);
    }
}
int main(void){
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printA(a, N - 1);
    return 0;
}