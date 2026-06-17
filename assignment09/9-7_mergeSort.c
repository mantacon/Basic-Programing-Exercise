#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>


void mergeSort(int a[], int n, int *count)
{
    *count = 0;
    int dt[2][2][10000];
    int num[2][2];
    int in, out, indx;
    int i, j, k, p, q, r;

    in = 0;
    out = !in;

    for (i = 0; i < n / 2; i++){
        dt[in][0][i] = a[i];
        (*count)++;
    }
    for (j = 0; i < n; i++, j++) {
        dt[in][1][j] = a[i];
        (*count)++;
    }
        
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
                if (dt[in][0][i] > dt[in][1][j]) {
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

    printf("merge sort\n");

    QueryPerformanceCounter(&start);
    mergeSort(dt100, 100, &count);
    QueryPerformanceCounter(&end);

    printf("100: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 100 * (int)log2(100), count);

    QueryPerformanceCounter(&start);
    mergeSort(dt1000, 1000, &count);
    QueryPerformanceCounter(&end);

    printf("1000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 1000 * (int)log2(1000), count);

    QueryPerformanceCounter(&start);
    mergeSort(dt10000, 10000, &count);
    QueryPerformanceCounter(&end);

    printf("10000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 10000 * (int)log2(10000), count);
    return 0;
}