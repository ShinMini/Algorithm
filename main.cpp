#include <iostream>
<<<<<<< HEAD
#include <string> 
#include <vector>

using namespace std;

int main(){
    // a = 97, z = 122,  Z = 90, A= 65;  => Z+7 = 'a' 
    // alpa => 0~25(a~z), 26~50(A~Z)
    vector<char> alpa(52);
    vector<std::size_t> count(52);
    for(int i=0; i<alpa.size(); i++){
        if(i<26) alpa.at(i)=(97+i);
        else alpa.at(i)=(39+i);
    }

    string s;
    cin >> s;
    for(char num : s){

        for(int i=0; i<alpa.size(); i++){
            if( num == alpa.at(i)) {
                if(i<26) count.at(i)++;
                else count.at(i-26)++;
            }
        }
    }

    size_t result = 0;
    size_t max=0, sum = 0;
    for(int i=0; i<count.size(); i++){ 
        if(count[i]>=max){ 
        max = count[i];
        result = i;
    }}
    for(int i=0; i<count.size(); i++){ if(max == count[i]) sum++; }

    if(sum==1) cout << alpa[result + 26];
    else cout <<"?";


=======
#include <cmath>
using namespace std;

int main(){
    int N, M, count=0;
    cin >>N >> M;

    for(N; N<=M; N++){
        if(N==1) continue; // 1인경우.

        for(int i=2; i<=ceil(sqrt(N))+2; i++){

            if(i==N || ceil(sqrt(N))+2==i) {// 마지막 바퀴
                cout << N << "\n";
                break;
            }     // 소수인 경우
            if(N%i==0) break;   // 소수가 아닌 경우, 
        }
    }
>>>>>>> 0a8932dc325dc96837fa7bb06808877c190356d5
    return 0;
}
