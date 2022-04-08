#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double max=0, average = 0;
    int length;
    cin >> length;

    // 받아온 점수를 저장할 배열, 크기는 length만큼 설정
    vector<int> scoreArray(length);

    // 받아온 길이만큼 점수를 받아옴.
    for(int i=0; i<length; i++)
    {
        int score;
        cin>>score;
        // scoreArray에 받아온 점수값을 저장해줌.
        scoreArray[i] = score;
    }
    

    // 최댓값 식별
    for(int i=0; i<length; i++) if(scoreArray[i] > max) max = scoreArray[i];

    // 길이만큼 더해줄거임.
    for(int i=0; i<length; i++)
    {
        // 저장된 점수값이 최댓값 이라면, 그대로 더해줌.
        //if(scoreArray[i] == max) average+=max;
        // 최댓값이 아니라면 조작해서 더해줌. 인줄 알았는ㄴ데, 그냥 상관없이 더해주는거더라..
        average += scoreArray[i]/max*100; 
    }

    // 조작된 평균값 출력
    cout << average/length;

   return 0;
}
