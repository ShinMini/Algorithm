#include <iostream>
using namespace std;
int main(){
    int N, T=0;
    cin >> N;

    if(N==4 || N==7) {   // 유일하게 안됨.
        cout << -1;
        return 0;
    }

    while(N>12){ //12, 11, 10, 9, 8까지가 들어옴. // 10인경우 제외하고 3으로 나눴을때, 수와 일치
        N-=5;
        T++;
    }

    if(N==10) cout << T+2;
    else cout << T+N/3;

    return 0;
}
