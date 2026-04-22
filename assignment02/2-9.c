#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand((unsigned int)time(NULL));
    int score=2;
    int dice1=0;
    int dice2=0;
    int i=1;
    for(;;i++){
        dice1=(rand()%6)+1;
        dice2=(rand()%6)+1;
        char c=0;
        printf("----------第%d回戦----------\n",i);
        printf("偶数ならo,奇数ならeと入力してね!!\n");
        scanf(" %c",&c);
        if(c=='s'){
            printf("終了!\n");
            break;
        }
        if((dice1+dice2)%2==0){
            if(c=='o'){
                printf("あたり!さいころの目は%dと%dでした\n",dice1,dice2);
                score++;
            }else{
                printf("はずれ!さいころの目は%dと%dでした\n",dice1,dice2);
                score--;
            }
        }else{
            if(c=='o'){
                printf("はずれ!さいころの目は%dと%dでした\n",dice1,dice2);
                score--;
            }else{
                printf("あたり!さいころの目は%dと%dでした\n",dice1,dice2);
                score++;
            }
        }
        printf("あなたの現在のスコアは%dです\n",score);
        if(score<=0){
            break;
        }
    }
    printf("ゲームオーバーです.あなたは%d回戦まで遊べました",i);
}