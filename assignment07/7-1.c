#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    FILE* fp1;
    FILE* fp2;
    char str1[1000], str2[1000];

    if((fp1 = fopen(argv[1], "r")) != NULL){
        if((fp2 = fopen(argv[2], "r")) != NULL){
            for(int i = 1; (fgets(str1, 1000, fp1) != NULL) && (fgets(str2, 1000, fp2) != NULL); i++){
                if(strcmp(str1, str2) != 0){
                    printf("%dçsñ⁄\n",i);
                    printf("%s", str1);
                    printf("%s\n", str2);
                }
            }
            fclose(fp1);
            fclose(fp2);
        }
        else{
            fprintf(stderr, "%s cannot open", argv[2]);
            exit(1);
        }
    }
    else{
        fprintf(stderr, "%s cannot open", argv[1]);
        exit(1);
    }
}