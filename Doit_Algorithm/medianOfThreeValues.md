``` cpp  
#include <stdio.h>

// 세 값의 중앙값을 구해보자 .
// let's find the middle value in three values
//  Let's find the median of three values.
int main(void)
{
    int a, b, c;
    int median; /* median of three values */
    printf("a의 값: "); scanf("%d", & a);
    printf("b의 값: "); scanf("%d", & b);
    printf("c의 값: "); scanf("%d", & c);
    median = a;
    // a b c 
    // a c b 
    if(b > median && c> median){
        median = (b<c)? b: c;
    } 
    // b c a
    // c b a
    else if(c < median && b< median) {
        median = (b<c)? c: b;
    }
    // b a c
    // c a b

    printf("median vlaue:  %d \n", median);
    return 0;
}
```
