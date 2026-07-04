#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct member{
    int num;                /* 登録番号 */
    char name[21];          /* 氏名 */
    char profile[61];       /* プロフィール */
    struct member *next;    /* 次の項目へのポインタ */
}list_mbr;

list_mbr* list(FILE* fp){
    list_mbr* before, *head;
    before = NULL;

    while(1){
        head = (list_mbr*)malloc(sizeof(list_mbr));
        if(fscanf(fp, "%d %s %s", &head->num, head->name, head->profile) == EOF) break;
        head->next = before;
        before = head;
    }
    return before;
}

void print_list(list_mbr* head){
    while(head != NULL){
        printf("%2d %s %s\n" ,head->num, head->name, head->profile);
        head = head->next;
    }
}

void free_list(list_mbr* head){
    list_mbr* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

}

void searchPos(list_mbr* head, char* pos){
    int count = 0;
    printf("  === %s の選手一覧 ===\n", pos);
    while(head != NULL){
        if(head->profile[0] == pos[0] && head->profile[1] == pos[1]){
            printf("%2d %s\n", head->num, head->name);
            count++;
        }
        head = head->next;
    }
    if(count == 0) printf("  ---該当者はいません---\n");
    else printf("該当者数: %d人\n", count);
}

int main(void){
    FILE* fp;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        list_mbr* head = list(fp);
        print_list(head);
        
        while(1){
            printf("\n");
            char pos[10];
            printf("ポジションは？ ");
            scanf("%s", pos);
            if(strcmp(pos, "0") == 0) break;
            searchPos(head, pos);
        }
        free_list(head);
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return -1;
    }

    return 0;
}


