#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int I, M;
    while(true){    // 들어온 수가 0이 아닐때 까지 반복, 
        cin >> I;
        if(I==0) break;

        std::size_t count;
        count=0;

        for(int i=I+1; i<=2*I; i++){ // I 부터 2I까지 돌며 소수인지 판별
            M = ceil(sqrt(i))+2;  // 루트 I 해준뒤, 올림해줌, 내가 생각한 소수 공식 +2를 해주는 이유, 1도 포함시키기 위해, 

            for(int t=2; t<=M; t++){ // 이때, t는 1과 자기 자신을 제외한 수M이 되기 전 까지 반복해서 나눠줌. 
                // 나눴을때, 나머지가 0이된다면, 1과 자기 자신을 제외
                if(i%t==0 &&i!=t) break;// prime number(i) => can't division without both 1 and itself, 
                if(t==M) {
                    cout << " t : >> "<< t << " M >> " << M << " i >> " << i << "\n";
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
        return 0;
}
