#include<stdio.h>

int getComb(int n, int m){
    if(m == 0) return 1;
    else if(m < 0) return 0;
    int value = 0;
    for(int i = 1; i <= n; i++) value += getComb(n, m - i);
    return value;
}
int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    printf("‘‘g‚İ‡‚í‚¹”%d", getComb(n, m));
    return 0;
}