#include<stdio.h>
#include<stdlib.h>

struct student{
    int num;
    char name[21];
    int score;
};

void printout(struct student dt[], int n);

void quicksort(struct student dt[], int left, int right);

int main(int argc, char *argv[]){
    struct student dt[3000];
    FILE *fp;

    if((fp = fopen(argv[1], "r")) != NULL){
        int n = 0;
        while(fscanf(fp, "%d %s %d", &dt[n].num, dt[n].name, &dt[n].score) != EOF){
            n++;
        }
        printout(dt, n);
        quicksort(dt, 0, n - 1);
        printf("************************\n");
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

void quicksort(struct student a[], int left, int right){
    int pivot; // 基準値用変数
    int i, j;        // 配列内の位置
    struct student temp;

    if(left < right){
        i = left; j = right;
        pivot = a[(left + right) / 2].score; // 配列の真ん中の要素を基準値とする．
        do{
            while(a[i].score > pivot)
                /* 基準値以上の値を持つa[]の添字を先頭から順に探す */
                i++;
            while(pivot > a[j].score)
                /* 基準値以下の値を持つa[]の添字を先頭から順に探す */
                j--;
            if(i <= j){
                if(i < j){
                    /* 交換すべき状態ならa[i]とa[j]の内容を交換する */
                    temp = a[i]; a[i] = a[j]; a[j] = temp;
                }
                i++;  j--;   /* 次の要素を調べるために添字を変化させる */
            }
        } while(i <= j);        /* 調べる要素が残っている時には続ける */
        if(left < j)
            quicksort(a, left, j);  /* 基準値以下の項目が入っている範囲で再帰実行 */
        if(i < right)
            quicksort(a, i, right); /* 基準値以上の項目が入っている範囲で再帰実行 */
    }
}