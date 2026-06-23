#include<stdio.h>

void searchRoute(int map[][7], int route[], int i, int *best){
    if(route[i] == 6){
        if(i < *best){
            *best = i;
            printf("---------------Å’ZŒo˜HXV----------------\n");
            printf("Å’ZŒo˜H‚Ì’·‚³ = %d\n", *best);
            printf("Å’ZŒo˜H = ");
            for(int j = 0; j <= i; j++) printf("%d ", route[j]);
            printf("\n");
        }
        return;
    }
    for(int j = 0; ; j++){
        int here = route[i];
        int frag = 0;
        if(map[here][j] == -1) return;
        for(int k = 0; k < i; k++){
            if(map[here][j] == route[k]) frag = 1;
        }
        if(frag == 0){//ƒ_ƒu‚Á‚Ä‚È‚¢‚æ
            route[i + 1] = map[here][j];
            searchRoute(map, route, i + 1, best);
        }
    }
}
int main(void){
    int map[7][7] = { { 1, 2, 5, -1}, { 0, 3, 4, 5, -1}, { 0, 3, 5, -1}, { 1, 2, 4, -1}, { 1, 3, 6, -1}, { 0, 1, 2, 6, -1}, { 4, 5, -1}};
    int route[7] = {0};
    int best = 6;
    searchRoute(map, route, 0, &best);
    return 0;
}