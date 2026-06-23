#include <stdio.h>

typedef struct Animal {
    char name[16];                 
    char cry[16];                  
    struct Animal *children[5];    
    int num_children;              
} Animal;

void print_report(Animal *animal) {
    for (int i = 0; i < animal->num_children; i++) {
        print_report(animal->children[i]);
        printf("-");
    }
    printf("%s", animal->cry);
}

Animal neko    = {"猫",     "meow",   {NULL}, 0};
Animal tori    = {"鳥",     "tweet",  {NULL}, 0};
Animal ookami  = {"狼",     "howl",   {NULL}, 0};
Animal lion    = {"ライオン", "roar",  {NULL}, 0};
Animal nezumi  = {"ネズミ",  "squeak", {NULL}, 0};
Animal uma     = {"馬",     "neigh",  {NULL}, 0};
Animal ushi    = {"牛",      "moo",   {&ookami}, 1};
Animal inu     = {"犬",      "bark",  {&tori, &ushi}, 2};
Animal hitsuji = {"羊",      "baa",   {&uma}, 1};
Animal kaeru   = {"カエル",  "croak", {&lion, &nezumi, &hitsuji}, 3};
Animal kirin   = {"キリン", "OK", {&neko, &inu, &kaeru}, 3};

int main(void) {
    print_report(&kirin);
    printf("\n");
    return 0;
}