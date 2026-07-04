#include<stdio.h>
#include<stdlib.h>

typedef struct member{
    int num;                /* ìoò^î‘çÜ */
    char name[21];          /* éÅñº */
    char profile[61];       /* ÉvÉçÉtÉBÅ[Éã */
    struct member *next;    /* éüÇÃçÄñ⁄Ç÷ÇÃÉ|ÉCÉìÉ^ */
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
    printf("\n");
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

void search(list_mbr* head, int num){
    while(head->num != num){
        if(head->next == NULL) {
            printf("  ---äYìñé“ÇÕÇ¢Ç‹ÇπÇÒ---\n");
            return;
        }
        head = head->next;
    }
    printf("%2d %s %s\n", head->num, head->name, head->profile);
}

int main(void){
    FILE* fp;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        list_mbr* head = list(fp);
        print_list(head);

        printf("\n");
        while(1){
            int num;
            printf("ìoò^î‘çÜÇÕÅH ");
            scanf("%d", &num);
            if(num == 0) break;
            search(head, num);
        }
        free_list(head);
        fclose(fp);
    }else{
        fprintf(stderr, "cannot open");
        return -1;
    }

    return 0;
}