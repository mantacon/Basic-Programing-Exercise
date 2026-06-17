#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
    int num;
    char name[21];
    int score;
};

void printout(struct student dt[], int n);

void mergeSort(struct student dt[], int num, int *count);

int main(int argc, char *argv[]){
    struct student dt[3000];
    FILE *fp;
    int count = 0;

    if((fp = fopen(argv[1], "r")) != NULL){
        int n = 0;
        while(fscanf(fp, "%d %s %d", &dt[n].num, dt[n].name, &dt[n].score) != EOF){
            n++;
        }
        printout(dt, n);
        mergeSort(dt, n, &count);
        printf("************************\n");
        printout(dt, n);
        printf("”äŠr‰ñ”%d, “ü‚ê‘Ö‚¦‰ñ”%d",n * (int)log2(n),  count);
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

void mergeSort(struct student a[], int n, int *count)
{
    struct student dt[2][2][3000];
    int num[2][2];
    int in, out, indx;
    int i, j, k, p, q, r;

    in = 0;
    out = !in;

    for (i = 0; i < n / 2; i++)
        dt[in][0][i] = a[i];
        (*count)++;
    for (j = 0; i < n; i++, j++)
        dt[in][1][j] = a[i];
        (*count)++;
    num[in][0] = n / 2;
    num[in][1] = n - n / 2;
    num[out][0] = 0;
    num[out][1] = 0;

    p = 1;

    do {
        i = 0;
        j = 0;
        indx = 0;

        do {
            if (num[in][0] >= p)
                q = p;
            else
                q = num[in][0];
            num[in][0] -= q;

            if (num[in][1] >= p)
                r = p;
            else
                r = num[in][1];
            num[in][1] -= r;

            k = num[out][indx];

            while (q != 0 && r != 0) {
                if (dt[in][0][i].score > dt[in][1][j].score) {
                    dt[out][indx][k] = dt[in][0][i];
                    i++;
                    q--;
                }
                else {
                    dt[out][indx][k] = dt[in][1][j];
                    j++;
                    r--;
                }
                k++;
                (*count)++;
            }

            while (q != 0) {
                dt[out][indx][k] = dt[in][0][i];
                i++;
                q--;
                k++;
                (*count)++;
            }

            while (r != 0) {
                dt[out][indx][k] = dt[in][1][j];
                j++;
                r--;
                k++;
                (*count)++;
            }

            num[out][indx] = k;
            indx = !indx;

        } while (num[in][0] > 0 || num[in][1] > 0);

        out = in;
        in = !in;

        p = p * 2;

    } while (p < n);

    for (i = 0; i < n; i++) {
        a[i] = dt[!out][!indx][i];
    }
}