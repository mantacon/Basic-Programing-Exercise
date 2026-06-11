#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>


void quickSort(int a[], int left, int right, int *change){
    int pivot; // 基準値用変数
    int i, j;        // 配列内の位置
    int temp;

    if(left < right){
        i = left; j = right;
        pivot = a[(left + right) / 2]; // 配列の真ん中の要素を基準値とする．
        do{
            while(a[i] > pivot)
                /* 基準値以上の値を持つa[]の添字を先頭から順に探す */
                i++;
            while(pivot > a[j])
                /* 基準値以下の値を持つa[]の添字を先頭から順に探す */
                j--;
            if(i <= j){
                if(i < j){
                    /* 交換すべき状態ならa[i]とa[j]の内容を交換する */
                    temp = a[i]; a[i] = a[j]; a[j] = temp;
                    (*change)++;
                }
                i++;  j--;   /* 次の要素を調べるために添字を変化させる */
            }
        } while(i <= j);        /* 調べる要素が残っている時には続ける */
        if(left < j)
            quickSort(a, left, j, change);  /* 基準値以下の項目が入っている範囲で再帰実行 */
        if(i < right)
            quickSort(a, i, right, change); /* 基準値以上の項目が入っている範囲で再帰実行 */
    }
}

int main(void){
    int count = 0;
    FILE *fp;
    int dt100[100], dt1000[1000], dt10000[10000];
    if((fp=fopen("data100.txt", "r")) != NULL){
        for(int i = 0; i < 100; i++){
            fscanf(fp, "%d", &dt100[i]);
        }
        fclose(fp);
    }else{
        printf("cannot open");
    }

    if((fp=fopen("data1000.txt", "r")) != NULL){
        for(int i = 0; i < 1000; i++){
            fscanf(fp, "%d", &dt1000[i]);
        }
        fclose(fp);
    }else{
        printf("cannot open");
    }

    if((fp=fopen("data10000.txt", "r")) != NULL){
        for(int i = 0; i < 10000; i++){
            fscanf(fp, "%d", &dt10000[i]);
        }
        fclose(fp);
    }else{
        printf("cannot open");
    }

    LARGE_INTEGER freq;
    LARGE_INTEGER start, end;

    QueryPerformanceFrequency(&freq);

    printf("quick sort\n");

    QueryPerformanceCounter(&start);
    quickSort(dt100, 0, 100 - 1, &count);
    QueryPerformanceCounter(&end);

    printf("100: %.6f s, 比較回数 %d, 入れ替え回数 %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 100 * (int)log2(100), count);

    QueryPerformanceCounter(&start);
    quickSort(dt1000, 0, 1000 - 1, &count);
    QueryPerformanceCounter(&end);

    printf("1000: %.6f s, 比較回数 %d, 入れ替え回数 %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 1000 * (int)log2(1000), count);

    QueryPerformanceCounter(&start);
    quickSort(dt10000, 0, 10000, &count);
    QueryPerformanceCounter(&end);

    printf("10000: %.6f s, 比較回数 %d, 入れ替え回数 %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 10000 * (int)log2(10000), count);
    return 0;
}