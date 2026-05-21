#include<stdio.h>

void charCopy(char *a, char *b);

int main(void){
    char a[100];
    char b[100];
    printf("INPUT : ");
    scanf("%s",b);
    charCopy(a, b);
    return 0;
}
void charCopy(char *a, char *b){
    int i = 0;
    for( i = 0; b[i] != '\0'; i++){
        a[i] = b[i];
    }
    a[i] = '\0';
    printf("OUTPUT : %s, length = %d", a, i);
}