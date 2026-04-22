#include <stdio.h>

int main() {
    FILE *fp = fopen("muzukashi_kanji.txt", "w");
    fprintf(fp, "åKåN, ŸEŸG, —JŸT");
    fclose(fp);
    
    return 0;
}