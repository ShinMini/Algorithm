#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int N, total;
    cin >> N >> total;

    vector<int> nums (N);
    for(int i=0; i<N; i++){
        cin >> nums.at(i);
    }

    // 5개의 카드중 3장의 카드를 사용해 만들 수 있는 조합의 경우의 수, 
    // 5C3
    int caseIndex = (N * N-1 * N-2) / 6; //  번 반복해주면 된다. 5의 경우, caseIndex = 10 가지 , 
    vector<int> caseArr(caseIndex); 

    for(int i=0; i<N; i++){
        for(int k=i+1; k<N-1; k++){
            for(int t = k+1; t<N-2; t++){
                caseArr.push_back(nums.at(i) + nums.at(k) + nums.at(t));
            }}}

    for(int c : caseArr){

        cout << c << " ";
    }

    return 0;
}
