#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void selectionSort(int dt[], int n, int *count){
    for(int i = 0; i < n; i++){
        int m = i;

        for(int j = i; j < n - 1; j++){
            if(dt[m] < dt[j + 1]){
                m = j + 1;
            }
        }

        int tmp = dt[m];
        dt[m] = dt[i];
        dt[i] = tmp;
        (*count)++;
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

    printf("selection sort\n");

    QueryPerformanceCounter(&start);
    selectionSort(dt100, 100, &count);
    QueryPerformanceCounter(&end);

    printf("100: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 100 * 100, count);

    QueryPerformanceCounter(&start);
    selectionSort(dt1000, 1000, &count);
    QueryPerformanceCounter(&end);

    printf("1000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 1000 * 1000, count);

    QueryPerformanceCounter(&start);
    selectionSort(dt10000, 10000, &count);
    QueryPerformanceCounter(&end);

    printf("10000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 10000 * 10000, count);
    return 0;
}