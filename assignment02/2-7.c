#include <stdio.h>
#include <stdlib.h>

#define arrSize 5

int main(){
    int arr[arrSize]={0};
    for(int i=0;i<arrSize;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<arrSize;i++){
        if(arr[i]>=0){
            for(int j=0;j<arr[i];j++){
                printf("+");
            }
        }else if(arr[i]<0){
            int a=abs(arr[i]);
            for(int j=0;j<a;j++){
                printf("-");
            }
        }
        printf("\n");
    }
} 