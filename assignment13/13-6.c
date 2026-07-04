#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct member{
    int num;                /* 登録番号 */
    char name[21];          /* 氏名 */
    char profile[61];       /* プロフィール */
    struct member *next;    /* 次の項目へのポインタ */
}list_mbr;

list_mbr* list2(FILE* fp){
    list_mbr* before, *head, *tmp;
    before = NULL;
    while(1){
        head = (list_mbr*)malloc(sizeof(list_mbr));
        if(fscanf(fp, "%d %s %s", &head->num, head->name, head->profile) == EOF) break;
        if(before != NULL && head->num > before->num){
            tmp = before;
            while(tmp->next != NULL && head->num > tmp->next->num){
                tmp = tmp->next;
            }
            head->next = tmp->next;
            tmp->next = head;
        }else{//先頭に入る
            head->next = before;
            before = head;
        }
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

list_mbr* searchPos(list_mbr* head, char* pos){
    list_mbr* result;
    list_mbr* result_head = NULL;
    list_mbr* result_tail;
    int first = 1;
    while(head != NULL){
        if(head->profile[0] == pos[0] && head->profile[1] == pos[1]){
            result = (list_mbr*)malloc(sizeof(list_mbr));
            result->num = head->num;
            strcpy(result->name, head->name);
            strcpy(result->name, head->name);
            if(first == 1) {
                result_head = result;
                result_tail = result;
                first = 0;
            }
            result_tail->next = result;
            result_tail = result;
        }
        head = head->next;
    }
    result_tail->next = NULL;
    return result_head;
}

int main(void){
    FILE* fp;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        list_mbr* head = list2(fp);
        print_list(head);
        
        while(1){
            printf("\n");
            char pos[10];
            int count = 0;
            printf("ポジションは？ ");
            scanf("%s", pos);
            if(strcmp(pos, "0") == 0) break;
            printf("  === %s の選手一覧 ===\n", pos);
            list_mbr* result = searchPos(head, pos);
            if(result == NULL) printf("  ---該当者はいません---\n");
            else{
                while(result != NULL){
                    printf("%2d %s\n", result->num, result->name);
                    count++;
                    result = result->next;
                }
                printf("該当者数%d人\n", count);
            }
        }
        free_list(head);
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return -1;
    }

    return 0;
}


