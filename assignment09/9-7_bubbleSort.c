#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>


void bubbleSort(int dt[], int num, int *count){
    for(int i = num; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(dt[j] > dt[j + 1]){
                int tmp = dt[j];
                dt[j] = dt[j + 1];
                dt[j + 1] = tmp;
                (*count)++;
            }
        }
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

    printf("bubble sort\n");

    QueryPerformanceCounter(&start);
    bubbleSort(dt100, 100, &count);
    QueryPerformanceCounter(&end);

    printf("100: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 100 * 100, count);

    QueryPerformanceCounter(&start);
    bubbleSort(dt1000, 1000, &count);
    QueryPerformanceCounter(&end);

    printf("1000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 1000 * 1000, count);

    QueryPerformanceCounter(&start);
    bubbleSort(dt10000, 10000, &count);
    QueryPerformanceCounter(&end);

    printf("10000: %.6f s, ”äŠr‰ñ” %d, “ü‚ê‘Ö‚¦‰ñ” %d\n",(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart, 10000 * 10000, count);
    return 0;
}