#include <iostream>
#include <cmath>
#include <vector>
#include <string> 

using namespace std;

// 받아온 토큰값을 판별하는 함수 생성
int Token(int number){
    int token = 0;

    if(number<10) {token = number + number%10;
    } else if(number<100){
        token = number + (number/10)%10 + number%10;
    } else if(number<1000){
        token = number + (number/100) + (number/10)%10 + number%10;}
    else if(number<10000){
        token = number + (number/1000)%10 + (number/100)%10 + (number/10)%10 + number%10;}
    else token= number + (number/10000)%10 +(number/1000)%10 + (number/100)%10 + (number/10)%10 + number%10;

    return token;
}

void ArrayFunction(std::vector<int> A, int size){
    int token; 

    // 받아온 array size만큼 반복문 실행, 1부터 10000까지  
    for(int i=1; i<=size; i++){
        token = Token(i);
        A[token-1]++; // A array값 설정
    }

    for(int i=1; i<size; i++){
        if(A[i-1] == 0) {cout << i << "\n";}
        //cout << A[i] << "\n";
    }
}

int main(){

    std::vector<int> A(15000,0);
    ArrayFunction(A, 10000);

    /* 1~10000까지 d(n)한 값을 저장할 Array A 생성
     * A에 저장된 "n"을 d(n)공식에 넣어 반환하는 함수 생성
     *
     * 함수로부터 반환된 값( d(n) )을 저장할 Array B(10000) 생성
     * 저장된 B Array에 중복값 있는지 판별, i=1~10027 까지 반복해 판별, (d(n)의 최댓값 = 10026)
     * 
     * 1부터 나올 수 있는 최대 결과값인 d(n).Max 값까지의 크기를 갖고 있는 Array C 생성
     * Array C(10027), 
     * 
     * for(int i=1; i<=10027; i++){
     *      int returnB;
     *      returnB = Array B[i];   // d(n)된 값을 returnB로 옮겨줌
     *      Array C[returnB]++;     // 일치하는 해당 returnB 영역에 +1 해줌,
     *  // 이럴 경우, array C에는 0혹은 1, 그리고 2 이상의 value를 가진 index들이 있음, 
     *  }
     *  
     *  for(int i=1; i<=10000; i++){ 
     *
     *  // 만약 해당 C[i]의 값이 1일 경우, 해당 번호를 출력 해줌. 
     *  if(C[i]==1) cout << i << "\n";
     *
     * 판별되어 중복값이 없을 경우, 출력 확인 value를  저장해줄 Array C(1000) 생성
     * 만약 중복된 값이 있을경우, 해당 array C[i]에 
     *
     *
     *
     */

    return 0;
}
