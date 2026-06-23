#include<stdio.h>

void BaseN(int x[], int n, int m, int i){
    if(m < n){
        printf("%x", m);
        for(int j = i - 1; j >= 0; j--) printf("%x", x[j]);
        return;
    }

    x[i] = m % n;
    BaseN(x, n, m / n, i + 1);
}

int main(void){
    int n, m;
    int x[100] = {0};
    scanf("%d %d", &n, &m);
    BaseN(x, n, m, 0);
    return 0;
}