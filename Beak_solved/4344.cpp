#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    cout << fixed; 
    cout.precision(3);
    int input;
    cin >> input; 

    vector<double> scoreArray(input);   // 입력 점수 저장
    vector<double> scoreAverages(input);
    vector<double> PersonRate(input);
    vector<string> finalReult(input);

    for(int i=0; i< input; i++){
        double testNumbers;
        cin >> testNumbers;

        vector<double> scorePerson(testNumbers);
        double score=0, averages = 0;
        for(int t=0; t<testNumbers; t++){
            cin >> score; 
            scorePerson[t] = score;
            averages +=score;
        }

        scoreAverages[i] = averages/testNumbers;

        
        for(int t=0; t<testNumbers; t++){ if(scoreAverages[i] < scorePerson[t]) PersonRate[i]++; }

        double result;
        result = PersonRate[i]/testNumbers*100.000;

        cout << result << "%" << "\n";
    }


    return 0;
}
