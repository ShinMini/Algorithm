// scanf 함수는 중간에 공백이 포함된 문자열을 한번에 입력할 수 없다. 
// 이때 공백을 넣고싶다면, gets함수를 사용한다. 
// gets함수는 중간의 공백이나 탭 문자를 포함하여 문자열 한 줄을 입력합니다. 
// scanf 함수와 gets 함수는 입력되는 문자열의 크기가 배열 크기를 넘어설 위험성이 있습니다. 
이러면,  할당되지 않은 메모리 공간을 차지해 문제가 생길 수 있음. 
안전하게 문자열을 입력하려면, 실행 도중에 배열 크기를 확인하는 fgets 함수를 사용하는 것이 좋음. 
fgets함수는 최대배열의 크기까지만 문자열을 입력함. 

char *gets(char * str)   // gets 함수 원형

개행 문자 제거 과정
strlen 함수는 배열명을 인수로 받아 널 문자 이전까지의 문자 수를 세어 반환한다. 
사용할때 string.h 헤더 파일을 인클루드 한다. 
ex) str[strlen(str) -1] = '\0'
// 널 이전까지의 문자 수 10개, 
// 9는 배열에서 개행문자가 저장된 곳의 위치
// 개행문자를 널 문자로 바꿈. 

버퍼에서 남아있는 개행문자를 지우는 바업은
개행 문자를 읽어들이는 무자 입력 함수를 호출하면 된다. 
// getchar();, scanf("%*c");, fgetc(stdin)
// 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 사용 X


문자열 입력 함수. \
1. pus, fputs
puts 함수 원형
int puts(const char *str); // 문자열을 출력하고 자동 줄 바꿈
int fputs(const char * str, FILE *stream);  // 문자열을 출력하고 줄 바꾸지 않음. 
// puts와 fputs 함수 모두 정상 출력된 이후, 0을 반환하고 출력에 실패하면, -1(EOF)를 반환합니다. 


문자열 연산 함수. 
문자열은 배열에 저장하므로 문자열의 대입, 길이 계산 빅, 붙이기 등 문자열 연산 방법은 모두 함수로 수행하빈다.
따라서 문자열을 자유롭게 다루려면 연산 함수의 구현 방법을 이해하고 사용법을 익혀야 한다. 


문자열을 대입하는 strcpy 함수.
// 이런 함수를 문자열 연산 함수라고 한다. 사용시 string.h 헤더 파일을 인클루드 해야함. 
strcpy 는 string copy의 약자 즉, 문자열 복사의 약어이다. 
사용법, strcpy(str1, str2) // str1 -> 복사 받을 곳, str2 -> 복사할 내용. 


원하는 개수의 문자만을 복사하는 strncpy 함수
strncpy 함수는 문자열을 복사할 땜 ㅜㄴ자의 수를 지정할 수 있다. 
strncpy=> string numbers copy
사용 법 -> strncpy(str, "apple-pie", 5); // apple-pie 앞에 5개의 문자만 char 배열 str에 복사함. 


 문자열을 붙이는 strcat, strncat 함수

 strcpy 함수는 초기화된 문자열을 지우고 새로운 문자열로 바꿀 때 사용한다. 
 반면 배열에 있는 문자열 뒤에 이어 붙일 때는 strcat 또는 strncat 함수를 사용한다. 

일종의 더하기 연산자같은 역할이며, 둘의 차이는
strcat function is adding string arrays, 
strncat function is adding set numbers string before

for instance,
str = "straw";

strcat(str, "berry"); // add "berry" to str array

strncat(str, "piece", 3);  // adding 3 strings to str array
 

 -- 
 result 
 strawberry
 strawberrypie

 ---
 구현 방식은
 먼저 붙여넣을 배열에서 널 문자의 위치를 찾고,
 그 위치부터 붙여넣을 문자열을 복사한다. 
 붙여넣기가 끝난 이후에는 널 문자를 저장하여 마무리한다. 

// 중간 결론, 아무래도 string 즉, char[] 형식의 array 는 pointer 형식으로 접근, 
// 초기 주소값을 찾고, 배열 중간에 있는 개행문자(\n) 또는 null (\n) value 등 
// event 를 중심으로 접근해 algorithm을 풀어나가는 방식이 접근법이라고 생각한다. 

precautions for using strcat function !!!

strcat function can invade(침범하다) memory when used.
// strcat 함수는 문자열을 덧붙이는 것이므로 붙여넣기가 되는 배열의 크기가 충분히 커야합니다.
strcat 함수는 붙여넣을 공간의 주소를 증가시키므로 공간이 부족한 경우 할당하지 않은 다른 메모리 영역을 invade 할 수 있습니다. 
this problem is when do compiling can not find problem, we can find problem running program after finished compile

when using strcat function need to optimizing array !!!

strcat 함수로 붙여넣기 ㅈ너에 먼저 널 문자의 위치를 찾으므로 반드시 초기화를 해야합니다. 
배열이 초기화되지 않으면, 쓰레기 값의 중간부터 붙여넣을 가능성이 큽니다. 

배열 초기화 방법
1. char str[80] = {'\0'};  // 명시적으로 널 문자를 초기화 
2. char str[80] = {0};// 널 문자의 아스키코드 값으로 초기화 
3. char str[80] = "";//  큰 따옴표 안에 아무것도 없으므로 널 문자만 초기화 
4. char str[80] = '\0';// 첫 번째 요소만 별도로 초기화 


문자열 길이를 계산하는 strlen 함수
문자열을 저장하는  char 배열은 다양한 길이의 문자열을 저장할 수 있도로 충분히 크게 선언해서 사용합니다.
따라서 배열에 저장된 문자열의 길이는 배열의 크기와 다를 수 있습니다. 
so length of strings in array can different with size of array
만약 배열에 저장된 문자열의 실제 길이를 알고 싶으면 strlen 함수를 사용합니다. 
ex) strlen(str)


strlen 함수는 배열에 저장된 문자열에서 널 문자가 나올 때까지 문자 수를 세어 반환합니다. 
따라서 배열의 크기와는 상관없이 실제 저장된 문자열의 길이를 확인할 수 있습니다. 
문자열의 길이를 반환하므로 반환갑을 바로 비교하거나 수식의 일부로 사용할 수 있음. 

문자열을 비교하는 strcmp, strncmp 함수
strcmp function is return the result that compare both strings in dictionary order.
// ex) strcmp(str1, st2) 
1. str1이 str2보다 빠른순서면, 1 반환 
2. str1이 str2보다 늦은 순서면, -1 반환 
1. str1이 str2보다 같은 문자열이면 0반환 

strcmp 함수는 아스키 코드의 순서에 따라 사전순을 구분한다. 즉, 
string 의 length만큼 작업시간이 소요된다. 첫번째 string(char[0])부터 마지막 string(char[char a.length()]);


