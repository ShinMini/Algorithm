#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int T, W, Input, check, temp;
    vector<int> Prime(30);

    cin>>T;
    for(int i=0; i<T; i++){
        cin >> Input;

        check = ceil(sqrt(Input))+2;
        Prime.resize(check/2);

        for(int t=2; t<=Input; t++){   //소수 판별 2부터 input된 숫자까지 

            for(int C=2; C<=check; C++){
                if((t%C)==0 && t!=C) break;
                if(C==check) Prime.push_back(t);
            }
        }
     for(int t=0; t<Prime.size(); t++){
            //cout << Prime.at(t) << "  ";
        }
        W = Prime.size()-1;
        //cout << " Prime[" << W << "] " << Prime.at(W) << "\n";
        bool isit = true;
        while(isit){
            if(W==0) break;

            if(Input >= Prime.at(W) * 2) {   // 뒤에서부터 값 하나씩 비교
                temp = Input - Prime.at(W);     // temp => 16-7 = 9
                //cout << "Input => " << Input << ", Prime.at(" << W << ")  => " << Prime.at(W) <<  "|| Input-Prime => " << temp << "\n";

                // temp 값이 Prime 배열 내에 있는지 검색, , 뒤에서부터
                for(int s=0; s<Prime.size(); s++){
                    if(Prime.at(s) == temp) {// 일치하는 값(9)이 있을 경우, 해당 값 출력이후 반복문 종료
                        cout << Prime.at(W) << " " << temp << "\n";
                        isit = false;
                        break;
                    }
                }
            }
            W--;
        }
   
        Prime = {}; // 초기화 진행
    }

    return 0;
}





// 전제조건, 답이 여러가지라면, 두 소수의 차이가 가장 작은 값 출력, 
    //
    // (A)...그렇다면, 배열의 값을 2배씩 먼저 해줌, 그리고 input(16)과 비교, 작거나 같은값이 나올때 까지
    // 두 소수의 합으로 나옴. 
    // 16의 소수 2, 3, 5, 7, 11, 13
    // 만약 같은 값이 나온다면(16), -> 해당 값 두번 출력(8, 8), 
    // 더 작은 값이 나온다면(7+7=14),  
    // input(16)과 해당값(7)을 뺀 값(9)을 비교, 만일 해당 값이 배열 내에 없다면, ...(B)
    // num(7)을 배열에서 삭제한뒤, (0을 집어넣든지,, erase하던지..)
    // 다시, 과정 ...(A) 반복
    //
    // 두번째 반복에서는 num(5+5=10)이 나옴. 
    // 같이 input(16)과 해당값(5)를 뺀 값(11)을 비교, 이 경우 해당 값이 배열 내에 있기 때문에, ...(C)
    // 두 값을 출력해줌, 5, 11
    //
    //
    // ex) ... 는 나온 값의 차이가 적을 수 있어 보류, 



    //-----------
    //자 뒤에서부터 더할건데, 두개로 해결 안되면, 3개 4개.. 그 이상 갈거임..
    // 뒤에서 부터 하나씩(num) 더함, Input(10)이 넘는지 체크, 넘는다면, 해당 배열 제거, 
    // 안넘는다면, (num)출력한뒤, Input-=num , => 3, 
    // 다시 뒤에서 부터 하나씩 더해줌. 0이 될때 까지 7, 5, 3,2,  


