#include<stdio.h>
#include<stdlib.h>

typedef struct member{
    int  num;               /* 登録番号 */
    char name[21];          /* 氏名 */
    char profile[61];       /* プロフィール */ 
    struct member *left;    /* 左部分木を指すポインタ */
    struct member *right;   /* 右部分木を指すポインタ */
}tree_mbr;  
 
tree_mbr *make_tree(tree_mbr *mbr, tree_mbr *root){
    if(root == NULL){
        root = mbr;
    }
    else if(root->num > mbr->num){//smaller
        root->left = make_tree(mbr, root->left);
    }
    else if(root->num < mbr->num){//bigger
        root->right = make_tree(mbr, root->right);    
    }else{
        fprintf(stderr, "same num err");
        return root;
    }
    return root;
}

tree_mbr *make_mbr(FILE *fp){
    tree_mbr *mbr;
    mbr = (tree_mbr *)calloc(1, sizeof(tree_mbr));
    if(fscanf(fp, "%d %s %s", &mbr->num, mbr->name, mbr->profile) == EOF) {
        free(mbr);
        return NULL;
    }
    mbr->left = NULL;
    mbr->right = NULL;
    return mbr;
}

void print_tree(tree_mbr *root, int depth){
    if(root != NULL){
        print_tree(root->right, depth + 1);
        for(int i = 0; i < depth; i++) printf("              ");
        printf("<%d,%s>\n", root->num, root->name);
        print_tree(root->left, depth + 1);
    }
}

tree_mbr* delete_tree(tree_mbr* root)
{
	tree_mbr* tmp = NULL;

	if (root != NULL) {
		if (root->right != NULL) {
			root->right = delete_tree(root->right);
		}
		else if (root->left != NULL) {
			root->left = delete_tree(root->left);
		}
		else {
			tmp = root;  root = root->left; 
			free(tmp);
		}
		if (root != NULL) {
			if (root->left != NULL) {
				root->left = delete_tree(root->left);
			}
			else {
				tmp = root; root = root->left; 
				free(tmp);
			}
		}
		else {}
	}
	else {}

	if (root != NULL) {	
		root = delete_tree(root); 
	}
	else {}

	return root;
}

int main (void){
    FILE *fp;
    tree_mbr *root = NULL;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        for(tree_mbr *mbr = make_mbr(fp); mbr != NULL; mbr = make_mbr(fp)){
            root = make_tree(mbr, root);
        }
        print_tree(root, 0);
        delete_tree(root);
        fclose(fp);
    }else{
        fprintf(stderr, "cannnot open");
        return -1;
    }
    return 0;
}
