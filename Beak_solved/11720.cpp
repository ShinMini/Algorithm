#include <iostream>

using namespace std;

int solve1(std::size_t first){  // 1) using ASCII code 
    int result=0;
    char second;

    for(int i=0; i<first; i++){
        std::cin >> second;
        result += second-48;
    }
    return result;
}

int solve2(std::size_t first){
    int result = 0; 
    int second;
    cin >> second;

    for(int i=0; i<first; i++){
        result += second%10;
        second/=10;
    }
    return result;
}

int main(){
    int A, result=0;
    cin >> A;

    result = solve2(A);
    cout << result;

    return 0;
}
