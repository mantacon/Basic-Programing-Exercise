#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int num;
    char name[21];
    int score;
};

void printout(struct student dt[], int n);

void sortScore(struct student dt[], int n);

int main(int argc, char *argv[]){
    struct student dt[3000];
    FILE *fp;

    if((fp = fopen(argv[1], "r")) != NULL){
        int n = 0;
        while(fscanf(fp, "%d %s %d", &dt[n].num, dt[n].name, &dt[n].score) != EOF){
            n++;
        }
        sortScore(dt, n);
        fclose(fp);

        FILE *fp2;
        if((fp2 = fopen(argv[2], "w")) != NULL){
            for(int i = 0; i < n; i++){
                char grade;
                if(dt[i].score >= 90) grade = 'S';
                else if(dt[i].score >= 80) grade = 'A';
                else if(dt[i].score >= 70) grade = 'B';
                else if(dt[i].score >= 60) grade = 'C';
                else grade = 'D';
                fprintf(fp2, "%d,%s,%d,%c\n", dt[i].num, dt[i].name, dt[i].score, grade);
            }
            printf("success");
            fclose(fp2);
        }else{
            printf("%s cannot open", argv[2]);
            exit(1);
        }
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

void sortScore(struct student dt[], int n){
    for(int i = 0; i < n; i++){
        int m = i;
        for(int j = i; j < n - 1; j++){
            if(dt[m].score < dt[j + 1].score){
                m = j + 1;
            }else if(dt[m].score == dt[j + 1].score){
                if(dt[m].num > dt[j + 1].num) m = j + 1;
            }
        }
        struct student tmp = dt[m];
        dt[m] = dt[i];
        dt[i] = tmp;
    }
}