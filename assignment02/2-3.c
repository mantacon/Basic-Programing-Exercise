#include<stdio.h>

int main(){
    int x=0;
    printf("x=");
    scanf("%d",&x);
    if(x<0||x>12){
        printf("error!");
    }   else if(x==0){
            printf("0!=1");
        }   else{
                int y=1;
                for(int i=1;i<=x;i++){
                   y*= i;
                }
                printf("%d!=%d",x,y);
            }
    return 0;
}