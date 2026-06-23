#include<stdio.h>
#include<stdlib.h>

void OneMax(int x[], int i, int *best, int n, int sum){
    if( ( n - i) + sum < *best) return;//c‚è‚ª‚·‚×‚Ä1‚Å‚àbest‚É“Í‚©‚È‚¢‚Æ‚«ŒvZ‚ğÈ‚­

    if(i == n){
        if(sum > *best) *best = sum;
        return;
    }

    for(int j = 0; j < 2; j++){
        x[i] = j;
        OneMax(x, i + 1, best, n, sum + j);
    }
}
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int *x = (int *)malloc(sizeof(int) * n);
    int best = -1;
    OneMax(x, 0, &best, n, 0);
    printf("f(x) = %d", best);
    free(x);

    return 0;
}