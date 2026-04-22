#include<stdio.h>

int main(){
    double x=0.0;
    printf("x=");
    scanf("%lf",&x);
    double ans=1.0;
    double a=1.0;
    for(int i=0;a>1e-7;i++){
        if(i!=0){
            a*=(x/i);
            ans+=a;
        }
        printf("%d %.8le\n",i+1,ans);
    }
}