#include <stdio.h>

using namespace std;

int main(void)
{
    int i, n;
    int sum;
    puts("find the sum from 1 to n. ");
    do{
        printf("put N : ");
        scanf("%d", &n);
    } while(n<=0);
    sum = 0;
    for(i =0; i<n; i++){
        sum +=i;
    }
    printf("the sum from 1 to n is => %d. \n", n, sum);

return 0;
}
