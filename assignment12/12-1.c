#include<stdio.h>

#define N 10
int maze[N][N]={
  {8,8,8,8,8,8,8,8,8,8},
  {8,1,0,0,8,8,0,0,0,8},
  {8,0,8,0,0,0,0,8,0,8},
  {8,0,8,8,8,0,8,8,0,8},
  {8,0,0,8,8,0,0,8,0,8},
  {8,8,0,0,8,0,8,8,0,8},
  {8,0,8,0,8,0,0,8,0,8},
  {8,0,0,0,8,8,0,0,0,8},
  {8,8,8,0,0,0,0,8,0,8},
  {8,8,8,8,8,8,8,8,9,8}
};

void printMap(int maze[][N]){
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if(maze[i][j] == 8) printf("¡ ");
        else if(maze[i][j] == 0) printf("  ");
        else printf("› ");
    }
    printf("\n");
}

}
void searchWay(int maze[][N], int x, int y, int count){
    if(maze[y][x] == 9){
        printf("%d‚Å“ž’…\n", count);
        printMap(maze);
        printf("-----------------------------------\n");
        return;
    }

    maze[y][x] = 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for(int i = 0; i < 4 ;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx < N && ny > 0 && ny < N && maze[ny][nx] != 8 && maze[ny][nx] != 1){
            searchWay(maze, nx, ny, count + 1);
        }
    }
    maze[y][x] = 0;
    return;
}

int main (void){
    int count = 0;
    searchWay(maze, 1, 1, count);
    return 0;
}
