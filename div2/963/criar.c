#include <stdio.h>

int main() {
    FILE *f = fopen("in","w+t");
    if(f==NULL) return 0;

    fprintf(f,"1\n");
    fprintf(f,"200000\n1 ");

    for(int i=1;i<200000;i++) fprintf(f,"%d ", i*2);


    fclose(f);
    return 0;
}