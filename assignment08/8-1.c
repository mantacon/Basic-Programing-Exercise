#include<stdio.h>
#include<stdlib.h>

struct student{
    int num;
    char name[21];
    int score;
};

void printout(struct student dt[], int n);

int main(int argc, char *argv[]){
    struct student dt[3000];
    FILE *fp;

    if((fp = fopen(argv[1], "r")) != NULL){
        int n = 0;
        while(fscanf(fp, "%d %s %d", &dt[n].num, dt[n].name, &dt[n].score) != EOF){
            n++;
        }
        printout(dt, n);
        fclose(fp);
    }else{
        printf("%s cannot open", argv[1]);
    exit(1);
    }
    
}

void printout(struct student dt[], int n){
    for(int i = 0; i < n; i++){
        printf("%4d %-20s %3d\n", dt[i].num, dt[i].name, dt[i].score);
    }
}

