#include<stdio.h>

int squareAdd(int);

int main(void){
    int n=0;
    printf("input number = ");
    scanf("%d",&n);
    printf("%d\n",squareAdd(n));
    return 0;
}

int squareAdd(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i*i;
    }
    return sum;
}