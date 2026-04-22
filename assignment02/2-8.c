#include<stdio.h>

int main(){
    int x=0;
    int temp[100]={0};
    printf("x=");
    scanf("%d",&x);
    int i=0;
    for(;x>0;i++){
        temp[i]=x%2;
        x/=2; 
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",temp[j]);
    }
    return 0;
}