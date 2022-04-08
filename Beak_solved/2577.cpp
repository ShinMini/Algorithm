#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int i = 0; // 반복문 변수
    int A, B, C;
    cin >> A >> B >> C;

    int sum = A * B * C;
    // sum 자릿수 판별기
    int sums = sum;
    int sumscount=0;

    while(sums>0){       // sums가 0이상일 때 실행, 
        sums /=10;
        sumscount++;
    }

    cout << "sum: " <<sum<<"\n";
    cout << "sums: " <<sums<<"\n";
    cout << "sumscount: " <<sumscount <<"\n";

    vector<int> arrs(sumscount);     // sums의 자릿수 만큼의 크기를 가지는 arrs 각 index마다 해당 index 자릿수를 갖음.
    vector<int> count(10);  // 기본값 0으로 초기화 된 10개의 원소를 가는 count

    cout << "arrs.length: " <<arrs.size() <<"\n";
    cout << "count.length: " <<count.size() <<"\n";

    i = 0;  // 반목문 실행전, i값 초기화
    // for(i<sumscount; i++){      // arrs의 자릿수만큼 반복하며 해당 자릴수 값을 넣어줌.
    // for문으로 실행할 수도 있으나, 코드가 안예쁨.
    while(true) {
        arrs[i] = (sum % 10);       // 현재 sum값의 일의자릿 수 삽입

        if (sum == 10) {    // 만약 이전 반복문에서 계산된 sum/10 값이 정확히 10이 나왔을 경우, 
            sum = 0;    // sum을 10으로 나눈 값인 0을 할당해준 뒤 한번더 반복문을 돌려줌.
            continue;
        } 
        if(sum/10 ==0) break;   // 위의 경우를 제외하고 sum/10을 한 값이 0이 됐을 경우, 반복문 종료, 

        sum /= 10;
        i++;
    }

    for (int t=0; t <=count.size(); t++)        // range: 0~ count.size => 9
    {
        for (int i= 0; i<sumscount; i++)    // range: 0 ~ number of arrs.length=> 8
        {
            if (arrs[i] == t)
                count[t]++;     // t번째 , count,  +1 증가
        }
    }
    for(int i=0; i<count.size(); i++){
        cout <<"count[" << i << "] => "<< count[i]<< "\n";
    }
    for(int t=0; t<sumscount; t++){
        cout <<"arrs[" << t << "] => "<< arrs[t]<< "\n";
    }
/*
    for (int i = 0; i <=10; i++)
    { // cout 함수 출력
        cout << count[i] << "\n";
    }
*/
    return 0;
}
