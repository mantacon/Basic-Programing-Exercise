#include<stdio.h>
#include<stdlib.h>

void OneMax(int x[], int i, int *best, int n){
    if(i == n){
        int temp = 0;
        for(int k = 0; k < n; k++) temp += x[k];
        if(temp > *best){
            *best = temp;
            printf("---------------Å—Ç‰ğXV---------------\n");
            printf("f(x) = %d\n", *best);
            printf("x = (");
            for(int k = 0; k < n - 1; k++) printf("%d, ", x[k]);
        printf("%d)\n", x[n - 1]);
            return;
        }
        else{
            return;
        }
    }

    for(int j = 0; j < 2; j++){
        x[i] = j;
        OneMax(x, i + 1, best, n);
    }
}
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int *x = (int *)malloc(sizeof(int) * n);
    int best = -1;
    OneMax(x, 0, &best, n);
    free(x);

    return 0;
}