#include<stdio.h>

int wordCopy(char *a, char *b);

int main(void){
    char a[100];
    char b[100];
    printf("INPUT : ");
    scanf("%s",b);
    int n = wordCopy(a, b);
    printf("OUTPUT : %s, length = %d", a, n);
    return 0;
}
int wordCopy(char *a, char *b){
    int i;
    int j;
    for(i = 0; b[i] == ' '; i++);
    for(j = 0; b[i + j] != ' ' && b[i + j] != '\0'; j++){
        a[j] = b[i + j];
    }
    a[j] = '\0';
    return j;
}