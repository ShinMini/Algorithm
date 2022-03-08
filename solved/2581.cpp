#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, M, count=0;
    cin >>N >> M;
    int min=0;

    for(N; N<=M; N++){
        if(N==1) continue; // 1인경우.

        for(int i=2; i<=ceil(sqrt(N))+2; i++){

            if(i==N || ceil(sqrt(N))+2==i) {// 마지막 바퀴
                count+=N;
                if(min==0)min=N;
                break;
            }     // 소수인 경우
            if(N%i==0) break;   // 소수가 아닌 경우, 
        }
    }
    (count !=0)?cout << count << "\n" << min : cout << -1;
    return 0;
}
