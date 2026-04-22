#include<stdio.h>
#include<math.h>

int main(){
    int year=0;
    int price=0.0;
    printf("year=>");
    scanf("%d",&year);
    printf("price=>");
    scanf("%d",&price);
    if(year>=2019){
        printf("%.0lf‰~", floor(price * 1.10));
    } else if(year >= 2014){
        printf("%.0lf‰~", floor(price * 1.08));
    } else if(year >= 1997){
        printf("%.0lf‰~", floor(price * 1.05));
    } else if(year >= 1989){
        printf("%.0lf‰~", floor(price * 1.03));
    } else {
        printf("%d‰~");
    }
    return 0;
}