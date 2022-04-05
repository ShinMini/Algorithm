#include <stdio.h>

using namespace std;

int main(void)
{
    int dan, i, t;
    printf("몇단 삼각형입니까? :");
    scanf("%d", &dan);

    for(i=0; i<dan; i++){
        do{
        printf("*");
        t++;
        }while(t<=i);
        printf("\n");
        t=0;
    }

    return 0;
}

