#include<stdio.h>
int squareAdd(int);

int main(void){
    int n=0;
    for(int i=0;;i++){
    printf("input number = ");
    scanf("%d",&n);
    if(n<0) break;
    printf("%d\n",squareAdd(n));
    }
    return 0;
}

int squareAdd(int n){
    static int lastN=0;
    static int sum=0;
    if(n==lastN){
        printf("Return cache date\n");
        return sum;
    }else{
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=i*i;
        }
        lastN=n;
        return sum;
    }
}

