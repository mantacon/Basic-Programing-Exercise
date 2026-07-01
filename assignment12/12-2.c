#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readFile(int dt[]){
    FILE* fp;
    if((fp = fopen("cost_file_n500.csv", "r")) != NULL){
        for(int i = 0; i < 500; i++){
            fscanf(fp, "%d", &dt[i]);
        }
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return;
    }
}

void purchase(int x, int dt[], int numSave[], int *best, int sum, int count){
    if(sum == x) {
        if(count < *best){
            *best = count;
            printf("----------Å—Ç‰ðXV----------\n");
            for(int i = 0; i < count - 1; i++){
                printf("%d + ", dt[numSave[i]]);
            }
            printf("%d = %d\n", dt[numSave[count - 1]], x);
        }
        return;
    }
    for(int i = 0; i < 500; i++){
        if(*best <= count + 1) break;
        if(sum + dt[i] <= x) {
            numSave[count] = i;
            purchase(x, dt, numSave, best, sum + dt[i], count + 1);
            numSave[count] = 0;
        }
    }
    return;
}
int main(int argc, char* argv[]){
    int x = atoi(argv[1]);
    int* dt = (int*)malloc(500 * sizeof(int));
    int numSave[100] = {0};
    readFile(dt);
    int best = 100;
    purchase(x, dt, numSave, &best, 0, 0);
    free(dt);
    return 0;
}