#include<stdio.h>

void bubbleSort(int dt[], int start, int end){
    for(int i = end; i > start; i--){
        for(int j = start; j < i; j++){
            if(dt[j] > dt[j + 1]){
                int tmp = dt[j];
                dt[j] = dt[j + 1];
                dt[j + 1] = tmp;
            }
        }
    }
}
int main (void){
    int start, end;
    int dt[10] = {9, 1, 3, 7, 0, 5, 4, 2, 8, 6};
    scanf("%d %d", &start, &end);
    printf("before sort\n");
    for(int i = 0; i < 10; i++) printf("%d\n", dt[i]);
    bubbleSort(dt, start, end);
    printf("after sort\n");
    for(int i = 0; i < 10; i++) printf("%d\n", dt[i]);
}

