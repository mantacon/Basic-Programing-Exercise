#include <stdio.h>
#define SIZE 100

int wordCopy2(char *a, char *b);

int main(void){
    char a[SIZE];
    char b[SIZE];
    
    printf("INPUT : ");
    fgets(b, SIZE, stdin);
    if (wordCopy2(a, b) != 0) {
        while (wordCopy2(a, NULL) != 0) {}
    }
    return 0;
}

int wordCopy2(char *a, char *b){
    int i;
    int j;
    static char *p;
    if (b == NULL) {
        b = p;
    }
    for(i = 0; b[i] == ' ' || b[i] == '\n'; i++);//スペースをスキップ
    if (b[i] == '\0') {
        return 0;
    }
    for(j = 0; b[i + j] != ' ' && b[i + j] != '\n' && b[i + j] != '\0'; j++){
        a[j] = b[i + j];
    }
    a[j] = '\0';
    printf("OUTPUT : %s, length = %d\n", a, j);
    p = &b[i + j]; 
    return 1;
}