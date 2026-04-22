#include<stdio.h>
#include<math.h>

typedef struct{
    int x;
    int y;
    int z;
}strVec;

double vecMagnitude(strVec);

double vecDotProduct(strVec,strVec);

int main(void){
    strVec vec1={1,3,5};
    strVec vec2={3,4,7};
    printf("Vector1:(%d,%d,%d)\n",vec1.x,vec1.y,vec1.z);
    printf("Vector2:(%d,%d,%d)\n",vec2.x,vec2.y,vec2.z);
    printf("É”[deg]=%d",acos(vecDotProduct(vec1,vec2)/(vecMagnitude(vec1)*vecMagnitude(vec2))));
}

double vecMagnitude(strVec vec){
    return sqrt(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

double vecDotProduct(strVec vec1,strVec vec2){
    int ans=vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
    return ans;
}