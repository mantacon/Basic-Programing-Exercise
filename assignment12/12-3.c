#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 20
#define WIDTH 78
#define MAX_PAGE 10

void func(int m, int n, int dt[], int i, int* count, int* new_col, int* page, int results[][ROWS][WIDTH]){
    //count = {0 ~ 20}行 i = {0 ~ n}列のまとまりのi番目の要素 new_col = 列のまとまり page 改ページ数 
    if(i == n){
        (*count)++;
        if(*count == ROWS){
            *count = 0;
            (*new_col)++;
            if( ( (  (*new_col) + 1) * n * 2) > 78){
                (*page)++;
                *new_col = 0;
            }
        }
        return;
    }

    for(int j = 1; j < m + 1; j++){
        
        if(!(*page == 0 && *count == 0 && *new_col == 0) && results[*page][*count][(*new_col) * n] == 0){
            int prev_page = *page;
            int prev_count = *count - 1;
            int prev_col = *new_col;

            if(prev_count < 0){
                prev_count = ROWS - 1;
                prev_col--;

                if(prev_col < 0){
                    prev_page--;
                    prev_col = WIDTH / (n * 2) - 1;
                }
            }

            if(prev_page >= 0){
                for(int k = 0; k < n; k++){
                    results[*page][*count][((*new_col) * n) + k]
                        = results[prev_page][prev_count][(prev_col * n) + k];
                }
            }
        }

        results[*page][*count][( (*new_col) * n) + i] = j;
        func(m, n, dt, i + 1, count, new_col, page, results);
    }
}

void printFile(int n, int results[][ROWS][WIDTH], FILE* fp){
    int flag = 0;//flag = 1のとき行が埋まってない
    for(int i = 0; ;i++){
        for(int j = 0;j < 20 ; j++){
            for(int k = 0;k < (WIDTH / (n * 2)) * n ; k++){
                if(results[i][j][k] == 0) {
                    flag = 1;
                    fprintf(fp, "  ");
                }
                else fprintf(fp, "%d ", results[i][j][k]);
            }
            fprintf(fp, "\n");
        }
        if(flag == 1) break;
        fprintf(fp, "\n [ 次ページ ]\n");
    }
}

int main(int argc, char* argv[]){
    int m, n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    int dt[100] = {0};
    int results[MAX_PAGE][ROWS][WIDTH] = {0};//全部ゼロに初期化dekiruはず
    FILE* fp;
    if( (fp = fopen(argv[3], "w")) != NULL){
        int count = 0;
        int new_col = 0;
        int page = 0;
        func(m, n, dt, 0, &count, &new_col, &page, results);
        printFile(n, results, fp);
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return 0;
    }
    return 0;
}