``` cpp  
#include <stdio.h>

using namespace std;

int main(void)
{
    int height, width, i, j;
    puts("print rectangle ");
    printf("width :");
    scanf("%d", &width);
    printf("height :");
    scanf("%d", &height);


    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf(" * ");
        }
        printf("\n");
    }

return 0;
}
```
