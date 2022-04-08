#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
    int N, i=0, input;
    int Max=0, Min=0 ;
    cin >> N;
    vector<int> v(N);

    while(i<N){
        cin >> input;

        v[i] = input;
        i++;
    }   // input 끝!
    i =0;// i다시 초기화
    Max = v[0]; // Max 초기값으로 배열 초기값 넣어줌
    Min = v[0]; // Min 초기값으로 배열 초기값 넣어줌

    while(i<N){
        if(Max < v[i]) Max = v[i];
        if(Min > v[i]) Min = v[i];
        i++;
    }

    cout << Min << " "<< Max;

    return 0;
}
