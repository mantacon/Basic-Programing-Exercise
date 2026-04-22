#include<stdio.h>

int main(){
    int x=0;
    printf("x=");
    scanf("%d",&x);
    x++;
    for(;;x++){
        if(x%13==0&&x%17==0){
            printf("%d”N",x);
            break;
        }else{}
    }
    return 0;
}