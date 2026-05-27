#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    FILE* fp1;
    FILE* fp2;
    char str1[1000], str2[1000];

    if((fp1 = fopen(argv[1], "r")) != NULL){
        if((fp2 = fopen(argv[2], "w")) != NULL){
            while(fgets(str1, 1000, fp1) != NULL){
                if(str1[0] == '#'){
                    if(str1[1] == '#'){
                        
                        fprintf(fp2, "<h2>");
                        str1[strcspn(str1, "\n")] = '\0';
                        fprintf(fp2, "%s</h2>", str1 + 2);
                    }
                    else{
                        fprintf(fp2, "<h1>");
                        str1[strcspn(str1, "\n")] = '\0';
                        fprintf(fp2, "%s</h1>", str1 + 1);
                    }
                }
                else{
                    fprintf(fp2, "%s", str1);
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