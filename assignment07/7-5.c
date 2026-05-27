#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int euclidean_distance(double *node1, double *node2) {
  double xd = node1[0] - node2[0];
  double yd = node1[1] - node2[1];
  double r  = sqrt(xd * xd + yd * yd) + 0.5;
  return (int)r;
}

double dtrunc(double x) {
    int k = (int) x;
    return (double)k;
}

int att_distance(double *node1, double *node2) {
  double xd = node1[0] - node2[0];
  double yd = node1[1] - node2[1];
  double rij  = sqrt((xd * xd + yd * yd) / 10.0);
  double tij = dtrunc(rij);

  if (tij < rij) return (int)tij + 1;
  else return (int) tij;
}

int main(int argc, char* argv[]){
    double** xy_matrix;
    int** dist_matrix;
    FILE* fp;
    FILE* fp2;
    char temp[100][100];
    char type[100];
    int demension;
    int gomi;
    char filename1[100],filename2[100];

    snprintf(filename1, sizeof(filename1), "files/tsp_files/%s.tsp", argv[1]);
    snprintf(filename2, sizeof(filename2), "files/tsp_opt_files/%s.opt.tour", argv[1]);
    if((fp = fopen(filename1, "r")) != NULL){
        for(int i = 0; ; i++){
            fscanf(fp, "%s", temp[i]);
            if(strcmp("EDGE_WEIGHT_TYPE:", temp[i]) == 0){
                fscanf(fp, "%s", type);
            }
            if(strcmp("DIMENSION:", temp[i]) == 0){
            fscanf(fp, "%d", &demension);
            }
            if(strcmp("NODE_COORD_SECTION", temp[i]) == 0){
                break;
            }
        }

        xy_matrix = (double**)malloc(sizeof(double*) * demension);
        for(int i = 0; i < demension; i++){
            xy_matrix[i] = (double*)malloc(sizeof(double) * 2);
        }
        dist_matrix = (int**)malloc(sizeof(int*) * demension);
        for(int i = 0; i < demension; i++){
            dist_matrix[i] = (int*)malloc(sizeof(int) * demension);
        }

        for(int i = 0; i < demension; i++){
            fscanf(fp, "%d", &gomi);
            fscanf(fp, "%lf", &xy_matrix[i][0]);
            fscanf(fp, "%lf", &xy_matrix[i][1]);
        }

        if(strcmp(type, "ATT") == 0){
            for(int i = 0; i < demension; i++){
                for(int j = 0; j < demension; j++){
                        dist_matrix[i][j] = att_distance(xy_matrix[i], xy_matrix[j]);
                }
            }
        }
        else{
            for(int i = 0; i < demension; i++){
                for(int j = 0; j < demension; j++){
                        dist_matrix[i][j] = euclidean_distance(xy_matrix[i], xy_matrix[j]);
                }
            }
        }
        
    }
    else{
        printf("%s cannot open", argv[1]);
        exit(1);
    }





    int sum = 0;
    int* opt_tour;
    opt_tour = malloc(sizeof(int) * demension);

    if((fp2 = fopen(filename2, "r")) != NULL){
        while(1){
            fscanf(fp2, "%s", temp[0]);
            if(strcmp("TOUR_SECTION", temp[0]) == 0) break;
        }
        for(int i = 0; i < demension; i++){
            fscanf(fp2, "%d", &opt_tour[i]);
        }
        for (int i = 0; i < demension - 1; i++){
            sum += dist_matrix[opt_tour[i] - 1][opt_tour[i + 1] - 1];
        }
        sum += dist_matrix[opt_tour[0] - 1][opt_tour[demension - 1] - 1];
        printf("Optimal tour length = %d", sum);
        fclose(fp2);
    }
    else{
        printf("%s cannot open", filename2);
    }

    free(opt_tour);
    for(int i = 0; i < demension; i++){
        free(xy_matrix[i]);
    } 
    free(xy_matrix);
    for(int i = 0; i < demension; i++){
        free(dist_matrix[i]);
    } 
    free(dist_matrix);
    fclose(fp);
}