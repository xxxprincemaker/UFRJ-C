#include <stdio.h>

typedef struct fields {
    int campo1;
    float campo2;
    char campo3;
    //struct fields *pc;
} campos;


int main(void){

    int j = 0, *pj, *pi;
    campos cp[10], *p1 = cp;
    int k = sizeof(cp);
    float f = 10.5;
    int i = *(int*)&f;
    int *p = i;

    printf("%d\n", p);
    printf("%d\n", k);
    printf("%lx %lx %lx %lx\n", sizeof(int), sizeof(cp[0].campo2), sizeof(cp[0].campo3));

    (p1+0)->campo1 = 0;
    (p1+1)->campo1 = 8;
    (p1+2)->campo1 = 5;
    (p1+9)->campo3 = 6;
    printf("%d %d\n", (p1+2)->campo1, (p1+9)->campo3);
    
    //p1+0)->pc = (p1+1)->pc;
    printf("%d", sizeof(campos));


    return 0;
}