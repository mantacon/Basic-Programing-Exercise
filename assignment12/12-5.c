#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

/*
-最近近傍法の解をbestとしてバックトラック総当たりの探索関数getAns
-現在までの合計＞bestだったら強制打ち切り
-best = 10000で課題の条件１がない場合
-getAnsの引数にmodeとか入れて、枝刈をするかしないかをコマンドラインから指定したい
-clockでじかんをはかって比較しよう！３つを比較する感じですね
-*/

int euclidean_distance(double point1[], double point2[]) {
  double xd = point1[0] - point2[0];
  double yd = point1[1] - point2[1];
  double r  = sqrt(xd * xd + yd * yd) + 0.5;
  return (int)r;
}

void getPoints(char filename[], double **points, int num){
    FILE* fp;
    char trashLine[100];
    if( (fp = fopen(filename, "r")) != NULL){
        for(int i = 0; i < 6; i++){
            fgets(trashLine, sizeof(trashLine), fp);
        }
        int trash;
        for(int i = 0; i < num; i++){
            fscanf(fp, "%d", &trash);
            fscanf(fp, "%lf", &points[i][0]);
            fscanf(fp, "%lf", &points[i][1]);
        }
        fclose(fp);
    }else{
        fprintf(stderr,"cannot open");
        return;
    }
}

void getDist(double** points, int **dist, int num){
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            dist[i][j] = euclidean_distance(points[i],points[j]);
        }
    }
}

int getTempAns(int **dist, int num, int i, int route[]){
    if(i == num){
        int sum = 0;
        for(int j = 0; j < num; j++){
            if(j == num - 1) sum += dist[route[j]][0];
            else sum += dist[route[j]][route[j + 1]];
        }
        printf("----------最良解更新----------\n");
        printf("最短巡回路長 = %d\n", sum);
        printf("順列 = (");
        for(int j = 0; j < num - 1; j++) printf("%d, ", route[j]);
        printf("%d)\n", route[num - 1]);
        return sum;
    }

    if(i == 0) {
        route[i] = i;
        return getTempAns(dist, num, i + 1, route);
    }else{
        int nearestLong = 10000;
        for(int j = 0; j < num; j++){
            if(dist[route[i - 1]][j] < nearestLong){
                int k = 0;
                while(k < i){//ダブり検出
                    if(route[k] == j) break;
                    k++;
                }
                if(k == i) {
                    route[i] = j;
                    nearestLong = dist[route[i - 1]][j];
                }
            }
        }
        return getTempAns(dist, num, i + 1, route);
    }
    
}

void getAns(int **dist, int num, int i, int route[], int *best, int *sum, int mode){
    if(i == num){
        *sum += dist[route[0]][route[num - 1]];
        if(*best > *sum){
            printf("----------最良解更新----------\n");
            printf("最短巡回路長 = %d\n", *sum);
            printf("順列 = (");
            *best = *sum;
            for(int j = 0; j < num - 1; j++) printf("%d, ", route[j]);
            printf("%d)\n", route[num - 1]);
        }
        *sum -= dist[route[0]][route[num - 1]];
        return;
    }

    if(i == 0) {
        route[i] = i;
        getAns(dist, num, i + 1, route, best, sum, mode);
    }else{
        for(int j = 0; j < num; j++){
            int k = 0;
            while(k < i){//ダブり検出
                if(route[k] == j) break;
                k++;
            }
            if(k == i) {
                *sum += dist[route[i - 1]][j];
                if(mode == 1 && *sum >= *best) {
                    *sum -= dist[route[i - 1]][j];
                    continue;
                }
                route[i] = j;
                getAns(dist, num, i + 1, route, best, sum, mode);
                *sum -= dist[route[i - 1]][j];
            }
        }
    }
}

int main(int argc, char* argv[]){
    clock_t start, end;
    double times;
    start = clock();

    double **points;
    int **dist;
    int *route;
    int num = atoi(argv[1]);

    points = (double **)calloc(num, sizeof(double *));
    for(int i = 0; i < num; i++) points[i] = (double *)calloc(2, sizeof(double));
    dist = (int **)calloc(num, sizeof(int *));
    for(int i = 0; i < num; i++) dist[i] = (int *)calloc(num, sizeof(int));
    route = (int *)calloc(num, sizeof(int));

    char filename[100];
    snprintf(filename, sizeof(filename), "tsp_files/rue%s.tsp", argv[1]);
    getPoints(filename, points, num);
    getDist(points, dist, num);
    int best = getTempAns(dist, num, 0, route);
    int sum = 0;
    int mode = atoi(argv[2]);//0:枝刈nasi,1:枝刈あり,2:枝刈あり、最近近傍解ナシ
    if(mode == 2) best = 10000;
    getAns(dist, num, 0, route, &best, &sum, mode);

    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f[s]", times);


    for(int i = 0; i < num; i++){
        free(points[i]);
    } 
    free(points);
    for(int i = 0; i < num; i++){
        free(dist[i]);
    } 
    free(dist);
    free(route);
    return 0;
}