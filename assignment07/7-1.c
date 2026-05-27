#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc[], char* argv[]){
    FILE* fp1;
    FILE* fp2;
    char str1[1000], str2[1000];

    if((fp1 = fopen(argv[0], "r")) != NULL){
        if((fp2 = fopen(argv[1], "r")) != NULL){
            for(int i = 1; (fscanf(fp1, "%s", str1) != EOF) && (fscanf(fp2, "%s", str2) != EOF); i++){
                if(strcmp(str1, str2) != 0){
                    printf("%dçsñ⁄\n",i);
                    printf("%s\n", str1);
                    printf("%s\n", str2);
                }
            }
            fclose(fp1);
            fclose(fp2);
        }
        else{
            fprintf(stderr, "%s cannot open", argv[1]);
            exit(1);
        }
    }
    else{
        fprintf(stderr, "%s cannot open", argv[0]);
        exit(1);
    }
}