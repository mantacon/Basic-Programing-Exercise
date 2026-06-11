#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    FILE *fp;
    if((fp = fopen("data100.txt", "w")) != NULL){
        for(int i = 0; i < 100; i++){
            fprintf(fp, "%d\n", rand());
        }
        fclose(fp);
    }else{
        printf("cannot open\n");
    }

    if((fp = fopen("data1000.txt", "w")) != NULL){
        for(int i = 0; i < 1000; i++){
            fprintf(fp, "%d\n", rand());
        }
        fclose(fp);
    }else{
        printf("cannot open\n");
    }

    if((fp = fopen("data10000.txt", "w")) != NULL){
        for(int i = 0; i < 10000; i++){
            fprintf(fp, "%d\n", rand());
        }
        fclose(fp);
    }else{
        printf("cannot open\n");
    }
}