#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
// 함수를 만들거임 
int function(size_t N){
    int result; 
    int a, b, c;

    if(N<100) result = N;
    // 자연수 N은 1000보다 작으므로, 
    // 나머지 경우는, 100 이상 1000 이하의 경우 ex) 888
    else if(N==1000) result =144;   // 얘는 특이케이스니까 걍 이게 편함 ㅇㅇ for문에 조건절 하나 추가하는것보다 나은듯
    else {
        // 일단 99까지의 자연수 더해주고 시작
        result = 99;
        for(std::size_t i=100; i<=N; i++){  // i는 100부터 N까지의 자연수가 들어감 
                c = (i/100)%10;
                b = (i/10)%10;
                a = i%10;
        if(c-b == b-a) result++; 
        }
    }
    return result;
}

int main() {
    size_t N, R; 
    cin >> N; 

    R = function(N);
    std::cout << R;
    
    return 0;

}
