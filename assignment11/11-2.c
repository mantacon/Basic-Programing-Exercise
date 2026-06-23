#include<stdio.h>
/*void judge(int d, int e, int f){
    int denominator = d*100 + e*10 +f;
    int numerator = 5 * denominator;
    int a = numerator / 100;
    int b = (numerator / 10) % 10;
    int c = numerator % 10;
    if(a != 0 && a != d && a != e && a != f && b != 0 && b != d && b != e && b != f && c != 0 && c != d && c != e && c != f){
        printf("%d / %d = 5\n", numerator, denominator);
    }else{}
}

void func(void){
    int d = 1, e = 0, f = 0;
    for(int i = 2; i < 10; i++){
        e = i;
        for(int j = 2; j < 10; j++){
            if(j == e){}
            else {
                f = j;
                judge(d, e, f);
            }
        }
    }
}バックトラックを使ってないため泣く泣く廃棄*/

void func(int x[], int i){
    if(i == 6){
        int abc = x[0] * 100 + x[1] * 10 + x[2];
        int def = x[3] * 100 + x [4] *10 + x[5];
        if(abc == 5 * def) printf("%d / %d = 5\n", abc, def);
    }

    for(int j = 1; j < 10; j++){
        int used = 0;
        for(int k = 0; k < i; k++){
            if(x[k] == j) used = 1;
        }
        if(used == 0){
            x[i] = j;
            func(x, i + 1);
            x[i] = 0;
        }
    }
}
int main(void){
    int x[6] = {0};
    func(x, 0);
    return 0;
}