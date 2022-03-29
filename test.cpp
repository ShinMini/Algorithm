#include <stdio.h>
#include <string.h>

int main(void)
{
   char str1[80], str2[80];   // declare arrays to put strings
   char * resp;   // declare pointer to select array that have longer lengths
   // 여기서 포인터 resp는 마치 새로운 배열을 선언한것처럼 사용된다. 

   printf (" 2개의 과일 이름 입력 : ");
   scanf("%s%s", str1, str2);
   // ex) sizeof(str1) =80 , strlen(str1) = length of input string
   
   if(strlen(str1)>strlen(str2))
   resp = str1;
   else
   resp = str2;
   printf("이름이 긴 과일은 :  %s\n", resp);
   return 0;
}