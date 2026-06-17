#include<stdio.h>

int getComb(int n, int m, int memory[]){
    if(m == 0) return 1;
    else if(m < 0) return 0;
    int value = 0;
    if(memory[m] != -1) value = memory[m];
    else{
        for(int i = 1; i <= n; i++){
            value += getComb(n, m - i, memory);
        } 
        memory[m] = value;
    }
    return value;
}
int main(void){
    int n,m;
    int memory[1000];
    for(int i = 0; i < 1000; i++) memory[i] = -1;
    scanf("%d %d", &n, &m, memory);
    printf("‘‘g‚Ý‡‚í‚¹”%d", getComb(n, m, memory));
    return 0;
}