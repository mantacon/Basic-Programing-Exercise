#include<stdio.h>
int squareAdd(static int);

int main(void){
    int n=0;
    for(int i=0;n>=0;i++){
    printf("input number = ");
    scanf("%d",&n);
    printf("%d\n",squareAdd(n));
    return 0;
    }
}

int squareAdd(static int n){
    static int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i*i;
    }
    return sum;
}