#include<stdio.h>

void func(int i, int modes[]){
    if(i == 9){
        /*for(int j = 0; j < 9; j++){
            printf("%d  ", modes[j]);
        }*/
        int sum = 0;
        int last = 0;
        for(int j = 0; j < 9; j++){
            switch(modes[j]){
                case 1:
                    sum += j + 1;
                    last = j + 1;
                    break;
                case 2:
                    sum -= j + 1;
                    last = j + 1;
                    break;
                case 3:
                    int k = j;
                    while(modes[k - 1] == 3){
                        k--;
                    }
                    if(modes[k - 1] == 1 ){
                        sum -= last;
                        sum += 10 * last + j + 1;
                        last = 10 * last + j + 1;
                    } 
                    else if(modes[k - 1] == 2){
                        sum += last;
                        sum -= (10 * last + j + 1);
                        last = 10 * last + j + 1;
                    } 
                    break;
            }
        }
        if(sum == 100){
            for(int j = 0; j < 9; j++){
                switch(modes[j]){
                    case 1:
                        if(j == 0) printf(" %d", j + 1);
                        else printf(" + %d", j + 1);
                        break;
                    case 2:
                        printf(" - %d", j + 1);
                        break;
                    case 3:
                        if(j == 8) printf("%d", j + 1);
                        else printf("%d", j + 1);
                }
            }
            printf(" = 100\n");
        }
        return;
    }

    for(int mode = 1; mode < 4; mode++){
        int flag = 0;
        switch(mode){
            case 1://plus
                modes[i] = 1;
                break;
            case 2://minus
                modes[i] = 2;
                break;
            case 3://merge
                modes[i] = 3;
                if(i == 0) {
                    flag = 1;
                    modes[i] = 0;
                }
                break;
        }
        if(flag == 1) break;
        func(i + 1, modes);
        modes[i] = 0;
    }
}
int main(void){
    int modes[9] = {0};
    func(0, modes);
    return 0;
}
