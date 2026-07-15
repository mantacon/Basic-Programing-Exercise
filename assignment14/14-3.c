#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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


tree_mbr *search_mbr(int num, tree_mbr* root){
    if(root != NULL){
        if(root->num < num){
            return search_mbr(num, root->right);
        }
        if(root->num > num){
            return search_mbr(num, root->left);
        }
        return root;
    }
    return NULL;
}

void delete_mbr(int num, tree_mbr* root){
    if(root != NULL){
        if(root->num < num){
            delete_mbr(num, root->right);
        }
        if(root->num > num){
            delete_mbr(num, root->left);
        }
        if(root->num == num){

        }
    }
    
}

/* 第二引数に与えられた木の最右節点を探しだし，その内容を第一引数の
指し示す節点にコピーする．
コピーされた元の節点は必要なくなるので，これを切り離す． */
tree_mbr * del( tree_mbr* dstt,  tree_mbr *root )
{
	tree_mbr *q;

	if ( root->right != NULL )
		root->right = del( dstt, root->right );   /* 最右節点でなければ，右部分木を調べる */
	else {   /* 最右節点なので， */
		 dstt->num = root->num;  strcpy(dstt->name, root->name); strcpy(dstt->profile, root->profile);
		/* 削除すべき節点にこの節点の内容をコピー */
		q = root;  /* コピー後はこの節点が不要になるのでこれへのポインタをqに保持*/
		root = root->left; /* 左部分木を繰り上げる */
		free( q ); /* 領域解放 */
	}
	return( root );
}

tree_mbr *delete( int x, tree_mbr *root )
{
	tree_mbr *q;

	if ( root == NULL )   /* NULL なら見つからなかったことになる */
		printf("該当者はいません\n");
	else if ( x < root->num )
		root->left = delete(x, root->left);
		/* 現在の節点のキーよりも小さいので左部分木を探索 */
	else if ( x > root->num )
		root->right = delete( x, root->right );
		/* 現在の節点のキーよりも大きいので右部分木を探索 */
	else {                  /* 見つかった．この木の根を削除する */
		if ( root->right == NULL ) {
			q = root;
			root = root->left;    /* 左部分木だけなら，この木自身を左部分木に置き換える */
			free( q );      /* 領域解放 */
		}
		else  if ( root->left == NULL ) {
			q = root;
			root = root->right;    /* 右部分木だけなら，この木自身を右部分木に置き換える */
			free( q );       /* 領域解放 */
		}
		else {                       /* 左右の部分木があるならば */
			root->left = del(root, root->left );   /* 左部分木の最右節点をこの木の根に移動する. */
		}
	}
	return( root );
}

void tree_static(tree_mbr *root, int *node, int *leaf){
    if(root != NULL){
        (*node)++;
        if(root->right == NULL && root->left == NULL) (*leaf)++;
        tree_static(root->right, node, leaf);
        tree_static(root->left, node, leaf);
    }
}

void tree_depth(tree_mbr *root, int depth, int *best_depth){
    if(root != NULL){
        tree_depth(root->right, depth + 1, best_depth);
        tree_depth(root->left, depth + 1, best_depth);
    }
    
    if(depth > *best_depth) *best_depth = depth; 
}

void print_tree_static(tree_mbr *root){
    int node = 0, leaf = 0, whole_depth = 0, left_depth = 0, right_depth = 0;
    tree_static(root, &node, &leaf);
    tree_depth(root, 0, &whole_depth);
    tree_depth(root->left, 0, &left_depth);
    tree_depth(root->right, 0, &right_depth);

    printf("==================================\n");
    printf("             木の統計情報          \n");
    printf("==================================\n");
    printf("総ノード数        : %d\n", node);
    printf("木の高さ          : %d\n", whole_depth);
    printf("葉ノード数        : %d\n", leaf);
    printf("-----------------------------------\n");
    printf("平衡度判定:\n");
    printf("  左部分木の高さ: %d\n", left_depth);
    printf("  右部分木の高さ: %d\n", right_depth);
    printf("  高さの差      : %d\n", abs(left_depth - right_depth));
    if(abs(left_depth - right_depth) <= 1) printf("  判定結果      : 平衡\n");
    else if(abs(left_depth - right_depth) >= 4) printf("  判定結果      : 不平衡\n");
    else  printf("  判定結果      : やや不平衡\n");
    printf("====================================\n");
}

int main (void){
    FILE *fp;
    tree_mbr *root = NULL;
    int key;
    int num;
    if( (fp = fopen("zac_japan.txt", "r")) != NULL){
        for(tree_mbr *mbr = make_mbr(fp); mbr != NULL; mbr = make_mbr(fp)){
            root = make_tree(mbr, root);
        }
        print_tree(root, 0);
        print_tree_static(root);
        do{
            printf("-----------------------------------------------------------------------------------\n");
            printf("1:探索 2:削除 3:表示 4:終了 \n");
            scanf("%d", &key);
            switch(key){
                case 1:
                    printf("登録番号は？  ");
                    scanf("%d", &num);
                    tree_mbr* temp = search_mbr(num, root);
                    if(temp != NULL) printf("%d %s %s\n", temp->num, temp->name, temp->profile);
                    else printf("該当者はいません\n");
                    break;
                case 2:
                    printf("登録番号は？  ");
                    scanf("%d", &num);
                    delete(num, root);
                    break;
                case 3:
                    print_tree(root, 0);
                    print_tree_static(root);
                    break;
                default:
                    break;
            }
        }while(key != 4);
        delete_tree(root);
        fclose(fp);
    }else{
        fprintf(stderr, "cannnot open");
        return -1;
    }
    return 0;
}
