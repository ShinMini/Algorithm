``` cpp 
#include <stdio.h>

using namespace std;

void spira(int n){
    int j, i;
    j=0; i=0;
    for(i=0; i<n; i++){
        for(j=0; j<n-i; j++)
            putchar(' ');
        for(j=0; j<1+2*i; j++)
            putchar('*');
        for(j=0; j<n-i; j++)
            putchar(' ');
        putchar('\n');
    }
    return;
}
void nrpira(int n){
    int j, i;
    j=0; i=0;

    for(i=0; i<n; i++){
        for(j=0; j<i; j++)
            putchar(' ');
        for(j=0; j<2*(n-i)-1; j++){
            printf("%d", i+1);
        }
        putchar('\n');
    }
}

int main(void)
{
    int n = 0;
    do{
        printf("몇 단 삼각형입니까? : ");
        scanf("%d", &n);
    } while(n<=0);

    spira(n);
    printf("\n");
    nrpira(n);


    return 0;
}

```
