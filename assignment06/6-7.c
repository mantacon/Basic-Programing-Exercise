#include<stdio.h>
#include<string.h>
#define SIZE 100

int main(void){
    char *buf[SIZE];
    char str[SIZE];
    int count[SIZE] = {0};
    printf("‘ÎÛ•¶š—ñ : ");
    fgets(str, SIZE, stdin);
    strcpy(str + (strlen(str) - 1)," ");//"\n"‚ğÁ‚·
    buf[0] = strtok(str, " ");
    count[0] += 1;
    int i = 1;
    while(1){
        char *tmp = strtok(NULL, " ");
        int flag = 0;
        if(tmp == NULL) break;
        for(int j = 0; j < i; j++){
            if(strcmp(buf[j], tmp) == 0) {
                count[j]++; 
                flag = 1;//“¯‚¶•¶š—ñ‚ªbuf‚É‚ ‚Á‚½flag = 1
                break;
            }
        }
        if(flag == 0){
            buf[i] = tmp;
            count[i] += 1;
            i++;
        }
    }
    int max = count[0];
    for(int j = 1; j < i; j++){
        if(max < count[j]) max = count[j];
    }
    printf("‚à‚Á‚Æ‚à•po‚µ‚½’PŒê: ");
    for(int j = 0; j < i; j++){
        if(max == count[j]) printf("%s   ", buf[j]);
    }
    printf("\n");
    printf("oŒ»‰ñ”: %d\n", max);
}