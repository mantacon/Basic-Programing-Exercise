#include<stdio.h>
#define N 8
void quicksort(int a[], int left, int right);

int main(void)
{
    int n = N;
    int a[N] = {65, 90, 85, 70, 86, 92, 63, 85};
    int i;

    printf("ソート前:\n");
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    quicksort(a, 0, n-1);
    printf("ソート後:\n");
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}

void quicksort(int a[], int left, int right){
    int pivot, temp; // 基準値用変数と交換作業用変数
    int i, j;        // 配列内の位置

    if(left < right){
        i = left; j = right;
        pivot = a[(left + right) / 2]; // 配列の真ん中の要素を基準値とする．
        do{
            while(a[i] < pivot)
                /* 基準値以上の値を持つa[]の添字を先頭から順に探す */
                i++;
            while(pivot < a[j])
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
        
