#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;
// start point == 0, vs start point == x;
// when 0 => count zeropoint++; 
// when 1 => count continue; (skip) or discard;
// final => add zerosum[i] = zeropoint; , zeropoint = 0;(initialize)
// need variable => string o = "o", string x = "x", string token;, vector<int> zerosum;, int zeropoint

int main() {
    int input;
    cin >> input; 
    vector<string> oxquiz(input);   // ox점수표 저장.
    vector<int> oxcount(input, 0);  // oxcount 저장
    string score;

    for(int i = 0; i<input; i++){
        cin >> score; 
        oxquiz[i] = score;
    }

    // oxquiz에서 하나씩 정리 시작하자.
    // for문 시작전에 0으로 초기화
    for(int i=0; i<input; i++){
        int count, saveSize;
        count = 0;
        saveSize = oxquiz[i].size();

        for(int t=0; t <saveSize; t++){
            string token;
            token = oxquiz[i].substr(0, 1);

            if(token =="O") {
                count++;
                oxcount[i] += count; // oxcount 배열에 그간 저장된 count값을 더해준뒤
            } 

            else {  // x가 나온다면, 
                count =0;   // count를 초기화
            }
            oxquiz[i].erase(0, 1);
        }
        
            cout <<oxcount[i] << "\n";

    }



    return 0;
}
