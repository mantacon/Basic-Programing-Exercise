#include<stdio.h>
#include<stdlib.h>

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
        printf("%d %s %s\n" ,head->num, head->name, head->profile);
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

int main(void){
    FILE* fp;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        list_mbr* head = list2(fp);
        print_list(head);
        free_list(head);
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return -1;
    }

    return 0;
}


