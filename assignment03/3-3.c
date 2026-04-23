#include<stdio.h>

int getFactorial(int);

int main(){
    int n=0;
    for(;;){
    printf("input number =");
    scanf("%d",&n);
    if(n<0||n>12){
        printf("error!\n");
        break;
    }   else if(n==0){
            printf("1\n");
        }   else{
                printf("%d\n",getFactorial(n));    
            }
    }
    return 0;
}

int getFactorial(int n){
    static int lastN=0;
    static int y=1;
    if (n==lastN){
        printf("Return cache data\n");
        return y;
    }else{
        lastN=n;
        y=1;
        for(int i=1;i<=n;i++){
            y*= i;
        }
        return y;
    }
}

