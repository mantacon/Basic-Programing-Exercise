#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    FILE* fp1;
    FILE* fp2;
    int max, data;
    char str1[1000], str2[1000];

    if((fp1 = fopen("files/sample.pgm", "r")) != NULL){
        if((fp2 = fopen("files/sample2.pgm", "w")) != NULL){
            for(int i = 0; i < 4; i++) {
                fscanf(fp1, "%s", str1);
                fprintf(fp2, "%s\n", str1);
            }
            max = atoi(str1);
            while(fscanf(fp1, "%d", &data) != EOF){
                if(data > max / 2) data = max;
                else data = 0;
                fprintf(fp2, "%d\n", data);
            }
            
            fclose(fp1);
            fclose(fp2);
        }
        else{
            fprintf(stderr, "%s cannot open", "files/sample2.pgm");
            exit(1);
        }
    }
    else{
        fprintf(stderr, "%s cannot open", "files/sample.pgm");
        exit(1);
    }
}