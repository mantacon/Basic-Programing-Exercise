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
    char temp[100][100];
    char type[100];
    int demension;
    int gomi;
    
    if((fp = fopen(argv[1], "r")) != NULL){
        for(int i = 0; ; i++){
            fscanf(fp, "%s", &temp[i]);
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

        for(int i = 0; i < demension; i++){
            for(int j = 0; j < demension; j++){
                printf("%d  ", dist_matrix[i][j]);
            }
            printf("\n");
        }

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
    else{
        printf("%s cannot open", argv[1]);
        exit(1);
    }
    
}