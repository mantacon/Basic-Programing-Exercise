#include<stdio.h>

#define SIZE 100

void eraseChar(char *a, int x, int y);

int main(void){
    char a[SIZE];
    int x;
    int y;
    printf("Œ³‚Ì•¶š—ñ : ");
    fgets(a, SIZE, stdin);
    printf("x y =");
    scanf("%d %d", &x, &y);
    if(x + y > SIZE) y = SIZE - x - 1;
    printf("x”Ô–Ú‚©‚çy•¶šíœ‚·‚é‚Æ : ");
    eraseChar(a, x, y);
    printf("%s", a);
}

void eraseChar(char *a, int x, int y){
    for(int i = x;; i++){
        a[i] = a[i + y];
        if(a[i + y] == '\0') break;
    }
}