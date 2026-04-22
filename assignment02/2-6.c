#include<stdio.h>

# define arrSize 5
int main(){
    int arr[arrSize]={0};
    for(int i=0;i<arrSize;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<arrSize;i++){
        if(max<arr[i]){
            max=arr[i];
        }else if(min>arr[i]){
            min=arr[i];
        }
    }
    printf("max=%d\n",max);
    printf("min=%d\n",min);
}